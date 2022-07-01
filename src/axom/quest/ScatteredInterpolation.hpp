// Copyright (c) 2017-2022, Lawrence Livermore National Security, LLC and
// other Axom Project Developers. See the top-level LICENSE file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)

#ifndef QUEST_SCATTERED_INTERPOLATION_H_
#define QUEST_SCATTERED_INTERPOLATION_H_

#include "axom/core.hpp"
#include "axom/slic.hpp"
#include "axom/sidre.hpp"
#include "axom/primal.hpp"
#include "axom/mint.hpp"

#include "axom/fmt.hpp"

#include "conduit.hpp"
#include "conduit_blueprint.hpp"

#include <cmath>
#include <limits>

namespace
{
/// Helper function to extract the dimension from the coordinate values group
/// of a mesh blueprint coordset
inline int extractDimension(const conduit::Node& values_node)
{
  SLIC_ASSERT(values_node.has_child("x"));
  return values_node.has_child("z") ? 3 : (values_node.has_child("y") ? 2 : 1);
}

/// Helper function to extract the number of points from the coordinate values group
/// of a mesh blueprint coordset
inline int extractSize(const conduit::Node& values_node)
{
  SLIC_ASSERT(values_node.has_child("x"));
  return values_node["x"].dtype().number_of_elements();
}

/**
 * \brief Utility function to create an axom::ArrayView over the array
 * of native types stored by a conduit::Node
 */
template <typename T>
inline axom::ArrayView<T> ArrayView_from_Node(conduit::Node& node, int sz)
{
  T* ptr = node.value();
  return axom::ArrayView<T>(ptr, sz);
}

/**
 * \brief Template specialization of ArrayView_from_Node for Point<double,2>
 *
 * \warning Assumes the underlying data is an MCArray with stride 2 access
 */
template <>
inline axom::ArrayView<axom::primal::Point<double, 2>> ArrayView_from_Node(
  conduit::Node& node,
  int sz)
{
  using PointType = axom::primal::Point<double, 2>;

  PointType* ptr = static_cast<PointType*>(node.data_ptr());
  return axom::ArrayView<PointType>(ptr, sz);
}

/**
 * \brief Template specialization of ArrayView_from_Node for Point<double,3>
 *
 * \warning Assumes the underlying data is an MCArray with stride 3 access
 */
template <>
inline axom::ArrayView<axom::primal::Point<double, 3>> ArrayView_from_Node(
  conduit::Node& node,
  int sz)
{
  using PointType = axom::primal::Point<double, 3>;

  PointType* ptr = static_cast<PointType*>(node.data_ptr());
  return axom::ArrayView<PointType>(ptr, sz);
}

/**
 * \brief Returns an ArrayView to the desired field from a mesh blueprint, which must be present
 *
 * \param [in] mesh_node The root conduit node of a valid mesh blueprint
 * \param [in] field_name The name of the field to return; Can either be either the name of the field,
 *  or the path to the field, e.g. fields/<field_name>/values
 *
 * \pre The field named \a field_name must be present in \a mesh_node or code will error out
 * \note Only currently supports scalar fields
 */
template <typename T>
inline axom::ArrayView<T> getField(conduit::Node& mesh_node,
                                   const std::string& field_name)
{
  using axom::utilities::string::startsWith;

  const std::string field_path = startsWith(field_name, "field")
    ? field_name
    : axom::fmt::format("fields/{}/values", field_name);
  SLIC_ERROR_IF(
    !mesh_node.has_path(field_path),
    axom::fmt::format("Mesh blueprint is missing required field '{}'",
                      field_name));

  auto& values = mesh_node[field_path];
  const auto sz = values.dtype().number_of_elements();

  return ::ArrayView_from_Node<T>(values, sz);
}

/// Check validity of blueprint group
inline bool isValidBlueprint(const conduit::Node& mesh_node)
{
  bool success = true;
  conduit::Node info;
  if(!conduit::blueprint::verify("mesh", mesh_node, info))
  {
    SLIC_INFO("Invalid blueprint for particle mesh: \n" << info.to_yaml());
    success = false;
  }

  return success;
}

}  // namespace

namespace axom
{
namespace quest
{
namespace detail
{
/**
 * \brief Utility class to enable processing an array of points whose layout
 * is either interleaved or separated strided arrays
 */
template <int NDIMS>
struct InterleavedOrStridedPoints
{
public:
  using PointType = axom::primal::Point<double, NDIMS>;
  using StridedPoints = axom::primal::detail::ZipBase<PointType>;
  using InterleavedPoints = axom::ArrayView<PointType>;

  /// Constructor from a multi-component array Conduit node
  explicit InterleavedOrStridedPoints(conduit::Node& values)
  {
    SLIC_ASSERT(isMultiComponentArray(values));

    m_is_interleaved = conduit::blueprint::mcarray::is_interleaved(values);

    m_npts = ::extractSize(values);

    if(m_is_interleaved)
    {
      m_interleaved = ::ArrayView_from_Node<PointType>(values["x"], m_npts);
    }
    else
    {
      const int dim = ::extractDimension(values);
      SLIC_ASSERT(dim == NDIMS);

      m_strided = StridedPoints {
        {static_cast<double*>(values["x"].data_ptr()),
         dim >= 2 ? static_cast<double*>(values["y"].data_ptr()) : nullptr,
         dim >= 3 ? static_cast<double*>(values["z"].data_ptr()) : nullptr}};
    }
  }

  /// Constructor from a multi-component array Sidre group node
  explicit InterleavedOrStridedPoints(const sidre::Group* values)
  {
    conduit::Node vals;
    SLIC_ASSERT(values != nullptr);
    values->createNativeLayout(vals);

    SLIC_ASSERT(isMultiComponentArray(vals));
    m_is_interleaved = conduit::blueprint::mcarray::is_interleaved(vals);
    m_npts = ::extractSize(vals);

    if(m_is_interleaved)
    {
      m_interleaved = ::ArrayView_from_Node<PointType>(vals["x"], m_npts);
    }
    else
    {
      const int dim = ::extractDimension(vals);
      SLIC_ASSERT(dim == NDIMS);

      m_strided = StridedPoints {
        {static_cast<double*>(vals["x"].data_ptr()),
         dim >= 2 ? static_cast<double*>(vals["y"].data_ptr()) : nullptr,
         dim >= 3 ? static_cast<double*>(vals["z"].data_ptr()) : nullptr}};
    }
  }

  /// Returns the number of points in the array
  int size() const { return m_npts; }

  /// Access the point at index \a idx in the array
  PointType operator[](int idx) const
  {
    return m_is_interleaved ? m_interleaved[idx] : m_strided[idx];
  }

private:
  /// Predicate to check that a Conduit node is a valid mcarray
  /// and print some debug information if it is not
  bool isMultiComponentArray(conduit::Node& node) const
  {
    conduit::Node info;
    if(!conduit::blueprint::verify("mcarray", node, info))
    {
      SLIC_INFO("Input was not a valid multicomponent array: " << info.to_yaml());
      return false;
    }
    return true;
  }

private:
  StridedPoints m_strided;
  InterleavedPoints m_interleaved;
  bool m_is_interleaved;
  int m_npts;
};

}  // namespace detail

/**
 * \brief A class to perform scattered data interpolation at arbitrary points
 * over an input point set
 *
 * The class uses linear interpolation over a Delaunay triangulation of the point set.
 */
template <int NDIMS = 3>
class ScatteredInterpolation
{
public:
  static constexpr int DIM = NDIMS;
  using DelaunayTriangulation = Delaunay<DIM>;
  using PointType = typename DelaunayTriangulation::PointType;
  using BoundingBoxType = typename DelaunayTriangulation::BoundingBox;

  /**
   * \brief Builds a Delaunay triangulation over the point set from \a mesh_node
   *
   * \param [in] mesh_node Conduit node for the input mesh
   * \param [in] coordset The name of the coordinate set for the input mesh
   */
  void buildTriangulation(conduit::Node& mesh_node, const std::string& coordset)
  {
    // Perform some simple error checking
    SLIC_ASSERT(::isValidBlueprint(mesh_node));

    // Extract coordinates as ArrayView of PointType
    const auto valuesPath = fmt::format("coordsets/{}/values", coordset);
    SLIC_ASSERT(mesh_node.has_path(valuesPath));
    auto coords = detail::InterleavedOrStridedPoints<DIM>(mesh_node[valuesPath]);
    const int npts = coords.size();

    // Compute the bounding box
    BoundingBoxType bb;
    for(int i = 0; i < npts; ++i)
    {
      bb.addPoint(coords[i]);
    }
    // Scale the bounding box to ensure that all input points are contained
    bb.scale(1.5);

    m_delaunay.initializeBoundary(bb);
    for(int i = 0; i < npts; ++i)
    {
      m_delaunay.insertPoint(coords[i]);
    }

    m_delaunay.removeBoundary();
  }

  /**
   * \brief Locates cell from Delaunay complex containing each point in \a query_mesh
   *
   * \param [inout] query_node Conduit node for the query points in mesh Blueprint format;
   * results will be placed into the `cell_idx` field
   * \param [in] coordset The name of the coordinate set for the query mesh
   *
   * \pre query_mesh is the root of a valid mesh blueprint with an unstructured
   * coordinate set \a coordset and a scalar field named `cell_idx` to store the results
   * \note Uses `Delaunay::INVALID_INDEX` for points that cannot be located within the mesh
   */
  void locatePoints(conduit::Node& query_mesh, const std::string& coordset)
  {
    // Perform some simple error checking
    SLIC_ASSERT(::isValidBlueprint(query_mesh));

    const auto valuesPath = fmt::format("coordsets/{}/values", coordset);
    SLIC_ASSERT(query_mesh.has_path(valuesPath));
    auto coords = detail::InterleavedOrStridedPoints<DIM>(query_mesh[valuesPath]);
    const int npts = coords.size();

    SLIC_ERROR_IF(!query_mesh.has_path("fields/cell_idx/values"),
                  "Query mesh for ScatteredInterpolation::locatePoints() is "
                  "missing required 'cell_idx' field");

    auto cell_idx = ::ArrayView_from_Node<axom::IndexType>(
      query_mesh["fields/cell_idx/values"],
      npts);

    // we expect that some points will be outside the mesh
    constexpr bool warnOnInvalid = false;
    for(int idx = 0; idx < npts; ++idx)
    {
      cell_idx[idx] =
        m_delaunay.findContainingElement(coords[idx], warnOnInvalid);
    }
  }

  /**
   * \brief Interpolates a field from an \a input_mesh to one on a \a query_mesh
   *
   * \param [inout] query_mesh Root node of mesh (in blueprint format) containing field to generate
   * \param [in] coordset The name of the coords for query points in \a query_mesh
   * \param [in] input_mesh Root node of mesh (in blueprint format) containing the field to interpolate
   * \param [in] input_field_name Name of field on \a input_mesh
   * \param [in] output_field_name Name of field on \a query_mesh
   * \param [in] INVALID_VALUE Value to use for points that are not in the \a input_mesh
   *
   * \pre \a input_mesh and \a query_mesh must conform to the mesh blueprint schema for point meshes
   * \pre \a input_mesh must contain a nodal scalar field named \a input_field_name
   * \pre \a query_mesh must contain a nodal scalar field named \a output_field_name
   * \pre \a query_mesh must contain a nodal scalar field named \a cell_idx whose values
   * are the index of the cell from the Delaunay triangulation containing the query points.
   * These can be computed in the \a locatePoints() function
   * \post Scalar field \a output_field_name on \a query_mesh will contain the interpolated
   * values of \a input_field_name from \a input_mesh for all query points that have a valid
   * \a cell_idx to a cell in the \a input_mesh.
   */
  void interpolateField(
    conduit::Node& query_mesh,
    const std::string& coordset,
    conduit::Node& input_mesh,
    const std::string& input_field_name,
    const std::string& output_field_name,
    const double INVALID_VALUE = std::numeric_limits<double>::quiet_NaN())
  {
    constexpr auto INVALID_INDEX = DelaunayTriangulation::INVALID_INDEX;

    SLIC_ASSERT(::isValidBlueprint(query_mesh));
    SLIC_ASSERT(::isValidBlueprint(input_mesh));

    // Extract the required fields from the input and query meshes
    auto in_fld = ::getField<double>(input_mesh, input_field_name);
    auto out_fld = ::getField<double>(query_mesh, output_field_name);
    auto containing_cell = ::getField<axom::IndexType>(query_mesh, "cell_idx");

    const auto valuesPath = fmt::format("coordsets/{}/values", coordset);
    SLIC_ASSERT(query_mesh.has_path(valuesPath));
    auto coords = detail::InterleavedOrStridedPoints<DIM>(query_mesh[valuesPath]);

    // Interpolate field at query points
    const int npts = coords.size();
    for(int idx = 0; idx < npts; ++idx)
    {
      const auto cell_id = containing_cell[idx];
      if(cell_id == INVALID_INDEX)
      {
        out_fld[idx] = INVALID_VALUE;
      }
      else
      {
        double res = 0.;
        const auto baryCoords = m_delaunay.getBaryCoords(cell_id, coords[idx]);
        const auto verts = m_delaunay.getMeshData()->boundaryVertices(cell_id);
        for(auto it = verts.begin(); it < verts.end(); ++it)
        {
          res += in_fld[*it] * baryCoords[it.index()];
        }

        out_fld[idx] = res;
      }
    }
  }

  /**
   * \brief Exports the Delaunay complex with scalar fields as a vtk file
   * 
   * \param [in] mesh_node Conduit node for the input mesh
   * \param [in] filename The name of the output file
   * 
   * \note Currently only includes scalar fields of type float64
   */
  void exportDelaunayComplex(conduit::Node& mesh_node, std::string&& filename) const
  {
    const auto CELL_TYPE = DIM == 2 ? mint::TRIANGLE : mint::TET;
    mint::UnstructuredMesh<mint::SINGLE_SHAPE> mint_mesh(DIM, CELL_TYPE);

    const auto* iaMesh = m_delaunay.getMeshData();

    // Add the mesh vertices
    for(auto v : iaMesh->vertices().positions())
    {
      mint_mesh.appendNodes(iaMesh->getVertexPosition(v).data(), 1);
    }

    // Add the mesh cells
    for(auto e : iaMesh->elements().positions())
    {
      mint_mesh.appendCell(&(iaMesh->boundaryVertices(e)[0]), CELL_TYPE);
    }

    // Add each of the scalar fields from mesh_node to the Delaunay complex
    // Note: Currently only adds fields that have type float64
    const int num_verts = iaMesh->vertices().size();
    auto itr = mesh_node["fields"].children();
    while(itr.has_next())
    {
      auto& node = itr.next();
      const auto& fieldName = node.name();

      if(node.has_child("values") &&
         node["values"].dtype().number_of_elements() == num_verts)
      {
        SLIC_DEBUG(fmt::format(
          "Processing field '{}' of type '{}' for Delaunay vtk file",
          fieldName,
          conduit::DataType::id_to_name(node["values"].dtype().id())));

        if(node["values"].dtype().is_float64())
        {
          double* vals = node["values"].as_float64_ptr();
          mint_mesh.createField(fieldName, mint::NODE_CENTERED, vals);
        }
      }
    }

    mint::write_vtk(&mint_mesh, filename);
  }

  /// TODO: Add a function that takes x,y,z coordinates
  /// and returns the vertex indices and the barycentric coords
  /// of the point w.r.t. its containing element

private:
  DelaunayTriangulation m_delaunay;
};

template <int NDIMS>
constexpr int ScatteredInterpolation<NDIMS>::DIM;

}  // namespace quest
}  // namespace axom

#endif  // QUEST_SCATTERED_INTERPOLATION_H_
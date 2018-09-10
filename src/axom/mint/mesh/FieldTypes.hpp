/*
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Copyright (c) 2017-2018, Lawrence Livermore National Security, LLC.
 *
 * Produced at the Lawrence Livermore National Laboratory
 *
 * LLNL-CODE-741217
 *
 * All rights reserved.
 *
 * This file is part of Axom.
 *
 * For details about use and distribution, please read axom/LICENSE.
 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

#ifndef MINT_FIELDTYPES_HPP_
#define MINT_FIELDTYPES_HPP_

#include "axom/core/Types.hpp" // for axom type definitions

namespace axom
{
namespace mint
{

/*!
 * \brief Enumerates the set of allowable field types.
 */
enum FieldType
{
  UNDEFINED_FIELD_TYPE =-1, //!< UNDEFINED_FIELD_TYPE

  FLOAT_FIELD_TYPE,         //!< single-precision floating point field type
  DOUBLE_FIELD_TYPE,        //!< double-precision floating point field type
  INT32_FIELD_TYPE,         //!< fixed width 32-bit integer field type
  INT64_FIELD_TYPE,         //!< fixed width 64-bit integer field type

  NUMBER_OF_FIELD_TYPES     //!< NUMBER_OF_FIELD_TYPES
};

/*!
 * \brief Field traits struct to map a C++ primitive type to a FieldType
 */
template < typename FieldType >
struct field_traits
{
  static constexpr int type() { return UNDEFINED_FIELD_TYPE; };
};

/// \name Specialization of field_traits
/// @{

//------------------------------------------------------------------------------
template < >
struct field_traits< float >
{
  static constexpr int type() { return FLOAT_FIELD_TYPE; };
};

//------------------------------------------------------------------------------
template < >
struct field_traits< double >
{
  static constexpr int type() { return DOUBLE_FIELD_TYPE; };
};

//------------------------------------------------------------------------------
template < >
struct field_traits< common::int32 >
{
  static constexpr int type() { return INT32_FIELD_TYPE; };
};

//------------------------------------------------------------------------------
template < >
struct field_traits< common::int64 >
{
  static constexpr int type() { return INT64_FIELD_TYPE; };
};

/// @}

} /* namespace mint */
} /* namespace axom */

#endif /* MINT_FIELDTYPES_HPP_ */
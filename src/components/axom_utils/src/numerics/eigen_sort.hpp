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

#ifndef AXOM_EIGEN_SORT_HPP_
#define AXOM_EIGEN_SORT_HPP_

// Axom includes
#include "axom/Types.hpp"           // for AXOM_NULLPTR
#include "axom_utils/Utilities.hpp" // for utilities::swap()

namespace axom
{
namespace numerics
{

/*!
 * \brief Sorts the supplied eigenvalues and eigenvectors in ascending order.
 *
 * \param [in,out] lambdas pointer to buffer consisting of the eigenvalues
 * \param [in,out] eigen_vectors matrix of the corresponding eigenvectors
 *
 * \note The eigen_vectors matrix is an orthogonal matrix consisting of the
 *  eigenvectors. Each column in the matrix stores an eigenvector that
 *  is associated with the an eigenvalue in the corresponding entry in the
 *  supplied lambdas array.
 *
 * \note lambdas should point to a buffer that holds eigen_vectors.getNumCols()
 *
 * \note The sorting algorithm in the current implementation is O(\f$ N^2 \f$)
 *  rather than O( \f$ NlogN \f$ )
 *
 * \pre lambdas != AXOM_NULLPTR
 * \pre eigen_vectors.getNumRows() >= 1
 * \pre eigen_vectors.getNumCols() >= 1
 */
template < typename T >
bool eigen_sort( T* lamdas, Matrix< T >& eigen_vectors );

//------------------------------------------------------------------------------
// IMPLEMENTATION
//------------------------------------------------------------------------------
template < typename T >
bool eigen_sort( T* lambdas, Matrix< T >& eigen_vectors )
{
  if ( lambdas==AXOM_NULLPTR ||
       eigen_vectors.getNumRows() < 1 ||
       eigen_vectors.getNumColumns() < 1 )
  {
    return false;
  }

  const int n = eigen_vectors.getNumColumns();

  for (int i = 0 ; i < n-1 ; ++i)
  {
    int m = i;

    for (int j = i+1 ; j < n ; ++j)
    {
      if ( lambdas[ j ] < lambdas[ m ] )
      {
        m = j;
      }
    } // END for j

    if (m != i)
    {
      utilities::swap( lambdas[ m ], lambdas[ i ] );
      eigen_vectors.swapColumns( m,i );
    } // END if swap

  } // END for i

  return true;
}

} /* end namespace numerics */
} /* end namespace axom */

#endif /* AXOM_EIGEN_SORT_HPP_ */
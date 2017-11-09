/*
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Copyright (c) 2017, Lawrence Livermore National Security, LLC.
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

#include "PSTLReader.hpp"

#include "axom/Types.hpp"
#include "slic/slic.hpp"

namespace axom
{
namespace quest
{

//------------------------------------------------------------------------------
PSTLReader::PSTLReader( MPI_Comm comm ) : m_comm( comm )
{
  MPI_Comm_rank( m_comm, &m_my_rank );
}

//------------------------------------------------------------------------------
PSTLReader::~PSTLReader()
{
  // TODO Auto-generated destructor stub
}

//------------------------------------------------------------------------------
void PSTLReader::read()
{
  SLIC_ASSERT( m_fileName != "" );
  SLIC_ASSERT( m_comm != MPI_COMM_NULL );

  // Clear internal data-structures
  this->clear();

  if( m_my_rank == 0)
  {
    // Rank 0 reads the mesh and broadcasts vertex positions to the others
    STLReader::read();

    MPI_Bcast( &m_num_nodes, 1, MPI_INT, 0, m_comm );
    MPI_Bcast( &m_nodes[0], m_num_nodes * 3, MPI_DOUBLE, 0, m_comm);
  }
  else
  {
    // Other ranks receive the mesh vertices from rank 0
    MPI_Bcast( &m_num_nodes, 1, MPI_INT, 0, m_comm );
    m_nodes.resize( m_num_nodes * 3);
    MPI_Bcast( &m_nodes[0], m_num_nodes * 3, MPI_DOUBLE, 0, m_comm);

    m_num_faces = m_num_nodes / 3;
  }

  MPI_Barrier( MPI_COMM_WORLD );
}

} // end namespace quest
} // end namespace axom

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

/*!
 * \file
 *
 * \brief Illustrates how to construct and use a ParticleMesh to perform
 *  operations on a set of particles.
 */

// Axom utilities
#include "axom_utils/Utilities.hpp" // for random_real()

// Mint includes
#include "mint/config.hpp"
#include "mint/ParticleMesh.hpp"
#include "mint/vtk_utils.hpp"

// namespace aliases
namespace mint      = axom::mint;
namespace utilities = axom::utilities;


//------------------------------------------------------------------------------
int main( int AXOM_NOT_USED(argc), char** AXOM_NOT_USED(argv) )
{
  using int64 = mint::IndexType;
  const mint::IndexType NUM_PARTICLES = 100;
  const int DIMENSION = 3;

  const double HI  = 10.0;
  const double LO  = -10.0;
  const double VLO = 0.0;
  const double VHI = 1.0;

  // STEP 0: create the ParticleMesh
  mint::ParticleMesh particles( DIMENSION, NUM_PARTICLES );

  // STEP 1: Add fields to the Particles
  double* vx = particles.createField< double >( "vx", mint::NODE_CENTERED );
  double* vy = particles.createField< double >( "vy", mint::NODE_CENTERED );
  double* vz = particles.createField< double >( "vz", mint::NODE_CENTERED );
  int64* id  = particles.createField< int64 >( "id", mint::NODE_CENTERED );

  // STEP 2: grab handle to the particle position arrays
  double* px = particles.getCoordinateArray( mint::X_COORDINATE );
  double* py = particles.getCoordinateArray( mint::Y_COORDINATE );
  double* pz = particles.getCoordinateArray( mint::Z_COORDINATE );

  // STEP 3: loop over the particle data
  const int64 numParticles = particles.getNumberOfNodes();
  for ( int64 i=0 ; i < numParticles ; ++i )
  {

    px[ i ] = utilities::random_real( LO, HI );
    py[ i ] = utilities::random_real( LO, HI );
    pz[ i ] = utilities::random_real( LO, HI );

    vx[ i ] = utilities::random_real( VLO, VHI );
    vy[ i ] = utilities::random_real( VLO, VHI );
    vz[ i ] = utilities::random_real( VLO, VHI );

    id[ i ] = i;

  } // END

  // STEP 4: write the particle mesh in VTK format for visualization
  mint::write_vtk( &particles, "particles.vtk" );

  return 0;
}
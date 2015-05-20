/*
 * Copyright (c) 2015, Lawrence Livermore National Security, LLC.
 * Produced at the Lawrence Livermore National Laboratory.
 *
 * All rights reserved.
 *
 * This source code cannot be distributed without permission and further
 * review from Lawrence Livermore National Laboratory.
 */

/*!
 *******************************************************************************
 * \file SeperateFilePerRankStream.cpp
 *
 * \date May 8, 2015
 * \author George Zagaris (zagaris2@llnl.gov)
 *
 *******************************************************************************
 */

#include "SeperateFilePerRankStream.hpp"

#include <cassert>
#include <fstream>
#include <sstream>

namespace asctoolkit {
namespace logapi {

struct SeperateFilePerRankStream::FileStream
{
  FileStream( const std::string& prefix, MPI_Comm c )
  {
    int rank = -1;
    MPI_Comm_rank( c, &rank );

    std::ostringstream oss;
    oss << prefix << "_" << rank << ".dat";

    this->ofs.open( oss.str().c_str() );
  }

  ~FileStream()
   {
    this->ofs.close();
   }

  std::ofstream ofs;
};

//------------------------------------------------------------------------------
SeperateFilePerRankStream::SeperateFilePerRankStream(
              const std::string& prefix, MPI_Comm c ):
    m_comm( c ),
    m_fstream( new FileStream(prefix,c) )
{

}

//------------------------------------------------------------------------------
SeperateFilePerRankStream::~SeperateFilePerRankStream()
{
  if ( m_fstream != NULL ) {
    delete m_fstream;
    m_fstream = NULL;
  }
}

//------------------------------------------------------------------------------
void SeperateFilePerRankStream::append( message::Level msgLevel,
                                      const std::string& message,
                                      const std::string& tagName,
                                      const std::string& fileName,
                                      int line )
{
  assert( "pre: null file stream" && (m_fstream != NULL) );
  assert( "pre: file stream is not open!" && m_fstream->ofs.is_open() );
  m_fstream->ofs << this->getFormatedMessage(
      message::getLevelAsString( msgLevel ),message,tagName,fileName,line);
}

} /* namespace logapi */

} /* namespace asctoolkit */

// wrapGenericOutputStream.cpp
// This file is generated by Shroud 0.12.2. Do not edit.
//
// Copyright (c) 2017-2022, Lawrence Livermore National Security, LLC and
// other Axom Project Developers. See the top-level LICENSE file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
#include "wrapGenericOutputStream.h"
#include <cstddef>
#include <string>
#include "axom/slic/streams/GenericOutputStream.hpp"

// splicer begin class.GenericOutputStream.CXX_definitions
// splicer end class.GenericOutputStream.CXX_definitions

extern "C" {

// splicer begin class.GenericOutputStream.C_definitions
// splicer end class.GenericOutputStream.C_definitions

SLIC_GenericOutputStream *SLIC_GenericOutputStream_ctor_default(
  const char *stream,
  SLIC_GenericOutputStream *SHC_rv)
{
  // splicer begin class.GenericOutputStream.method.ctor_default
  const std::string SHCXX_stream(stream);
  axom::slic::GenericOutputStream *SHCXX_rv =
    new axom::slic::GenericOutputStream(SHCXX_stream);
  SHC_rv->addr = static_cast<void *>(SHCXX_rv);
  SHC_rv->idtor = 1;
  return SHC_rv;
  // splicer end class.GenericOutputStream.method.ctor_default
}

SLIC_GenericOutputStream *SLIC_GenericOutputStream_ctor_default_bufferify(
  const char *stream,
  int Lstream,
  SLIC_GenericOutputStream *SHC_rv)
{
  // splicer begin class.GenericOutputStream.method.ctor_default_bufferify
  const std::string SHCXX_stream(stream, Lstream);
  axom::slic::GenericOutputStream *SHCXX_rv =
    new axom::slic::GenericOutputStream(SHCXX_stream);
  SHC_rv->addr = static_cast<void *>(SHCXX_rv);
  SHC_rv->idtor = 1;
  return SHC_rv;
  // splicer end class.GenericOutputStream.method.ctor_default_bufferify
}

SLIC_GenericOutputStream *SLIC_GenericOutputStream_ctor_format(
  const char *stream,
  const char *format,
  SLIC_GenericOutputStream *SHC_rv)
{
  // splicer begin class.GenericOutputStream.method.ctor_format
  const std::string SHCXX_stream(stream);
  const std::string SHCXX_format(format);
  axom::slic::GenericOutputStream *SHCXX_rv =
    new axom::slic::GenericOutputStream(SHCXX_stream, SHCXX_format);
  SHC_rv->addr = static_cast<void *>(SHCXX_rv);
  SHC_rv->idtor = 1;
  return SHC_rv;
  // splicer end class.GenericOutputStream.method.ctor_format
}

SLIC_GenericOutputStream *SLIC_GenericOutputStream_ctor_format_bufferify(
  const char *stream,
  int Lstream,
  const char *format,
  int Lformat,
  SLIC_GenericOutputStream *SHC_rv)
{
  // splicer begin class.GenericOutputStream.method.ctor_format_bufferify
  const std::string SHCXX_stream(stream, Lstream);
  const std::string SHCXX_format(format, Lformat);
  axom::slic::GenericOutputStream *SHCXX_rv =
    new axom::slic::GenericOutputStream(SHCXX_stream, SHCXX_format);
  SHC_rv->addr = static_cast<void *>(SHCXX_rv);
  SHC_rv->idtor = 1;
  return SHC_rv;
  // splicer end class.GenericOutputStream.method.ctor_format_bufferify
}

void SLIC_GenericOutputStream_delete(SLIC_GenericOutputStream *self)
{
  axom::slic::GenericOutputStream *SH_this =
    static_cast<axom::slic::GenericOutputStream *>(self->addr);
  // splicer begin class.GenericOutputStream.method.delete
  delete SH_this;
  self->addr = nullptr;
  // splicer end class.GenericOutputStream.method.delete
}

}  // extern "C"

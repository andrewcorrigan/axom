// wrapDataStore.cpp
// This file is generated by Shroud 0.12.2. Do not edit.
//
// Copyright (c) 2017-2021, Lawrence Livermore National Security, LLC and
// other Axom Project Developers. See the top-level LICENSE file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
#include "wrapDataStore.h"
#include <cstddef>
#include <string>
#include "axom/sidre/core/Buffer.hpp"
#include "axom/sidre/core/DataStore.hpp"
#include "axom/sidre/core/Group.hpp"
#include "axom/sidre/interface/SidreTypes.h"

// splicer begin class.DataStore.CXX_definitions
// splicer end class.DataStore.CXX_definitions

extern "C" {

// splicer begin class.DataStore.C_definitions
// splicer end class.DataStore.C_definitions

SIDRE_DataStore* SIDRE_DataStore_new(SIDRE_DataStore* SHC_rv)
{
  // splicer begin class.DataStore.method.new
  axom::sidre::DataStore* SHCXX_rv = new axom::sidre::DataStore();
  SHC_rv->addr = static_cast<void*>(SHCXX_rv);
  SHC_rv->idtor = 1;
  return SHC_rv;
  // splicer end class.DataStore.method.new
}

void SIDRE_DataStore_delete(SIDRE_DataStore* self)
{
  axom::sidre::DataStore* SH_this =
    static_cast<axom::sidre::DataStore*>(self->addr);
  // splicer begin class.DataStore.method.delete
  delete SH_this;
  self->addr = nullptr;
  // splicer end class.DataStore.method.delete
}

SIDRE_Group* SIDRE_DataStore_get_root(SIDRE_DataStore* self, SIDRE_Group* SHC_rv)
{
  axom::sidre::DataStore* SH_this =
    static_cast<axom::sidre::DataStore*>(self->addr);
  // splicer begin class.DataStore.method.get_root
  axom::sidre::Group* SHCXX_rv = SH_this->getRoot();
  SHC_rv->addr = SHCXX_rv;
  SHC_rv->idtor = 0;
  return SHC_rv;
  // splicer end class.DataStore.method.get_root
}

size_t SIDRE_DataStore_get_num_buffers(const SIDRE_DataStore* self)
{
  const axom::sidre::DataStore* SH_this =
    static_cast<const axom::sidre::DataStore*>(self->addr);
  // splicer begin class.DataStore.method.get_num_buffers
  size_t SHC_rv = SH_this->getNumBuffers();
  return SHC_rv;
  // splicer end class.DataStore.method.get_num_buffers
}

SIDRE_Buffer* SIDRE_DataStore_get_buffer(SIDRE_DataStore* self,
                                         SIDRE_IndexType idx,
                                         SIDRE_Buffer* SHC_rv)
{
  axom::sidre::DataStore* SH_this =
    static_cast<axom::sidre::DataStore*>(self->addr);
  // splicer begin class.DataStore.method.get_buffer
  axom::sidre::Buffer* SHCXX_rv = SH_this->getBuffer(idx);
  // C_error_pattern
  if(SHCXX_rv == nullptr)
  {
    SHC_rv->addr = NULL;
    SHC_rv->idtor = 0;
    return NULL;
  }

  SHC_rv->addr = SHCXX_rv;
  SHC_rv->idtor = 0;
  return SHC_rv;
  // splicer end class.DataStore.method.get_buffer
}

SIDRE_Buffer* SIDRE_DataStore_create_buffer_empty(SIDRE_DataStore* self,
                                                  SIDRE_Buffer* SHC_rv)
{
  axom::sidre::DataStore* SH_this =
    static_cast<axom::sidre::DataStore*>(self->addr);
  // splicer begin class.DataStore.method.create_buffer_empty
  axom::sidre::Buffer* SHCXX_rv = SH_this->createBuffer();
  SHC_rv->addr = SHCXX_rv;
  SHC_rv->idtor = 0;
  return SHC_rv;
  // splicer end class.DataStore.method.create_buffer_empty
}

SIDRE_Buffer* SIDRE_DataStore_create_buffer_from_type(SIDRE_DataStore* self,
                                                      int type,
                                                      SIDRE_IndexType num_elems,
                                                      SIDRE_Buffer* SHC_rv)
{
  axom::sidre::DataStore* SH_this =
    static_cast<axom::sidre::DataStore*>(self->addr);
  // splicer begin class.DataStore.method.create_buffer_from_type
  axom::sidre::TypeID SHCXX_type = axom::sidre::getTypeID(type);
  axom::sidre::Buffer* SHCXX_rv = SH_this->createBuffer(SHCXX_type, num_elems);
  // C_error_pattern
  if(SHCXX_rv == nullptr)
  {
    SHC_rv->addr = NULL;
    SHC_rv->idtor = 0;
    return NULL;
  }

  SHC_rv->addr = SHCXX_rv;
  SHC_rv->idtor = 0;
  return SHC_rv;
  // splicer end class.DataStore.method.create_buffer_from_type
}

void SIDRE_DataStore_destroy_buffer(SIDRE_DataStore* self, SIDRE_IndexType id)
{
  axom::sidre::DataStore* SH_this =
    static_cast<axom::sidre::DataStore*>(self->addr);
  // splicer begin class.DataStore.method.destroy_buffer
  SH_this->destroyBuffer(id);
  // splicer end class.DataStore.method.destroy_buffer
}

bool SIDRE_DataStore_generate_blueprint_index(SIDRE_DataStore* self,
                                              const char* domain_path,
                                              const char* mesh_name,
                                              const char* index_path,
                                              int num_domains)
{
  axom::sidre::DataStore* SH_this =
    static_cast<axom::sidre::DataStore*>(self->addr);
  // splicer begin class.DataStore.method.generate_blueprint_index
  const std::string SHCXX_domain_path(domain_path);
  const std::string SHCXX_mesh_name(mesh_name);
  const std::string SHCXX_index_path(index_path);
  bool SHC_rv = SH_this->generateBlueprintIndex(SHCXX_domain_path,
                                                SHCXX_mesh_name,
                                                SHCXX_index_path,
                                                num_domains);
  return SHC_rv;
  // splicer end class.DataStore.method.generate_blueprint_index
}

bool SIDRE_DataStore_generate_blueprint_index_bufferify(SIDRE_DataStore* self,
                                                        const char* domain_path,
                                                        int Ldomain_path,
                                                        const char* mesh_name,
                                                        int Lmesh_name,
                                                        const char* index_path,
                                                        int Lindex_path,
                                                        int num_domains)
{
  axom::sidre::DataStore* SH_this =
    static_cast<axom::sidre::DataStore*>(self->addr);
  // splicer begin class.DataStore.method.generate_blueprint_index_bufferify
  const std::string SHCXX_domain_path(domain_path, Ldomain_path);
  const std::string SHCXX_mesh_name(mesh_name, Lmesh_name);
  const std::string SHCXX_index_path(index_path, Lindex_path);
  bool SHC_rv = SH_this->generateBlueprintIndex(SHCXX_domain_path,
                                                SHCXX_mesh_name,
                                                SHCXX_index_path,
                                                num_domains);
  return SHC_rv;
  // splicer end class.DataStore.method.generate_blueprint_index_bufferify
}

void SIDRE_DataStore_print(const SIDRE_DataStore* self)
{
  const axom::sidre::DataStore* SH_this =
    static_cast<const axom::sidre::DataStore*>(self->addr);
  // splicer begin class.DataStore.method.print
  SH_this->print();
  // splicer end class.DataStore.method.print
}

}  // extern "C"

#------------------------------------------------------------------------------
# !!!! This is a generated file, edit at own risk !!!!
#------------------------------------------------------------------------------
# Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
# other Axom Project Developers. See the top-level COPYRIGHT file for details.
#
# SPDX-License-Identifier: (BSD-3-Clause)
#------------------------------------------------------------------------------
# SYS_TYPE: blueos_3_ppc64le_ib
# Compiler Spec: xl@nvcc
#------------------------------------------------------------------------------
# CMake executable path: /usr/WS1/axom/devtools/blueos_3_ppc64le_ib/latest/cmake-3.9.6/bin/cmake
#------------------------------------------------------------------------------

#------------------------------------------------------------------------------
# Compilers
#------------------------------------------------------------------------------

set(CMAKE_C_COMPILER "/usr/tce/packages/xl/xl-2019.08.20/bin/xlc" CACHE PATH "")

set(CMAKE_CXX_COMPILER "/usr/tce/packages/xl/xl-2019.08.20/bin/xlC" CACHE PATH "")

set(ENABLE_FORTRAN ON CACHE BOOL "")

set(CMAKE_Fortran_COMPILER "/usr/tce/packages/xl/xl-2019.08.20/bin/xlf2003" CACHE PATH "")

#------------------------------------------------------------------------------
# TPLs
#------------------------------------------------------------------------------

# Root directory for generated TPLs
set(TPL_ROOT "/usr/WS1/axom/libs/blueos_3_ppc64le_ib/2020_04_02_19_22_50/xl-nvcc" CACHE PATH "")

set(CONDUIT_DIR "${TPL_ROOT}/conduit-0.5.1" CACHE PATH "")

set(MFEM_DIR "${TPL_ROOT}/mfem-4.0" CACHE PATH "")

set(HDF5_DIR "${TPL_ROOT}/hdf5-1.8.21" CACHE PATH "")

# SCR not built

set(RAJA_DIR "${TPL_ROOT}/raja-0.11.0" CACHE PATH "")

set(UMPIRE_DIR "${TPL_ROOT}/umpire-2.1.0" CACHE PATH "")

#------------------------------------------------------------------------------
# MPI
#------------------------------------------------------------------------------

set(ENABLE_MPI ON CACHE BOOL "")

set(MPI_C_COMPILER "/usr/tce/packages/spectrum-mpi/spectrum-mpi-rolling-release-xl-2019.08.20/bin/mpicc" CACHE PATH "")

set(MPI_CXX_COMPILER "/usr/tce/packages/spectrum-mpi/spectrum-mpi-rolling-release-xl-2019.08.20/bin/mpicxx" CACHE PATH "")

set(MPI_Fortran_COMPILER "/usr/tce/packages/spectrum-mpi/spectrum-mpi-rolling-release-xl-2019.08.20/bin/mpif90" CACHE PATH "")

set(MPIEXEC "/usr/tce/packages/spectrum-mpi/spectrum-mpi-rolling-release-xl-2019.08.20/bin/mpirun" CACHE PATH "")

set(MPIEXEC_NUMPROC_FLAG "-np" CACHE PATH "")

set(BLT_MPI_COMMAND_APPEND "mpibind" CACHE PATH "")

#------------------------------------------------------------------------------
# Devtools
#------------------------------------------------------------------------------

# Root directory for generated developer tools
set(DEVTOOLS_ROOT "/usr/WS1/axom/devtools/blueos_3_ppc64le_ib/2020_04_02_14_30_58/gcc-8.3.1" CACHE PATH "")

set(PYTHON_EXECUTABLE "${DEVTOOLS_ROOT}/python-3.7.4/bin/python" CACHE PATH "")

set(ENABLE_DOCS ON CACHE BOOL "")

set(DOXYGEN_EXECUTABLE "${DEVTOOLS_ROOT}/doxygen-1.8.14/bin/doxygen" CACHE PATH "")

set(SPHINX_EXECUTABLE "${DEVTOOLS_ROOT}/python-3.7.4/bin/sphinx-build" CACHE PATH "")

set(SHROUD_EXECUTABLE "${DEVTOOLS_ROOT}/python-3.7.4/bin/shroud" CACHE PATH "")

set(UNCRUSTIFY_EXECUTABLE "${DEVTOOLS_ROOT}/uncrustify-0.61/bin/uncrustify" CACHE PATH "")

set(CPPCHECK_EXECUTABLE "${DEVTOOLS_ROOT}/cppcheck-1.87/bin/cppcheck" CACHE PATH "")

#------------------------------------------------------------------------------
# Other machine specifics
#------------------------------------------------------------------------------

set(ENABLE_GTEST_DEATH_TESTS OFF CACHE BOOL "")

set(CMAKE_Fortran_COMPILER_ID "XL" CACHE PATH "All of BlueOS compilers report clang due to nvcc, override to proper compiler family")

set(CMAKE_C_COMPILER_ID "XL" CACHE PATH "All of BlueOS compilers report clang due to nvcc, override to proper compiler family")

set(CMAKE_CXX_COMPILER_ID "XL" CACHE PATH "All of BlueOS compilers report clang due to nvcc, override to proper compiler family")

set(BLT_FORTRAN_FLAGS "-WF,-C!  -qxlf2003=polymorphic" CACHE PATH "Converts C-style comments to Fortran style in preprocessed files")

set(BLT_EXE_LINKER_FLAGS "-Wl,-rpath,/usr/tce/packages/xl/xl-2019.08.20/lib" CACHE PATH "Adds a missing rpath for libraries associated with the fortran compiler")

#------------------------------------------------------------------------------
# Cuda
#------------------------------------------------------------------------------

set(ENABLE_CUDA ON CACHE BOOL "")

set(CUDA_TOOLKIT_ROOT_DIR "/usr/tce/packages/cuda/cuda-10.1.168" CACHE PATH "")

set(CMAKE_CUDA_COMPILER "${CUDA_TOOLKIT_ROOT_DIR}/bin/nvcc" CACHE PATH "")

set(CUDA_SEPARABLE_COMPILATION ON CACHE BOOL "")

set(AXOM_CUDA_ARCH "sm_60" CACHE PATH "")

set(CMAKE_CUDA_FLAGS "-restrict -arch ${AXOM_CUDA_ARCH} -std=c++11 --expt-extended-lambda -G" CACHE PATH "")

set(CMAKE_CUDA_HOST_COMPILER "${MPI_CXX_COMPILER}" CACHE PATH "")

# nvcc does not like gtest's 'pthreads' flag
set(gtest_disable_pthreads ON CACHE BOOL "")


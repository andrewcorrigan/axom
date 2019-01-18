/*
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Copyright (c) 2017-2019, Lawrence Livermore National Security, LLC.
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

#ifndef AXOM_PRIMAL_BVH_MATH_H_
#define AXOM_PRIMAL_BVH_MATH_H_

#include "axom/core/Macros.hpp"
#include "axom/core/Types.hpp"    // for fixed bitwidth types

// include math so we can use functions defined
// in both cuda and c
#include <math.h>

#define DRAY_INF_32 0x7f800000U
#define DRAY_NG_INF_32 0xff800000U

#define DRAY_INF_64 0x7ff0000000000000ULL
#define DRAY_NG_INF_64 0xfff0000000000000ULL

#define DRAY_NAN_32 0x7FC00000U
#define DRAY_NAN_64 0x7FF8000000000000ULL

#define DRAY_EPSILON_32 1e-5f
#define DRAY_EPSILON_64 1e-9f

#ifndef __CUDACC__
// make sure min / max resolve for both cuda and cpu
#include <math.h>
#include <string.h> //resolve memcpy
using namespace std;
#endif

namespace axom
{
namespace primal
{
namespace bvh
{
namespace detail
{

union Bits32
{
  axom::common::float32 scalar;
  axom::common::int32  bits;
};

union Bits64
{
  axom::common::float64 scalar;
  axom::common::int64  bits;
};

} /* namespace detail */

template<typename T>
inline AXOM_HOST_DEVICE
T epsilon()
{
  return 1;
}

template<>
inline AXOM_HOST_DEVICE
axom::common::float32 epsilon<axom::common::float32>()
{
  return DRAY_EPSILON_32;
}

template<>
inline AXOM_HOST_DEVICE
axom::common::float64 epsilon<axom::common::float64>()
{
  return DRAY_EPSILON_64;
}

inline AXOM_HOST_DEVICE
axom::common::float32 nan32()
{
  detail::Bits32 nan;
  nan.bits = DRAY_NAN_32;
  return nan.scalar;
}

inline AXOM_HOST_DEVICE
axom::common::float32 infinity32()
{
  detail::Bits32 inf;
  inf.bits = DRAY_INF_32;
  return inf.scalar;
}

inline AXOM_HOST_DEVICE
axom::common::float32 neg_infinity32()
{
  detail::Bits32 ninf;
  ninf.bits = DRAY_NG_INF_32;
  return ninf.scalar;
}

inline AXOM_HOST_DEVICE
axom::common::float64 nan64()
{
  detail::Bits64 nan;
  nan.bits = DRAY_NAN_64;
  return nan.scalar;
}

inline AXOM_HOST_DEVICE
axom::common::float64 infinity64()
{
  detail::Bits64 inf;
  inf.bits = DRAY_INF_64;
  return inf.scalar;
}

inline AXOM_HOST_DEVICE
axom::common::float64 neg_infinity64()
{
  detail::Bits64 ninf;
  ninf.bits = DRAY_NG_INF_64;
  return ninf.scalar;
}

template<typename T>
inline AXOM_HOST_DEVICE
T infinity();

template<>
inline AXOM_HOST_DEVICE
axom::common::float32 infinity<axom::common::float32>()
{
  return infinity32();
}

template<>
inline AXOM_HOST_DEVICE
axom::common::float64 infinity<axom::common::float64>()
{
  return infinity64();
}

//
// count leading zeros
//
inline AXOM_HOST_DEVICE
axom::common::int32 clz(axom::common::int32 x)
{
  axom::common::int32 y;
  axom::common::int32 n = 32;
  y = x >> 16;
  if (y != 0)
  {
    n = n - 16;
    x = y;
  }
  y = x >> 8;
  if (y != 0)
  {
    n = n - 8;
    x = y;
  }
  y = x >> 4;
  if (y != 0)
  {
    n = n - 4;
    x = y;
  }
  y = x >> 2;
  if (y != 0)
  {
    n = n - 2;
    x = y;
  }
  y = x >> 1;
  if (y != 0)
    return axom::common::int32(n - 2);
  return axom::common::int32(n - x);
}

inline AXOM_HOST_DEVICE
axom::common::float64 pi()
{
  return 3.14159265358979323846264338327950288;
}

inline AXOM_HOST_DEVICE
axom::common::float32 rcp(axom::common::float32 f)
{
  return 1.0f / f;
}

inline AXOM_HOST_DEVICE
axom::common::float64 rcp(axom::common::float64 f)
{
  return 1.0 / f;
}

inline AXOM_HOST_DEVICE
axom::common::float64 rcp_safe(axom::common::float64 f)
{
  return rcp((fabs(f) < 1e-8) ? 1e-8 : f);
}

inline AXOM_HOST_DEVICE
axom::common::float32 rcp_safe(axom::common::float32 f)
{
  return rcp((fabs(f) < 1e-8f) ? 1e-8f : f);
}

template<typename T>
inline AXOM_HOST_DEVICE
T clamp(const T &val, const T &min_val, const T &max_val)
{
  return min(max_val, max(min_val, val));
}

} /* namespace axom */
} /* namespace primal */
} /* namespace bvh */
#endif

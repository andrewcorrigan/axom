/*
 * Copyright (c) 2015, Lawrence Livermore National Security, LLC.
 * Produced at the Lawrence Livermore National Laboratory.
 *
 * All rights reserved.
 *
 * This source code cannot be distributed without permission and further
 * review from Lawrence Livermore National Laboratory.
 */


/**
 * \file NullSet.hpp
 *
 * \brief Sentinel set type indicating an empty set.
 *
 */

#ifndef SLAM_NULL_SET_H_
#define SLAM_NULL_SET_H_

#include "common/ATKMacros.hpp"

#include "slic/slic.hpp"
#include "slam/Set.hpp"

namespace asctoolkit {
namespace slam {


/**
 * \class NullSet
 *
 * \brief An indexed set (a tuple) of entities in a simulation
 */
  class NullSet : public Set
  {
  public:
    NullSet() {}

    inline PositionType         size() const { return PositionType(); }

    inline ElementType          at(PositionType pos) const { verifyPosition(pos); return PositionType(); }
    inline ElementType operator [](PositionType pos) const { return at(pos); }

    inline bool                 isSubset() const { return false; }
    const Set*                  parentSet() const { return this; }

    bool                        isValid(bool) const { return true; }

    bool                        empty() const { return true; }

    // TODO: Do we need to add iterator stubs here to satisfy some interface?
    //       The result will be invalid, but it may be useful to get the code to compile, or avoid special logic in the code...
    // iterator begin();
    // iterator end();
    // iterator_pair range();

  private:
    void verifyPosition(PositionType ATK_DEBUG_PARAM(pos)) const
    {
      SLIC_ASSERT_MSG(false,"Subscripting on NullSet is never valid."
          << "\n\tAttempted to access item at index " << pos << ".");
    }
  };


#if 0
/**
 * \brief NullSets are always equal
 * \note Two sets of different types are (currently) considered to be unequal
 */
  inline bool operator==(NullSet const&, NullSet const&) { ATK_WARNING("operator==(NullSet,NullSet)"); return true; }
/**
 * \brief NullSets are always equal
 * \note Two sets of different types are (currently) considered to be unequal
 */
  inline bool operator!=(NullSet const&, NullSet const&) { ATK_WARNING("operator!=(NullSet,NullSet)"); return false; }
#endif


} // end namespace slam
} // end namespace asctoolkit

#endif //  SLAM_SET_H_
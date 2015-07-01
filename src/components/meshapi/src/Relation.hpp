/**
 * \file Relation.h
 *
 * \brief Basic API for a topological relation between two sets
 *
 */

#ifndef MESHAPI_RELATION_HPP_
#define MESHAPI_RELATION_HPP_

#include <vector>

#include "meshapi/Set.hpp"
#include "meshapi/NullSet.hpp"

namespace asctoolkit {
namespace meshapi    {

  class NullSet;

  class Relation
  {
  public:
    typedef Set::PositionType                                             SetPosition;

    typedef std::vector<SetPosition>                                      RelationVec;
    typedef RelationVec::iterator                                         RelationVecIterator;
    typedef std::pair<RelationVecIterator,RelationVecIterator>            RelationVecIteratorPair;

    typedef RelationVec::const_iterator                                   RelationVecConstIterator;
    typedef std::pair<RelationVecConstIterator,RelationVecConstIterator>  RelationVecConstIteratorPair;

    static NullSet s_nullSet;

  public:
    virtual ~Relation(){}

    virtual RelationVecConstIterator      begin(SetPosition fromSetIndex)       const  = 0;

    virtual RelationVecConstIterator      end(SetPosition fromSetIndex)         const  = 0;

    virtual RelationVecConstIteratorPair  range(SetPosition fromSetIndex)   const  = 0;

    virtual SetPosition                   size(SetPosition fromSetIndex)                       const  = 0;

    virtual bool                          isValid(bool verboseOutput = false)                const = 0;

#if 0
    // Go through the relation's data and ensure that no entity from the ToSet is mapped to more than once by an element of the FromSet.
    // This operation will compact the relation
    // We can optionally sort the entities as well...
    // Not yet implemented
    virtual void        makeUnique() = 0;

    // Accessors to the underlying sets -- allows setting and getting the sets
    virtual Set*        fromSet()       = 0;
    virtual const Set*  fromSet() const = 0;
    virtual Set*        toSet()         = 0;
    virtual const Set*  toSet()   const = 0;

    // This function differs for each concrete relation type..
    void bindRelationData(..args..) = 0;

    // Accessors to the underlying relation data -- differs depending on the implementation (e.g. structured vs. unstructured
    ArrType* relationData() = 0;
#endif

  };


} // end namespace meshapi
} // end namespace asctoolkit

#endif // MESHAPI_RELATION_HPP_

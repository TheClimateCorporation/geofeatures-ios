/**
*   MultiPoint.hpp
*
*   Copyright 2015 The Climate Corporation
*
*   Licensed under the Apache License, Version 2.0 (the "License");
*   you may not use this file except in compliance with the License.
*   You may obtain a copy of the License at
*
*   http://www.apache.org/licenses/LICENSE-2.0
*
*   Unless required by applicable law or agreed to in writing, software
*   distributed under the License is distributed on an "AS IS" BASIS,
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*   See the License for the specific language governing permissions and
*   limitations under the License.
*
*   Created by Tony Stone on 6/9/15.
*/

#ifndef __MultiPoint_HPP_
#define __MultiPoint_HPP_

#include "Geometry.hpp"
#include "Point.hpp"

#include <boost/concept/requires.hpp>

#include <boost/geometry/core/tags.hpp>
#include <boost/geometry/geometries/concepts/point_concept.hpp>
#include <vector>

namespace climate {
    namespace gf {

        /**
        * Forward declarations
        */
        class Point;

        /**
        * Base type for Ring class
        */
        typedef std::vector<climate::gf::Point> MultiPointBaseType;

        /**
        * @class       MultiPoint
        *
        * @brief       A Collection of Points.
        *
        * @author      Tony Stone
        * @date        6/9/15
        */
        class MultiPoint : public Geometry, public MultiPointBaseType {

        public:
            inline MultiPoint() : Geometry(), MultiPointBaseType() {}
            inline virtual ~MultiPoint() {};
        };

        /** @defgroup BoostRangeIterators
        *
        * @{
        */
        inline MultiPointBaseType::iterator range_begin(MultiPoint& mp) {return mp.begin();}
        inline MultiPointBaseType::iterator range_end(MultiPoint& mp) {return mp.end();}
        inline MultiPointBaseType::const_iterator range_begin(const MultiPoint& mp) {return mp.begin();}
        inline MultiPointBaseType::const_iterator range_end(const MultiPoint& mp) {return mp.end();}
        /** @} */

    }   // namespace gf
}   // namespace climate

namespace boost {
    namespace geometry {
        namespace traits
        {
            template<>
            struct tag<climate::gf::MultiPoint> {
                typedef multi_point_tag type;
            };
        }
    } // namespace geometry::traits

    template<>
    struct range_iterator<climate::gf::MultiPoint>
    { typedef climate::gf::MultiPointBaseType::iterator type; };

    template<>
    struct range_const_iterator<climate::gf::MultiPoint>
    { typedef climate::gf::MultiPointBaseType::const_iterator type; };

} // namespace boost

#endif //__MultiPoint_HPP_

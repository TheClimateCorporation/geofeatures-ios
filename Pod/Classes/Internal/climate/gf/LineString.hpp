/**
*   LineString.hpp
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

#ifndef __LineString_HPP_
#define __LineString_HPP_

#include "Geometry.hpp"
#include "Point.hpp"

#include <boost/concept/assert.hpp>
#include <boost/range.hpp>

#include <boost/geometry/core/tag.hpp>
#include <boost/geometry/core/tags.hpp>

#include <boost/geometry/geometries/concepts/point_concept.hpp>
#include <vector>

namespace climate {
    namespace gf {

        /**
        * Base type for LineString class
        */
        typedef std::vector<climate::gf::Point> LineStringBaseType;

        /**
        * @class       LineString
        *
        * @brief       A Line of Points.
        *
        * @author      Tony Stone
        * @date        6/9/15
        */
        class LineString : public Geometry, public LineStringBaseType {

        public:
            inline LineString() : Geometry(), LineStringBaseType() {}
            LineString(LineStringBaseType &other) : Geometry(), LineStringBaseType(other) {}
            LineString(LineStringBaseType const &other) : Geometry(), LineStringBaseType(other) {}

            inline virtual ~LineString() {};
        };

    }   // namespace gf
}   // namespace climate

namespace boost {
    namespace geometry {
        namespace traits
        {
            template<>
            struct tag<climate::gf::LineString> {
                typedef linestring_tag type;
            };
        }
    } // namespace geometry::traits
} // namespace boost


#endif //__LineString_HPP_

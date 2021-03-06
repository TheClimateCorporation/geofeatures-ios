/**
*   MultiPolygon.hpp
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
#ifndef __MultiPolygon_HPP_
#define __MultiPolygon_HPP_

#include "Geometry.hpp"
#include "Polygon.hpp"

#include <boost/geometry/core/access.hpp>
#include <boost/geometry/core/coordinate_type.hpp>
#include <boost/geometry/core/coordinate_system.hpp>
#include <boost/geometry/core/coordinate_dimension.hpp>

#include <boost/geometry/geometries/concepts/point_concept.hpp>
#include <vector>

namespace climate {
    namespace gf {

        /**
        * Base type for MultiPolygon class
        */
        typedef std::vector<climate::gf::Polygon> MultiPolygonBaseType;

        /**
        * @class       MultiPolygon
        *
        * @brief       A Collection of Polygons.
        *
        * @author      Tony Stone
        * @date        6/9/15
        */
        class MultiPolygon : public Geometry, public MultiPolygonBaseType {

        public:

            inline MultiPolygon () : Geometry(), MultiPolygonBaseType() {}
            inline MultiPolygon (MultiPolygonBaseType & polygons) : Geometry(), MultiPolygonBaseType(polygons) {}

            inline virtual ~MultiPolygon() {};
        };

        /** @defgroup BoostRangeIterators
        *
        * @{
        */
        inline MultiPolygonBaseType::iterator range_begin(MultiPolygon& mp) {return mp.begin();}
        inline MultiPolygonBaseType::iterator range_end(MultiPolygon& mp) {return mp.end();}
        inline MultiPolygonBaseType::const_iterator range_begin(const MultiPolygon& mp) {return mp.begin();}
        inline MultiPolygonBaseType::const_iterator range_end(const MultiPolygon& mp) {return mp.end();}
        /** @} */

    }   // namespace gf
}   // namespace climate

namespace boost {
    namespace geometry {
        namespace traits
        {
            template<>
            struct tag<climate::gf::MultiPolygon> {
                typedef multi_polygon_tag type;
            };
        }
    } // namespace geometry::traits

    template<>
    struct range_iterator<climate::gf::MultiPolygon>
    { typedef climate::gf::MultiPolygonBaseType::iterator type; };

    template<>
    struct range_const_iterator<climate::gf::MultiPolygon>
    { typedef climate::gf::MultiPolygonBaseType::const_iterator type; };

} // namespace boost

#endif //__MultiPolygon_HPP_

/**
*   GeometryCollection.hpp
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
*   Created by Tony Stone on 6/10/15.
*/


#ifndef __GeometryCollection_HPP_
#define __GeometryCollection_HPP_

#include "Geometry.hpp"
#include "Point.hpp"
#include "MultiPoint.hpp"
#include "Box.hpp"
#include "LineString.hpp"
#include "MultiLineString.hpp"
#include "Ring.hpp"
#include "Polygon.hpp"
#include "MultiPolygon.hpp"
#include "GeometryCollection.hpp"

#include <boost/variant.hpp>
#include <vector>

namespace climate {
    namespace gf {

        /**
        * Variant type of contained objects
        */
        typedef boost::variant<
                climate::gf::Point,
                climate::gf::MultiPoint,
                climate::gf::Box,
                climate::gf::LineString,
                climate::gf::MultiLineString,
                climate::gf::Ring,
                climate::gf::Polygon,
                climate::gf::MultiPolygon>  GeometryCollectionVariantType;

        /**
        * Base type for GeometryCollection class
        */
        typedef std::vector<GeometryCollectionVariantType> GeometryCollectionBaseType;

        /**
        * @class       GeometryCollection
        *
        * @brief       A Collection of Geometries.
        *
        * @author      Tony Stone
        * @date        6/9/15
        */
        class GeometryCollection : public Geometry, public GeometryCollectionBaseType {

        public:
            inline GeometryCollection() : Geometry(), GeometryCollectionBaseType() {}
            inline GeometryCollection(GeometryCollectionBaseType const & other) : Geometry(), GeometryCollectionBaseType(other) {}
            inline virtual ~GeometryCollection() {}
        };

        /** @defgroup BoostRangeIterators
        *
        * @{
        */
        inline GeometryCollectionBaseType::iterator range_begin(GeometryCollection& gc) {return gc.begin();}
        inline GeometryCollectionBaseType::iterator range_end(GeometryCollection& gc) {return gc.end();}
        inline GeometryCollectionBaseType::const_iterator range_begin(const GeometryCollection& gc) {return gc.begin();}
        inline GeometryCollectionBaseType::const_iterator range_end(const GeometryCollection& gc) {return gc.end();}
        /** @} */

    }   // namespace gf
}   // namespace climate

#endif //__GeometryCollection_HPP_

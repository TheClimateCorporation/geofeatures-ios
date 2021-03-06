/**
*   WriteWKT.hpp
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
*   Created by Tony Stone on 6/13/15.
*/

#ifndef __WriteWKT_HPP_
#define __WriteWKT_HPP_

#include "GeometryCollection.hpp"
#include <boost/variant.hpp>
#include <boost/geometry/io/wkt/write.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/erase.hpp>
#include <boost/algorithm/string/find_iterator.hpp>

#include <regex>
#include <iostream>

namespace climate {
    namespace gf {

        template <typename Geometry>
        class wkt {

        public:
            wkt(const Geometry &geometry) : geometryCollection(geometry) {}
            virtual ~wkt() {}

        private:
            class variantToString : public  boost::static_visitor<std::string> {

            public:
                template <typename T>
                std::string operator()(const T & v) const {

                    std::stringstream stringStream;
                    stringStream << boost::geometry::wkt<T>(v);

                    return stringStream.str();
                }
            };

            const Geometry & geometryCollection;

            friend std::ostream& operator<<(std::ostream& os, const climate::gf::wkt<Geometry>& wkt);
        };

        inline std::ostream& operator<<(std::ostream& os, const climate::gf::wkt<climate::gf::GeometryCollection>& wkt)
        {
            os << "GEOMETRYCOLLECTION";

            if (wkt.geometryCollection.size() > 0) {

                os << "(";

                bool first = true;
                
                for (climate::gf::GeometryCollection::vector::const_iterator it = wkt.geometryCollection.begin();  it != wkt.geometryCollection.end(); ++it ) {
                    if (!first) {
                        os << ",";
                    }
                    os << boost::apply_visitor(climate::gf::wkt<climate::gf::GeometryCollection>::variantToString(), *it);
                    first = false;
                }
                os << ")";
            } else {
                os << "()";  // EMPTY
            }

            return os;
        }

    }   // namespace gf
}   // namespace climate

#endif //__WriteWKT_HPP_

/**
*   IsValidOperation.hpp
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
*   Created by Tony Stone on 6/11/15.
*/

#ifndef __IsValidOperation_HPP_
#define __IsValidOperation_HPP_

#include <boost/variant/variant.hpp>
#include <boost/geometry/strategies/strategies.hpp>
#include <boost/geometry/algorithms/is_valid.hpp>

#include "GeometryVariant.hpp"

namespace climate {
    namespace gf {
        namespace operators {

            class IsValidOperation : public  boost::static_visitor<bool> {

            public:
                template <typename T>
                bool operator()(const T & v) const {
                    return boost::geometry::is_valid(v);
                }

                bool operator()(const GeometryCollection & v) const {
                    return true;
                }
            };

        }   // namespace operators
    }   // namespace gf
}   // namespace climate

#endif //__IsValidperator_HPP_

/**
*   GFPolygonAbstract+Protected.hpp
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
*   Created by Tony Stone on 6/3/15.
*/

#ifndef __GFPolygonAbstractProtected_hpp
#define __GFPolygonAbstractProtected_hpp

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

#import "GFPolygonAbstract.h"

#include <boost/geometry.hpp>
#include "Polygon.hpp"

@interface GFPolygonAbstract (Protected)

    - (climate::gf::Polygon)cppPolygonWithGeoJSONCoordinates: (NSArray *) coordinates;
    - (NSArray *)geoJSONCoordinatesWithCPPPolygon: (const climate::gf::Polygon &) polygon;

    - (id <MKOverlay>)mkOverlayWithCPPPolygon: (const climate::gf::Polygon &) polygon;

@end

#endif // __GFPolygonAbstractProtected_hpp
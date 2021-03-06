/*
*   GFLineString.mm
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
*   Created by Tony Stone on 6/4/15.
*/

#include "GFLineString.h"
#include "GFLineStringAbstract+Protected.hpp"
#include "GFPoint.h"

#include "GFGeometry+Protected.hpp"
#include "LineString.hpp"

#include <boost/geometry/io/wkt/wkt.hpp>

@implementation GFLineString

    - (id)initWithWKT:(NSString *)wkt {
        NSParameterAssert(wkt != nil);

        try {
            climate::gf::LineString lineString;

            boost::geometry::read_wkt([wkt cStringUsingEncoding: NSUTF8StringEncoding], lineString);

            return [super initWithCPPGeometryVariant: lineString];

        } catch (std::exception & e) {
            @throw [NSException exceptionWithName:@"Exception" reason:[NSString stringWithUTF8String:e.what()] userInfo:nil];
        }
    }

    - (id)initWithGeoJSONGeometry:(NSDictionary *)jsonDictionary {
        NSParameterAssert(jsonDictionary != nil);

        id coordinates = jsonDictionary[@"coordinates"];
        
        if (!coordinates || ![coordinates isKindOfClass:[NSArray class]]) {
            @throw [NSException exceptionWithName:@"Invalid GeoJSON" reason:@"Invalid GeoJSON Geometry Object, no coordinates found or coordinates of an invalid type." userInfo:nil];
        }

        return [super initWithCPPGeometryVariant: [self cppLineStringWithGeoJSONCoordinates: jsonDictionary[@"coordinates"]]];
    }

    - (NSDictionary *) toGeoJSONGeometry {
        try {
            const climate::gf::LineString & lineString = boost::polymorphic_strict_get<climate::gf::LineString>([self cppGeometryConstReference]);
            
            return @{@"type": @"Point", @"coordinates": [self geoJSONCoordinatesWithCPPLineString: lineString]};
            
        } catch (std::exception & e) {
            @throw [NSException exceptionWithName:@"Exception" reason: [NSString stringWithUTF8String: e.what()] userInfo:nil];
        }
    }

    - (NSArray *)mkMapOverlays {
        try {
            const climate::gf::LineString & lineString = boost::polymorphic_strict_get<climate::gf::LineString>([self cppGeometryConstReference]);
            
            return @[[self mkOverlayWithCPPLineString: lineString]];
            
        } catch (std::exception & e) {
            @throw [NSException exceptionWithName:@"Exception" reason: [NSString stringWithUTF8String: e.what()] userInfo:nil];
        }
    }

@end


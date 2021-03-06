//
//  GeoFeaturesTests.m
//  GeoFeaturesTests
//
//  Created by Tony Stone on 04/14/2015.
//  Copyright (c) 2014 Tony Stone. All rights reserved.
//

#import <GeoFeatures/GeoFeatures.h>
#import "GFGeometryTests.h"
#import <MapKit/MapKit.h>

@interface GFGeometryMultiPolygonTests : GFGeometryTests
@end

static NSString * geometry1JSONString = @"{ \"type\": \"MultiPolygon\","
        "    \"coordinates\": ["
        "      [[[102.0, 2.0], [103.0, 2.0], [103.0, 3.0], [102.0, 3.0], [102.0, 2.0]]],"
        "      [[[100.0, 0.0], [101.0, 0.0], [101.0, 1.0], [100.0, 1.0], [100.0, 0.0]],"
        "       [[100.2, 0.2], [100.8, 0.2], [100.8, 0.8], [100.2, 0.8], [100.2, 0.2]]]"
        "      ]"
        "    }";

static NSString * geometry2JSONString = @"{ \"type\": \"MultiPolygon\","
        "    \"coordinates\": ["
        "      [[[103.0, 2.0], [104.0, 2.0], [104.0, 3.0], [103.0, 3.0], [103.0, 2.0]]],"
        "      [[[100.0, 0.0], [101.0, 0.0], [101.0, 1.0], [100.0, 1.0], [100.0, 0.0]],"
        "       [[100.2, 0.2], [100.8, 0.2], [100.8, 0.8], [100.2, 0.8], [100.2, 0.2]]]"
        "      ]"
        "    }";

@implementation GFGeometryMultiPolygonTests

    - (void)setUp {
        [super setUp];

        expectedClass       = NSClassFromString( @"GFMultiPolygon");
        geoJSONGeometryName = @"MultiPolygon";
        
        geometry1a = [GFGeometry geometryWithGeoJSONGeometry: [NSJSONSerialization JSONObjectWithData: [geometry1JSONString dataUsingEncoding: NSUTF8StringEncoding] options: 0 error: nil]];
        geometry1b = [GFGeometry geometryWithGeoJSONGeometry: [NSJSONSerialization JSONObjectWithData: [geometry1JSONString dataUsingEncoding: NSUTF8StringEncoding] options: 0 error: nil]];
        geometry2  = [GFGeometry geometryWithGeoJSONGeometry: [NSJSONSerialization JSONObjectWithData: [geometry2JSONString dataUsingEncoding: NSUTF8StringEncoding] options: 0 error: nil]];
    }

    - (void)tearDown {

        expectedClass       = nil;
        geoJSONGeometryName = nil;
        
        geometry1a = nil;
        geometry2           = nil;

        [super tearDown];
    }

    - (void) testMapOverlays {
        
        NSArray * mapOverlays = [geometry1a mkMapOverlays];
        
        XCTAssertNotNil (mapOverlays);
        XCTAssertTrue   ([mapOverlays count] == 2);
        
        for (int i = 0; i < [mapOverlays count]; i++) {
            id mapOverlay = [mapOverlays objectAtIndex: i];
            
            XCTAssertTrue   ([mapOverlay isKindOfClass: [MKPolygon class]]);
            
            MKPolygon * polygon = mapOverlay;
            
            XCTAssertTrue   ([polygon pointCount] == 5);
            
            if (i == 0) {
                XCTAssertTrue ([[polygon interiorPolygons] count] == 0);
            } else {
                XCTAssertTrue ([[polygon interiorPolygons] count] == 1);
            }
        }
    }

@end

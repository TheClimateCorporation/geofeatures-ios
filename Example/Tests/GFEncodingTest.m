//
//  GeoFeaturesTests.m
//  GeoFeaturesTests
//
//  Created by Tony Stone on 04/14/2015.
//  Copyright (c) 2014 Tony Stone. All rights reserved.
//

#import <GeoFeatures/GeoFeatures.h>
#import <XCTest/XCTest.h>

@interface GFEncodingTest : XCTestCase
@end

#define EncodingTest(wkt) XCTAssertEqualObjects([self encodeDecodeWithWKT: (wkt)], (wkt))

@implementation GFEncodingTest

    - (NSString *) encodeDecodeWithWKT: (NSString *) wkt {
        
        GFGeometry *inputGeometry = [GFGeometry geometryWithWKT: wkt];
        
        NSMutableData * archive = [[NSMutableData alloc] init];
        NSKeyedArchiver *archiver = [[NSKeyedArchiver alloc] initForWritingWithMutableData:archive];
        
        [archiver encodeObject:inputGeometry];
        [archiver finishEncoding];
        
        NSKeyedUnarchiver *unarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:archive];
        GFGeometry * resultGeometry = [unarchiver decodeObject];
        
        return [resultGeometry toWKTString];
    }

    - (void) testPoint {
        EncodingTest(@"POINT(1 1)");
    }

    - (void) testMultiPoint {
        EncodingTest(@"MULTIPOINT((1 1),(2 2))");
    }

    - (void) testLineString {
        EncodingTest(@"LINESTRING(40 60,120 110)");
    }

    - (void) testMultiLineString {
        EncodingTest(@"MULTILINESTRING((0 0,5 0),(5 0,10 0,5 -5,5 0),(5 0,5 5))");
    }

    - (void) testPolygon {
        EncodingTest(@"POLYGON((0 0,0 90,90 90,90 0,0 0))");
    }

    - (void) testMultiPolygon {
        EncodingTest(@"MULTIPOLYGON(((20 0,20 10,40 10,40 0,20 0)),((5 5,5 8,8 8,8 5,5 5)))");
    }

    - (void) testGeometryCollection {
        EncodingTest(@"GEOMETRYCOLLECTION(POLYGON((0 0,0 90,90 90,90 0,0 0)),POLYGON((120 0,120 90,210 90,210 0,120 0)),LINESTRING(40 50,40 140),LINESTRING(160 50,160 140),POINT(60 50),POINT(60 140),POINT(40 140))");
    }

@end
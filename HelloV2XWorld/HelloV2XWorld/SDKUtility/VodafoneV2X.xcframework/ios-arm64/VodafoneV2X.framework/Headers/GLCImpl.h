//
//  GLCImpl.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 16/12/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "GLCPartImpl.h"

NS_ASSUME_NONNULL_BEGIN

@protocol GeographicLocationContainer <NSObject, InitializableWithPointer, PublicPointer, UPERDecodable>

@required
@property(readonly) CLLocationDegrees referenceLatitude;
@property(readonly) CLLocationDegrees referenceLongitude;

@property(readonly) NSInteger referenceSemiMajorConfidence;
@property(readonly) NSInteger referenceSemiMinorConfidence;
@property(readonly) NSInteger referenceSemiMajorOrientation;

@property(readonly) CLLocationDistance referenceAltitudeValue;
@property(readonly) NSInteger referenceAltitudeConfidence;

@property(readonly, nullable) NSDate* referencePositionTime;

@property(readonly) CLLocationDirection referenceHeadingValue;
@property(readonly) NSInteger referenceHeadingConfidence;

@property(readonly) CLLocationSpeed referenceSpeedValue;
@property(readonly) NSInteger referenceSpeedConfidence;

@property(readonly, nullable) NSArray<id<GLCPart>> *parts;

@end

@interface GLCImpl : NSObject<GeographicLocationContainer>

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

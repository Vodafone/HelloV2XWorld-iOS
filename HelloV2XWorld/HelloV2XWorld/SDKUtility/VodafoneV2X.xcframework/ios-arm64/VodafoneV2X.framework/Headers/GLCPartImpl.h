//
//  GLCPartImpl.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 20/12/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "ZoneImpl.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, V2XLanePosition) {
    V2XLanePositionOffRoad = -1,
    V2XLanePositionHardShoulder = 0,
    V2XLanePositionOuterMostDrivingLane = 1,
    V2XLanePositionSecondLaneFromOutside = 2,
    V2XLanePositionUnavailable = NSIntegerMax
};

@protocol GLCPart <NSObject, InitializableWithPointer, PublicPointer, UPERDecodable>

@property(readonly) NSUInteger zoneId;
@property(readonly) V2XLanePosition laneNumber;
@property(readonly) NSUInteger zoneExtension;
@property(readonly) NSUInteger zoneHeading;
@property(readonly, nullable) id<Zone> zone;

@end

@interface GLCPartImpl : NSObject<GLCPart>

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

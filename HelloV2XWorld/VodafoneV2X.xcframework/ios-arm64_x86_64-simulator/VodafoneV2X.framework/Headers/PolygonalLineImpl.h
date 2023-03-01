//
//  PolygonalLineImpl.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 21/12/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "DeltaPositionImpl.h"
#import "DeltaReferencePositionImpl.h"
#import "AbsolutePositionImpl.h"
#import "AbsolutePositionWithAltitudeImpl.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, PolygonalLinePR) {
    PolygonalLinePRNothing = 0,
    PolygonalLinePRDeltaPositions,
    PolygonalLinePRDeltaPositionsWithAltitude,
    PolygonalLinePRAbsolutePositions,
    PolygonalLinePRAbsolutePositionsWithAltitude,
};

@protocol PolygonalLine <NSObject, InitializableWithPointer, PublicPointer, UPERDecodable>

/// active type of PolygonalLine
@property(readonly) PolygonalLinePR present;

@property(readonly, nullable) NSArray<id<DeltaPosition>>* deltaPositions;
@property(readonly, nullable) NSArray<id<DeltaReferencePosition>>* deltaPositionsWithAltitude;
@property(readonly, nullable) NSArray<id<AbsolutePosition>>* absolutePositions;
@property(readonly, nullable) NSArray<id<AbsolutePositionWithAltitude>>* absolutePositionsWithAltitude;

@end

@interface PolygonalLineImpl : NSObject<PolygonalLine>

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

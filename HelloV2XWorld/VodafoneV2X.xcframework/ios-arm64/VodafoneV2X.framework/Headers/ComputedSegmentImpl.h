//
//  ComputedSegmentImpl.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 21/12/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "DeltaReferencePositionImpl.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ComputedSegment <NSObject, InitializableWithPointer, PublicPointer, UPERCodable>

@property(readonly) NSUInteger zoneId;
@property(readonly) NSUInteger laneNumber;
@property(readonly) NSUInteger laneWidth;
@property(readonly) NSUInteger offsetDistance;
@property(readonly, nullable) id<DeltaReferencePosition> offsetPosition;

@end

@interface ComputedSegmentImpl : NSObject<ComputedSegment>

@property(nonatomic) NSUInteger zoneId;
@property(nonatomic) NSUInteger laneNumber;
@property(nonatomic) NSUInteger laneWidth;
@property(nonatomic) NSUInteger offsetDistance;
@property(nonatomic, nullable) DeltaReferencePositionImpl *offsetPosition;

@end

NS_ASSUME_NONNULL_END

//
//  ZoneImpl.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 20/12/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "PolygonalLineImpl.h"
#import "SegmentImpl.h"
#import "ComputedSegmentImpl.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZonePR) {
    ZonePRNothing = 0,
    ZonePRSegment,
    ZonePRArea,
    ZonePRComputedSegment
};

@protocol Zone <NSObject, InitializableWithPointer, PublicPointer, UPERDecodable>

@property(readonly) ZonePR present;

@property(readonly, nullable) id<Segment> segment;
@property(readonly, nullable) id<PolygonalLine> area;
@property(readonly, nullable) id<ComputedSegment> computedSegment;

@end

@interface ZoneImpl : NSObject<Zone>

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

//
//  SegmentImpl.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 21/12/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "PolygonalLineImpl.h"

NS_ASSUME_NONNULL_BEGIN

@protocol Segment <NSObject, InitializableWithPointer, PublicPointer, UPERDecodable>

@property(readonly) id<PolygonalLine> line;
@property(readonly) NSUInteger laneWidth;

@end

@interface SegmentImpl : NSObject<Segment>

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

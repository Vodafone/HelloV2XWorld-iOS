//
//  VruMotionPredictionContainerImpl.h
//  VodafoneV2X
//
//  Created by Ahmed Hamdy on 20/03/2022.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "PathPointImpl.h"
#import "VRUPathPointImpl.h"

NS_ASSUME_NONNULL_BEGIN

@protocol VruMotionPredictionContainer <NSObject>
@property(readonly, nullable) NSArray<id<PathPointPublic>> *pathHistory;
@property(readonly, nullable) NSArray<id<VRUPathPoint>> *pathPrediction;
@end


@interface VruMotionPredictionContainerImpl : NSObject<VruMotionPredictionContainer, InitializableWithPointer, PublicPointer, UPERCodable>

-(void)appendPathHistoryList:(NSArray<id<PathPointPublic>> *)pathHistory;
-(void)appendPathPredictionList:(NSArray<id<VRUPathPoint>> *)pathPrediction;

@end

NS_ASSUME_NONNULL_END

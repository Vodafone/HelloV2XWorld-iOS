//
//  IntersectionStateImpl.h
//  VodafoneV2X
//
//  Created by Mohamed Elabd on 24/02/2022.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "CommonEnums.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TrafficLighMovement;
@protocol TrafficLightRecord;

@protocol IntersectionState <NSObject, InitializableWithPointer, PublicPointer, UPERDecodable>

@property(nonatomic, readonly, nullable) NSString *name;
@property(nonatomic, readonly) NSUInteger region;
@property(nonatomic, readonly) NSUInteger trafficLightID;
@property(nonatomic, readonly) NSUInteger timeStamp;
@property(nonatomic, readonly) NSArray<id<TrafficLightRecord>>* trafficLights;
@property(nonatomic, readonly) NSArray<id<TrafficLighMovement>>* states;

@end

@interface IntersectionStateImpl : NSObject<IntersectionState>

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

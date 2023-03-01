//
//  VAMImpl.h
//  VodafoneV2X
//
//  Created by Ahmed Hamdy on 17/03/2022.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "CommonEnums.h"
#import "BasicContainerImpl.h"
#import "VruHighFrequencyContainerImpl.h"
#import "VruLowFrequencyContainerImpl.h"
#import "VruMotionPredictionContainerImpl.h"

NS_ASSUME_NONNULL_BEGIN

@protocol VAM <NSObject, InitializableWithPointer, PublicPointer, UPERCodable>

@property(readonly) NSUInteger stationID;
@property(readonly) ProtocolVersion protocolVersion;
@property(readonly) MessageID messageID;

@property(readonly) BasicContainerImpl* basicContainer;
@property(readonly) VruHighFrequencyContainerImpl* highFrequency;
@property(readonly) VruLowFrequencyContainerImpl* lowFrequency;
@property(readonly) VruMotionPredictionContainerImpl* motionPrediction;

- (void)locationSource:(CLLocation*)location heading:(nullable CLHeading *)heading;
- (void)appendPathHistoryPoints:(NSArray<CLLocation*> *)locations;
- (void)appendPathHistoryPoints:(NSArray<CLLocation*> *)locations andLocation:(CLLocationCoordinate2D) coordinate;
- (void)appendPathPredictionPoints:(NSArray<CLLocation*> *)locations;
- (void)setVruProfile:(StationKind)stationKind;
@end

@interface VAMImpl : NSObject<VAM>

@end

NS_ASSUME_NONNULL_END

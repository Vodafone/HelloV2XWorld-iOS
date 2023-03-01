//
//  CAMImpl.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 16/07/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "HighFrequencyContainerImpl.h"
#import "BasicContainerImpl.h"
#import "LowFrequencyContainerImpl.h"
#import "CommonEnums.h"

@class SHBPacketHeaderImpl;

NS_ASSUME_NONNULL_BEGIN

@protocol CAMProtocol <NSObject, InitializableWithPointer, PublicPointer, UPERCodable, BContainer, HFContainer, LFContainer>

/// CAM Basic container
@property(readonly) BasicContainerImpl* basicContainer;

/// CAM HighFrequency container
@property(readonly) HighFrequencyContainerImpl* highFrequency;

/// CAM LowFrequency container
@property(readonly, nullable) LowFrequencyContainerImpl* lowFrequencyContainer;

/// Station ID
@property(nonatomic) NSUInteger stationID;

/// Protocol version
@property(nonatomic) ProtocolVersion protocolVersion;

/// CAM Message ID
@property(nonatomic) MessageID messageID;

@property(readonly) SHBPacketHeaderImpl *camHeaders;

/// This is the place where the CLLocation received from GNSSReceiver should be injected to configure automatically all internal CAM properties
/// @param location location object retreived from GPS receiver
/// @param heading CLHeading retreived from GPS receiver
- (void)locationSource:(CLLocation*)location heading:(nullable CLHeading *)heading;

@end

/// CAMImpl is the entity reponsible for holding and managing a reference type CAM
/// It works as the bridging between the C++ and Apple World.
/// Specificities:
/// It implements the protocols for all the inner objects that composed it. Making it easy to set them directly
@interface CAMImpl : NSObject<CAMProtocol>

@property(nonatomic) NSUInteger stationID;
@property(nonatomic) ProtocolVersion protocolVersion;
@property(nonatomic) MessageID messageID;

@end

NS_ASSUME_NONNULL_END

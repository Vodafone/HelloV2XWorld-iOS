//
//  GBCPacketHeaderImpl.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 25/03/2022.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "BasicHeaderProtocol.h"
#import "CommonHeaderProtocol.h"
#import "LongPosVectorProtocol.h"
#import "BTPBProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol GBCPacketHeader <NSObject, BasicHeaderProtocol, CommonHeaderProtocol, LongPosVectorProtocol, BTPBProtocol>

@required
@property(readonly) NSUInteger sequenceNumber;
@property(readonly) CLLocationDistance distanceA;
@property(readonly) CLLocationDistance distanceB;
@property(readonly) CLLocationDegrees angle;

@end

@interface GBCPacketHeaderImpl : NSObject<ASN1Header, InitializableWithPointer, PublicPointer, GBCPacketHeader>

// DENMHeader Specifics
@property(nonatomic) NSUInteger sequenceNumber;
@property(nonatomic) CLLocationDistance distanceA;
@property(nonatomic) CLLocationDistance distanceB;
@property(nonatomic) CLLocationDegrees angle;

// BasicHeaderInterface
@property(nonatomic) V2XTimeBase timeBase;
@property(nonatomic) NSInteger multiplier;
@property(nonatomic) NSInteger version;
@property(nonatomic) V2XNextHeader nextHeaderAfterBH;
@property(nonatomic) NSInteger remaingHop;

// CommonHeaderInterface
@property(nonatomic) NSUInteger payloadLength;
@property(nonatomic) NSUInteger maxHopLimit;
@property(nonatomic) V2XCommonNextHeader nextHeaderAfterCH;
@property(nonatomic) V2XHeaderType headerType;
@property(nonatomic) BOOL scf;
@property(nonatomic) BOOL channelOffload;
@property(nonatomic) NSInteger tcid;
@property(nonatomic) BOOL flagsAreMobile;

// LongPositionVectorInterface
@property(nonatomic) StationKind stationType;
@property(nonatomic) V2XAddrConfig configuration;
@property(nonatomic) NSUInteger mid;
@property(nonatomic) NSDate* tst;
@property(nonatomic) CLLocationDegrees latitude;
@property(nonatomic) CLLocationDegrees longitude;
@property(nonatomic) BOOL accuracy;
@property(nonatomic) CLLocationSpeed speedValue;
@property(nonatomic) CLLocationDirection headingValue;

// BTPBInterface
@property(nonatomic) V2XDestPort destinationPort;
@property(nonatomic) NSInteger destinationPortInfo;


@end

NS_ASSUME_NONNULL_END

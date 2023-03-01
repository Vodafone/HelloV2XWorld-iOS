//
//  CommonHeaderProtocol.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 03/12/2021.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// this enum is composed by HeaderType(HT) and HeaderSubType(HST)
typedef NS_ENUM(NSUInteger, V2XHeaderType) {
    V2XHeaderTypeAnyUnspecified         = 0,
    V2XHeaderTypeBeaconUnspecified      = 16,
    V2XHeaderTypeGeoUnicastUnspecified  = 32,
    V2XHeaderTypeGeoAnyCastCircle       = 48,
    V2XHeaderTypeGeoAnyCastRect         = 49,
    V2XHeaderTypeGeoAnyCastElip         = 50,
    V2XHeaderTypeGeoBroadCircle         = 64,
    V2XHeaderTypeGeoBroadRect           = 65,
    V2XHeaderTypeGeoBroadElip           = 66,
    V2XHeaderTypeTsbSingleHop           = 80,
    V2XHeaderTypeTsbMultiHop            = 81,
    V2XHeaderTypeLsRequest              = 96,
    V2XHeaderTypeLsReply                = 97
};

typedef NS_ENUM(NSUInteger, V2XCommonNextHeader) {
    V2XCommonNextHeaderAny    = 0,
    V2XCommonNextHeaderBtpA   = 1,
    V2XCommonNextHeaderBtpB   = 2,
    V2XCommonNextHeaderIpv6   = 3
};

@protocol CommonHeaderProtocol <NSObject>

@required
@property(readonly) NSUInteger payloadLength;
@property(readonly) NSUInteger maxHopLimit;
@property(readonly) V2XCommonNextHeader nextHeaderAfterCH;
@property(readonly) V2XHeaderType headerType;
@property(readonly) BOOL scf;
@property(readonly) BOOL channelOffload;
@property(readonly) NSInteger tcid;
@property(readonly) BOOL flagsAreMobile;

@end

NS_ASSUME_NONNULL_END

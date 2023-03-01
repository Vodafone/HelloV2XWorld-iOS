//
//  LongPosVectorProtocol.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 03/12/2021.
//

#import <Foundation/Foundation.h>
#import "BasicContainerImpl.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, V2XAddrConfig) {
    V2XAddrConfigAutomatic,
    V2XAddrConfigManual
};

@protocol LongPosVectorProtocol <NSObject>

@required
@property(readonly) StationKind stationType;
@property(readonly) V2XAddrConfig configuration;
@property(readonly) NSUInteger mid;
@property(readonly) NSDate* tst;
@property(readonly) CLLocationDegrees latitude;
@property(readonly) CLLocationDegrees longitude;
@property(readonly) BOOL accuracy;
@property(readonly) CLLocationSpeed speedValue;
@property(readonly) CLLocationDirection headingValue;

@end

NS_ASSUME_NONNULL_END

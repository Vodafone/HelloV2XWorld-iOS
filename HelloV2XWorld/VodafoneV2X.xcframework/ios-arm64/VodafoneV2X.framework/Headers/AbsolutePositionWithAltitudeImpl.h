//
//  AbsolutePositionWithAltitudeImpl.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 21/12/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "CommonEnums.h"

NS_ASSUME_NONNULL_BEGIN

@protocol AbsolutePositionWithAltitude <NSObject, InitializableWithPointer, PublicPointer, UPERCodable>

@property(readonly) CLLocationDegrees latitude;
@property(readonly) CLLocationDegrees longitude;
@property(readonly) CLLocationDistance altitudeValue;
@property(readonly) V2XAltitudeConfidence altitudeConfidence;

@end

@interface AbsolutePositionWithAltitudeImpl: NSObject<AbsolutePositionWithAltitude>

@property(nonatomic) CLLocationDegrees latitude;
@property(nonatomic) CLLocationDegrees longitude;
@property(nonatomic) CLLocationDistance altitudeValue;
@property(nonatomic) V2XAltitudeConfidence altitudeConfidence;

@end

NS_ASSUME_NONNULL_END

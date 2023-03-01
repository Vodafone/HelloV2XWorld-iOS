//
//  DeltaPositionImpl.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 21/12/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"

NS_ASSUME_NONNULL_BEGIN

@protocol DeltaPosition <NSObject, InitializableWithPointer, PublicPointer, UPERCodable>

@property(readonly) CLLocationDegrees deltaLatitude;
@property(readonly) CLLocationDegrees deltaLongitude;

@end

@interface DeltaPositionImpl : NSObject<DeltaPosition>

/// deltaLatitude (-0.0131071..0.0131072)
@property(nonatomic) CLLocationDegrees deltaLatitude;
/// deltaLongitude (-0.0131071..0.0131072)
@property(nonatomic) CLLocationDegrees deltaLongitude;

@end

NS_ASSUME_NONNULL_END

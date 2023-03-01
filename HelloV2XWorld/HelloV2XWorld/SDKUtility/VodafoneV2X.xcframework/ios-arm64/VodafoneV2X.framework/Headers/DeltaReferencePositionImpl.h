//
//  DeltaReferencePositionImpl.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 21/12/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"

NS_ASSUME_NONNULL_BEGIN

@protocol DeltaReferencePosition <NSObject, InitializableWithPointer, PublicPointer, UPERCodable>

@property(readonly) CLLocationDegrees deltaLatitude;
@property(readonly) CLLocationDegrees deltaLongitude;
@property(readonly) CLLocationDistance deltaAltitude;
@end

@interface DeltaReferencePositionImpl : NSObject<DeltaReferencePosition>


/// deltaLatitude (-0.0131071..0.0131072)
@property(nonatomic) CLLocationDegrees deltaLatitude;
/// deltaLongitude (-0.0131071..0.0131072)
@property(nonatomic) CLLocationDegrees deltaLongitude;
/// deltaAltitude (-127..128)
@property(nonatomic) CLLocationDistance deltaAltitude;

@end

NS_ASSUME_NONNULL_END

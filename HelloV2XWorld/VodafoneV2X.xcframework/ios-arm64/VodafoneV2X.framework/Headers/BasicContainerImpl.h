//
//  BasicContainerImpl.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 17/07/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "CommonEnums.h"

NS_ASSUME_NONNULL_BEGIN

// MARK: BasicContainerImpl public interface
@protocol BContainer <NSObject>

@required
@property(nonatomic) StationKind stationType;
@property(nonatomic) CLLocationDegrees latitude;
@property(nonatomic) CLLocationDegrees longitude;
@property(nonatomic) CLLocationDistance altitudeValue;

/// Standard values V2XSemiAxisLength
@property(nonatomic) NSInteger semiMajorConfidence;

/// Standard values V2XSemiAxisLength
@property(nonatomic) NSInteger semiMinorConfidence;

/// Standard values V2XHeadingValue
@property(nonatomic) V2XHeadingValue semiMajorOrientation;

@property(nonatomic) V2XAltitudeConfidence altitudeConfidence;

@end

///The basic container includes basic information related to the originating ITS-S.
@interface BasicContainerImpl : NSObject<BContainer, InitializableWithPointer, PublicPointer, UPERCodable>

@end

NS_ASSUME_NONNULL_END

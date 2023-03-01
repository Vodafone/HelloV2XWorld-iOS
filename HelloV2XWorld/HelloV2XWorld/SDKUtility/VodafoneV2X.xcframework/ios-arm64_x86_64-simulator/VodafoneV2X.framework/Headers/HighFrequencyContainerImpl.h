//
//  HighFrequencyContainerImpl.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 16/07/2021.
//

#import <Foundation/Foundation.h>
#import "CommonEnums.h"
#import "CodingProtocols.h"

NS_ASSUME_NONNULL_BEGIN

// MARK: HighFrequencyContainerImpl public interface
@protocol HFContainer <NSObject>

@required

// standards V2XHeadingValue
@property(nonatomic) CLLocationDirection headingValue;
@property(nonatomic) CLLocationSpeed speedValue;
@property(nonatomic) NSInteger vehicleLength;
@property(nonatomic) NSInteger vehicleWidth;

@end

/// HighFrequencyImpl
@interface HighFrequencyContainerImpl : NSObject<HFContainer, InitializableWithPointer, PublicPointer, UPERCodable>

/// default "BasicVehicleContainerHighFrequency"
@property(nonatomic) V2XHighFrequencyContainer present;

/// default "EqualOrWithinOneDegree"
@property(nonatomic) V2XHeadingConfidence headingConfidence;

/// default "EqualOrWithinOneMeterPerSec"
@property(nonatomic) V2XSpeedConfidence speedConfidence;

/// default "NoTrailerPresent"
@property(nonatomic) V2XVehicleLengthConfidenceIndication vehicleLengthConfidenceIndication;

/// default "Unavailable"
@property(nonatomic) V2XLongitudinalAccelerationValue longitudinalAccelerationValue;

/// default "Unavailable"
@property(nonatomic) V2XLongitudinalAccelerationConfidence longitudinalAccelerationConfidence;

/// default "Unavailable"
@property(nonatomic) V2XCurvatureValue curvatureValue;

/// default "Unavailable"
@property(nonatomic) V2XCurvatureConfidence curvatureConfidence;

/// default "Unavailable"
@property(nonatomic) V2XYawRateValue yawRateValue;

/// default "Unavailable"
@property(nonatomic) V2XYawRateConfidence yawRateConfidence;

/// default "Forward"
@property(nonatomic) V2XDriveDirection driveDirection;

/// default "Unavailable"
@property(nonatomic) V2XCurvatureCalculationMode curvatureCalculationMode;

@end

NS_ASSUME_NONNULL_END

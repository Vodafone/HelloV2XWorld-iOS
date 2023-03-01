//
//  CommonEnums.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 10/12/2021.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, V2XDeltaLatitude) {
    V2XDeltaLatitudeOneMicrodegreeNorth    = 10,
    V2XDeltaLatitudeOneMicrodegreeSouth    = -10,
    V2XDeltaLatitudeUnavailable            = 131072
};

typedef NS_ENUM(NSInteger, V2XDeltaLongitude) {
    V2XDeltaLongitudeOneMicrodegreeEast    = 10,
    V2XDeltaLongitudeOneMicrodegreeWest    = -10,
    V2XDeltaLongitudeUnavailable           = 131072
};

typedef NS_ENUM(NSInteger, V2XDeltaAltitude) {
    V2XDeltaAltitudeOneCentimeterUp    = 1,
    V2XDeltaAltitudeOneCentimeterDown  = -1,
    V2XDeltaAltitudeUnavailable        = 12800
};

typedef NS_ENUM(NSInteger, V2XHeadingConfidence) {
    V2XHeadingConfidenceEqualOrWithinZeroPointOneDegree = 1,
    V2XHeadingConfidenceEqualOrWithinOneDegree          = 10,
    V2XHeadingConfidenceOutOfRange                      = 126,
    V2XHeadingConfidenceUnavailable                     = 127
};

typedef NS_ENUM(NSUInteger, V2XSpeedConfidence) {
    V2XSpeedConfidenceEqualOrWithinOneCentimeterPerSec    = 1,
    V2XSpeedConfidenceEqualOrWithinOneMeterPerSec    = 100,
    V2XSpeedConfidenceOutOfRange    = 126,
    V2XSpeedConfidenceUnavailable    = 127
};

typedef NS_ENUM(NSUInteger, V2XSpeedValue) {
    V2XSpeedValueStandstill = 0,
    V2XSpeedValueOneMeterPerSec = 1,
    V2XSpeedValueUnavailable = 16383,
};

typedef NS_ENUM(NSUInteger, V2XVehicleLengthConfidenceIndication) {
    V2XVehicleLengthConfidenceIndicationNoTrailerPresent                = 0,
    V2XVehicleLengthConfidenceIndicationTrailerPresentWithKnownLength   = 1,
    V2XVehicleLengthConfidenceIndicationTrailerPresentWithUnknownLength = 2,
    V2XVehicleLengthConfidenceIndicationTrailerPresenceIsUnknown        = 3,
    V2XVehicleLengthConfidenceIndicationUnavailable                     = 4
};

typedef NS_ENUM(NSInteger, V2XLongitudinalAccelerationValue) {
    V2XLongitudinalAccelerationValuePointOneMeterPerSecSquaredForward    = 1,
    V2XLongitudinalAccelerationValuePointOneMeterPerSecSquaredBackward    = -1,
    V2XLongitudinalAccelerationValueUnavailable    = 161
};

typedef NS_ENUM(NSInteger, V2XLongitudinalAccelerationConfidence) {
    V2XLongitudinalAccelerationConfidencePointOneMeterPerSecSquared    = 1,
    V2XLongitudinalAccelerationConfidenceOutOfRange    = 101,
    V2XLongitudinalAccelerationConfidenceUnavailable    = 102
};

typedef NS_ENUM(NSUInteger, V2XCurvatureValue) {
    V2XCurvatureValueStraight = 0,
    V2XCurvatureValueUnavailable = 1023
};

typedef NS_ENUM(NSUInteger, V2XCurvatureConfidence) {
    V2XCurvatureConfidenceOnePerMeter_0_00002   = 0,
    V2XCurvatureConfidenceOnePerMeter_0_0001    = 1,
    V2XCurvatureConfidenceOnePerMeter_0_0005    = 2,
    V2XCurvatureConfidenceOnePerMeter_0_002     = 3,
    V2XCurvatureConfidenceOnePerMeter_0_01      = 4,
    V2XCurvatureConfidenceOnePerMeter_0_1       = 5,
    V2XCurvatureConfidenceOutOfRange            = 6,
    V2XCurvatureConfidenceUnavailable           = 7
};

typedef NS_ENUM(NSInteger, V2XYawRateValue) {
    V2XYawRateValueStraight             = 0,
    V2XYawRateValueDegSec_000_01ToRight = -1,
    V2XYawRateValueDegSec_000_01ToLeft  = 1,
    V2XYawRateValueUnavailable          = 32767
};

typedef NS_ENUM(NSInteger, V2XYawRateConfidence) {
    V2XYawRateConfidenceDegSec_000_01   = 0,
    V2XYawRateConfidenceDegSec_000_05   = 1,
    V2XYawRateConfidenceDegSec_000_10   = 2,
    V2XYawRateConfidenceDegSec_001_00   = 3,
    V2XYawRateConfidenceDegSec_005_00   = 4,
    V2XYawRateConfidenceDegSec_010_00   = 5,
    V2XYawRateConfidenceDegSec_100_00   = 6,
    V2XYawRateConfidenceOutOfRange      = 7,
    V2XYawRateConfidenceUnavailable     = 8
};

typedef NS_ENUM(NSUInteger, V2XDriveDirection) {
    V2XDriveDirectionForward        = 0,
    V2XDriveDirectionBackward       = 1,
    V2XDriveDirectionUnavailable    = 2
};

typedef NS_ENUM(NSUInteger, V2XCurvatureCalculationMode) {
    V2XCurvatureCalculationModeYawRateUsed    = 0,
    V2XCurvatureCalculationModeYawRateNotUsed    = 1,
    V2XCurvatureCalculationModeUnavailable    = 2
};

typedef NS_ENUM(NSUInteger, V2XHighFrequencyContainer) {
    V2XHighFrequencyContainerNothing,
    V2XHighFrequencyContainerBasicVehicleContainerHighFrequency,
    V2XHighFrequencyContainerRsuContainerHighFrequency
};

typedef NS_ENUM(NSInteger, V2XVehicleWidth) {
    V2XVehicleWidthTenCentimeters   = 1,
    V2XVehicleWidthOutOfRange       = 61,
    V2XVehicleWidthUnavailable      = 62
};

typedef NS_ENUM(NSInteger, V2XVehicleLength) {
    V2XVehicleLengthTenCentimeters  = 1,
    V2XVehicleLengthOutOfRange      = 1022,
    V2XVehicleLengthUnavailable     = 1023
};

typedef NS_ENUM(NSInteger, ProtocolVersion) {
    ProtocolVersionCurrentVersion  = 2
};

typedef NS_ENUM(NSUInteger, MessageID) {
    MessageIDDenm                = 1,
    MessageIDCam                 = 2,
    MessageIDPoi                 = 3,
    MessageIDSpatem              = 4,
    MessageIDMapem               = 5,
    MessageIDIvim                = 6,
    MessageIDEv_rsr              = 7,
    MessageIDTistpgtransaction   = 8,
    MessageIDSrem                = 9,
    MessageIDSsem                = 10,
    MessageIDEvcsn               = 11,
    MessageIDSaem                = 12,
    MessageIDRtcmem              = 13,
    MessageIDVam                 = 14
};

typedef NS_ENUM(NSInteger, V2XAltitudeConfidence) {
    V2XAltitudeConfidence_000_01        = 0,
    V2XAltitudeConfidence_000_02        = 1,
    V2XAltitudeConfidence_000_05        = 2,
    V2XAltitudeConfidence_000_10        = 3,
    V2XAltitudeConfidence_000_20        = 4,
    V2XAltitudeConfidence_000_50        = 5,
    V2XAltitudeConfidence_001_00        = 6,
    V2XAltitudeConfidence_002_00        = 7,
    V2XAltitudeConfidence_005_00        = 8,
    V2XAltitudeConfidence_010_00        = 9,
    V2XAltitudeConfidence_020_00        = 10,
    V2XAltitudeConfidence_050_00        = 11,
    V2XAltitudeConfidence_100_00        = 12,
    V2XAltitudeConfidence_200_00        = 13,
    V2XAltitudeConfidence_OutOfRange    = 14,
    V2XAltitudeConfidence_Unavailable   = 15
};

typedef NS_ENUM(NSUInteger, StationKind) {
    StationKindUnknown          = 0,
    StationKindPedestrian       = 1,
    StationKindCyclist          = 2,
    StationKindMoped            = 3,
    StationKindMotorcycle       = 4,
    StationKindPassengerCar     = 5,
    StationKindBus              = 6,
    StationKindLightTruck       = 7,
    StationKindHeavyTruck       = 8,
    StationKindTrailer          = 9,
    StationKindSpecialVehicles  = 10,
    StationKindTram             = 11,
    StationKindRoadSideUnit     = 15
};

typedef NS_ENUM(NSUInteger, V2XSemiAxisLength) {
    V2XSemiAxisLengthOneCentimeter    = 1,
    V2XSemiAxisLengthOutOfRange    = 4094,
    V2XSemiAxisLengthUnavailable    = 4095
};

typedef NS_ENUM(NSInteger, V2XHeadingValue) {
    V2XHeadingValueWgs84North    = 0,
    V2XHeadingValueWgs84East     = 900,
    V2XHeadingValueWgs84South    = 1800,
    V2XHeadingValueWgs84West     = 2700,
    V2XHeadingValueUnavailable   = 3601
};

typedef NS_ENUM(NSInteger, V2XAltitudeValue) {
    V2XAltitudeValueRefElioidSurface = 0,
    V2XAltitudeValueOneCentimeter = 1,
    V2XAltitudeValueUnavailable   = 800001,
};

typedef NS_ENUM(NSUInteger, V2XTrafficLighState) {
    V2XTrafficLighStateUnavailable,
    V2XTrafficLighStateDark,
    V2XTrafficLighStateStopThenProceed,
    V2XTrafficLighStateStopAndRemain,
    V2XTrafficLighStatePreMovement,
    V2XTrafficLighStatePermissiveMovementAllowed,
    V2XTrafficLighStateProtectedMovementAllowed ,
    V2XTrafficLighStatePermissiveClearance,
    V2XTrafficLighStateProtectedClearance,
    V2XTrafficLighStateCautionConflictingTraffic
};

typedef NS_ENUM(NSUInteger, V2XMappedProfile) {
    V2XProSubMappedNothing                  = 0,
    
    V2XProSubMappedPedestrianUnavailable    = (1 << 4), // 16
    V2XProSubMappedPedestrianOrdenary       = 17,
    V2XProSubMappedPedestrianRoadWorker     = 18,
    V2XProSubMappedPedestrianFirstResponder = 19,
    V2XProSubMappedPedestrianMax            = 31,
    
    V2XProSubMappedBicyclistUnavailable         = (2 << 4), // 32
    V2XProSubMappedBicyclist                    = 33,
    V2XProSubMappedBicyclistWheelChair          = 34,
    V2XProSubMappedBicyclistHorseAndRider       = 35,
    V2XProSubMappedBicyclistRollerSkater        = 36,
    V2XProSubMappedBicyclistEScooter            = 37,
    V2XProSubMappedBicyclistPersonalTransporter = 38,
    V2XProSubMappedBicyclistPedelec             = 39,
    V2XProSubMappedBicyclistSpeedPedelec        = 40,
    V2XProSubMappedBicyclistMax                 = 47,
    
    V2XProSubMappedMotorcyclistUnavailable                  = (3 << 4), // 48
    V2XProSubMappedMotorcyclistMoped                        = 49,
    V2XProSubMappedMotorcyclistMotorcycle                   = 50,
    V2XProSubMappedMotorcyclistMotorcycleAndSidecarRight    = 51,
    V2XProSubMappedMotorcyclistMotorcycleAndSidecarLeft     = 52,
    V2XProSubMappedMotorcyclistMax                          = 63,
    
    V2XProSubMappedAnimalUnavailable    = (4 << 4), //64
    V2XProSubMappedAnimalWildAnimal     = 65,
    V2XProSubMappedAnimalFarmAnimal     = 66,
    V2XProSubMappedAnimalServiceAnimal  = 67,
    V2XProSubMappedAnimalMax            = 79
};

typedef NS_ENUM(NSUInteger, V2XDestPort) {
    V2XDestPortCam               = 2001,
    V2XDestPortDenm              = 2002,
    V2XDestPortMapem             = 2003,
    V2XDestPortSpatem            = 2004,
    V2XDestPortSaem              = 2005,
    V2XDestPortIvim              = 2006,
    V2XDestPortSrem              = 2007,
    V2XDestPortSsem              = 2008,
    V2XDestPortAllocated         = 2009,
    V2XDestPortEvcsn_poi         = 2010,
    V2XDestPortTpg               = 2011,
    V2XDestPortCharging          = 2012,
    V2XDestPortGpc               = 2013,
    V2XDestPortCtl               = 2014,
    V2XDestPortCrl               = 2015,
    V2XDestPortCertReqService    = 2016,
    V2XDestPortMCDM              = 2017,
    V2XDestPortVAM               = 2018,
    V2XDestPortIMZM              = 2019
};

typedef NS_ENUM(NSUInteger, V2XDrivenLineOffset) {
    V2XSmall,
    V2XLarge
};

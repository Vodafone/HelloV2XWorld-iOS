//
//  LowFrequencyContainerImpl.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 17/07/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "PathPointImpl.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, V2XVehicleRole) {
    V2XVehicleRoleDefault           = 0,
    V2XVehicleRolePublicTransport   = 1,
    V2XVehicleRoleSpecialTransport  = 2,
    V2XVehicleRoleDangerousGoods    = 3,
    V2XVehicleRoleRoadWork          = 4,
    V2XVehicleRoleRescue            = 5,
    V2XVehicleRoleEmergency         = 6,
    V2XVehicleRoleSafetyCar         = 7,
    V2XVehicleRoleAgriculture       = 8,
    V2XVehicleRoleCommercial        = 9,
    V2XVehicleRoleMilitary          = 10,
    V2XVehicleRoleRoadOperator      = 11,
    V2XVehicleRoleTaxi              = 12,
    V2XVehicleRoleReserved1         = 13,
    V2XVehicleRoleReserved2         = 14,
    V2XVehicleRoleReserved3         = 15,
    V2XVehicleRoleNotDefined        = NSUIntegerMax
};

typedef NS_OPTIONS(NSUInteger, V2XExteriorLights) {
    V2XExteriorLightsLowBeamHeadlightsOn    = 1 << 7,
    V2XExteriorLightsHighBeamHeadlightsOn   = 1 << 6,
    V2XExteriorLightsLeftTurnSignalOn       = 1 << 5,
    V2XExteriorLightsRightTurnSignalOn      = 1 << 4,
    V2XExteriorLightsDaytimeRunningLightsOn = 1 << 3,
    V2XExteriorLightsReverseLightOn         = 1 << 2,
    V2XExteriorLightsFogLightOn             = 1 << 1,
    V2XExteriorLightsParkingLightsOn        = 1 << 0,
    V2XExteriorLightsNone                   = 0,
};

// MARK: LowFrequencyContainerImpl public interface
@protocol LFContainer <NSObject>

@required
@property(nonatomic) V2XVehicleRole role;
@property(nonatomic) V2XExteriorLights exteriorLights;
@property(readonly) NSArray<id<PathPointPublic>> *pathPoints;

@end

@interface LowFrequencyContainerImpl : NSObject<LFContainer, InitializableWithPointer, PublicPointer, UPERCodable>

- (void)appendPath:(id<PathPointPublic>)point;
- (void)removePath:(id<PathPointPublic>)point;

@end

NS_ASSUME_NONNULL_END

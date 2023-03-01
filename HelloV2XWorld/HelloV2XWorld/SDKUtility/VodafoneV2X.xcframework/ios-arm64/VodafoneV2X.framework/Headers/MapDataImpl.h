//
//  MapDataImpl.h
//  VodafoneV2X
//
//  Created by Gonçalo Martins on 19/01/2022.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, V2XLayerType) {
    V2XLayerTypeNone = 0,
    V2XLayerTypeMixedContent = 1,
    V2XLayerTypeGeneralMapData = 2,
    V2XLayerTypeIntersectionData = 3,
    V2XLayerTypeCurveData = 4,
    V2XLayerTypeRoadwaySectionData = 5,
    V2XLayerTypeParkingAreaData = 6,
    V2XLayerTypeSharedLaneData = 7
};

typedef NS_ENUM(NSUInteger, V2XAllowedManeuver) {
    V2XAllowedManeuverStraightAllowed    = 0,
    V2XAllowedManeuverLeftAllowed    = 1,
    V2XAllowedManeuverRightAllowed    = 2,
    V2XAllowedManeuverUTurnAllowed    = 3,
    V2XAllowedManeuverLeftTurnOnRedAllowed    = 4,
    V2XAllowedManeuverRightTurnOnRedAllowed    = 5,
    V2XAllowedManeuverLaneChangeAllowed    = 6,
    V2XAllowedManeuverNoStoppingAllowed    = 7,
    V2XAllowedManeuverYieldAllwaysRequired    = 8,
    V2XAllowedManeuverGoWithHalt    = 9,
    V2XAllowedManeuverCaution    = 10,
    V2XAllowedManeuverReserved1    = 11
};

typedef NS_ENUM(NSUInteger, V2XLaneType) {
    V2XLaneTypeNothing = 0,
    V2XLaneTypeVehicle = 1,
    V2XLaneTypeCrosswalk = 2,
    V2XLaneTypeBike = 3,
    V2XLaneTypeSidewalk = 4,
    V2XLaneTypeBarrier = 5,
    V2XLaneTypeStriping = 6,
    V2XLaneTypeTrackedVehicle = 7,
    V2XLaneTypeParking = 8
};

typedef NS_ENUM(NSUInteger, V2XLaneDirection) {
    V2XLaneDirectionIngress = 80,
    V2XLaneDirectionEgress = 40
};

@protocol GenericLane, IntersectionGeometry;

@protocol MapData <NSObject, InitializableWithPointer, PublicPointer, UPERDecodable>

@required

@property(readonly, nullable, nonatomic) NSArray<id<IntersectionGeometry>> *intersections;

@end

@interface MapDataImpl : NSObject<MapData>

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END


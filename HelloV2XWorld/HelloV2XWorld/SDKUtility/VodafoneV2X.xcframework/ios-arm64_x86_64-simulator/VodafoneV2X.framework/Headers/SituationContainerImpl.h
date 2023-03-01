//
//  SituationContainerImpl.h
//  VodafoneV2X
//
//  Created by Gonçalo Martins on 08/09/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "EventPointImpl.h"
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, InformationQualityKind) {
    InformationQualityKindUnavailable    = 0,
    InformationQualityKindLowest    = 1,
    InformationQualityKindHighest    = 7
};

typedef NS_ENUM(NSUInteger, CauseCodeKind) {
    CauseCodeKindReserved    = 0,
    CauseCodeKindTrafficCondition    = 1,
    CauseCodeKindAccident    = 2,
    CauseCodeKindRoadworks    = 3,
    CauseCodeKindImpassability    = 5,
    CauseCodeKindAdverseWeatherConditionAdhesion    = 6,
    CauseCodeKindAquaplannning    = 7,
    CauseCodeKindHazardousLocationSurfaceCondition    = 9,
    CauseCodeKindHazardousLocationObstacleOnTheRoad    = 10,
    CauseCodeKindHazardousLocationAnimalOnTheRoad    = 11,
    CauseCodeKindHumanPresenceOnTheRoad    = 12,
    CauseCodeKindWrongWayDriving    = 14,
    CauseCodeKindRescueAndRecoveryWorkInProgress    = 15,
    CauseCodeKindAdverseWeatherConditionExtremeWeatherCondition    = 17,
    CauseCodeKindAdverseWeatherConditionVisibility    = 18,
    CauseCodeKindAdverseWeatherConditionPrecipitation    = 19,
    CauseCodeKindSlowVehicle    = 26,
    CauseCodeKindDangerousEndOfQueue    = 27,
    CauseCodeKindVehicleBreakdown    = 91,
    CauseCodeKindPostCrash    = 92,
    CauseCodeKindHumanProblem    = 93,
    CauseCodeKindStationaryVehicle    = 94,
    CauseCodeKindEmergencyVehicleApproaching    = 95,
    CauseCodeKindHazardousLocationDangerousCurve    = 96,
    CauseCodeKindCollisionRisk    = 97,
    CauseCodeKindSignalViolation    = 98,
    CauseCodeKindDangerousSituation    = 99,
    CauseCodeKindUnknown    = NSIntegerMax
};

// MARK: SituationContainerImpl public interface
@protocol SContainer <NSObject>

@required
@property(nonatomic) InformationQualityKind informationQuality;

@property(nonatomic) CauseCodeKind eventCauseCode;
@property(nonatomic) NSUInteger eventSubCauseCode;

@property(nonatomic) CauseCodeKind linkedCauseCode;
@property(nonatomic) NSUInteger linkedSubCauseCode;

@property(readonly, nullable) NSArray<id<EventPointPublic>> *eventHistoryList;

@end

@interface SituationContainerImpl : NSObject<SContainer, InitializableWithPointer, PublicPointer, UPERCodable>

-(void)appendPathHistoryList:(NSArray<id<EventPointPublic>> *)pathHistory;

@end

NS_ASSUME_NONNULL_END

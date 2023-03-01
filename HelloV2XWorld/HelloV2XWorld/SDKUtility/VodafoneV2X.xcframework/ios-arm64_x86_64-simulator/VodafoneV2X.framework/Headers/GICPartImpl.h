//
//  GICPartImpl.h
//  VodafoneV2X
//
//  Created by Gonçalo Martins on 14/12/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, V2XDirection) {
    V2XDirectionSameDirection    = 0,
    V2XDirectionOppositeDirection    = 1,
    V2XDirectionBothDirections    = 2,
    V2XDirectionValueNotUsed    = 3,
    V2XDirectionUnavailable = NSUIntegerMax
};

typedef NS_ENUM(NSUInteger, IVIType) {
    IVITypeImmediateDangerWarningMessages    = 0,
    IVITypeRegulatoryMessages    = 1,
    IVITypeTrafficRelatedInformationMessages    = 2,
    IVITypePollutionMessages    = 3,
    IVITypeNotTrafficRelatedInformationMessages    = 4
};

typedef NS_ENUM(NSUInteger, IVIPurpose) {
    IVIPurposeSafety    = 0,
    IVIPurposeEnvironmental    = 1,
    IVIPurposeTrafficOptimisation    = 2
};

typedef NS_ENUM(NSUInteger, V2XLaneStatus) {
    V2XLaneStatusOpen    = 0,
    V2XLaneStatusClosed    = 1,
    V2XLaneStatusMergeR    = 2,
    V2XLaneStatusMergeL    = 3,
    V2XLaneStatusMergeLR    = 4,
    V2XLaneStatusProvisionallyOpen    = 5,
    V2XLaneStatusDiverging    = 6,
    V2XLaneStatusUnavailable = NSUIntegerMax
};

@protocol RoadSignISO14823;
@protocol TextLines;

@protocol GICPart <NSObject, InitializableWithPointer, PublicPointer, UPERDecodable>

@required

@property(readonly, nullable) NSArray<NSNumber *> *detectionZoneIds;
@property(readonly, nullable) NSArray<NSNumber *> *relevanceZoneIds;
@property(readonly, nullable) NSArray<NSNumber *> *driverAwarenessZoneIds;
@property(readonly, nullable) NSArray<NSNumber *> *applicableLanes;
@property(readonly, nullable) NSArray<id<TextLines>> *extraTexts;

@property(readonly) NSArray<id<RoadSignISO14823>> *roadSignCodes;

@property(readonly) V2XDirection direction;
@property(readonly) IVIType iviType;
@property(readonly) V2XLaneStatus laneStatus;

@property(readonly) NSUInteger minimumAwarenessTime;
@property(readonly) NSUInteger layoutId;
@property(readonly) NSUInteger preStoredlayoutId;

@end

@interface GICPartImpl : NSObject<GICPart>

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END


//
//  ManagementContainerImpl.h
//  VodafoneV2X
//
//  Created by Gonçalo Martins on 06/09/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "BasicContainerImpl.h"

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, ITSTimestamp) {
    ITSTimestampUTCStartOf2004    = 0,
    ITSTimestampOneMillisecAfterUTCStartOf2004    = 1
};

typedef NS_ENUM(NSInteger,TerminationKind) {
    TerminationKindIsCancellation   = 0,
    TerminationKindIsNegation       = 1,
    TerminationKindIsUnknown        = 2
};

typedef NS_ENUM(NSUInteger, RelevanceDistanceKind) {
    RelevanceDistanceKindLessThan50m    = 0,
    RelevanceDistanceKindLessThan100m    = 1,
    RelevanceDistanceKindLessThan200m    = 2,
    RelevanceDistanceKindLessThan500m    = 3,
    RelevanceDistanceKindLessThan1000m    = 4,
    RelevanceDistanceKindLessThan5km    = 5,
    RelevanceDistanceKindLessThan10km    = 6,
    RelevanceDistanceKindOver10km    = 7
};

typedef NS_ENUM(NSInteger, RelevanceTrafficDirectionKind) {
    RelevanceTrafficDirectionKindAllTrafficDirections    = 0,
    RelevanceTrafficDirectionKindUpstreamTraffic    = 1,
    RelevanceTrafficDirectionKindDownstreamTraffic    = 2,
    RelevanceTrafficDirectionKindOppositeTraffic    = 3
};

typedef NS_ENUM(NSInteger, ValidityDurationKind) {
    ValidityDurationKindTimeOfDetection    = 0,
    ValidityDurationKindOneSecondAfterDetection    = 1
};

typedef NS_ENUM(NSInteger, TransmissionIntervalKind) {
    TransmissionIntervalKindOneMilliSecond    = 1,
    TransmissionIntervalKindTenSeconds    = 10000
};

typedef NS_ENUM(NSInteger, V2XLongitude) {
    V2XLongitudeOneMicrodegreeEast    = 10,
    V2XLongitudeOneMicrodegreeWest    = -10,
    V2XLongitudeUnavailable    = 1800000001
};

typedef NS_ENUM(NSInteger, V2XLatitude) {
    V2XLatitudeOneMicrodegreeNorth    = 10,
    V2XLatitudeOneMicrodegreeSouth    = -10,
    V2XLatitudeUnavailable    = 900000001
};

// MARK: ManagementContainerImpl public interface
@protocol MContainer <NSObject>

@required
@property(nonatomic) NSUInteger originatingStationID;
@property(nonatomic) NSUInteger sequenceNumber;

/// B.11 detectionTime
/// Time at which the event is detected by the originating ITS-S. For the DENM repetition, this DE shall remain unchanged.
@property(nonatomic) NSDate* detectionTime;

/// B.37 referenceTime
/// This DE refers to the time at which a new DENM, an update DENM or a cancellation DENM is generated.
@property(nonatomic) NSDate* referenceTime;

@property(nonatomic) TerminationKind termination;
@property(nonatomic) CLLocationDegrees latitude;
@property(nonatomic) CLLocationDegrees longitude;

@property(nonatomic) NSInteger semiMajorConfidence;
@property(nonatomic) NSInteger semiMinorConfidence;
@property(nonatomic) V2XHeadingValue semiMajorOrientation;

@property(nonatomic) CLLocationDistance altitudeValue;
@property(nonatomic) V2XAltitudeConfidence altitudeConfidence;

@property(nonatomic) StationKind stationType;

/// Duration (in seconds) of a traffic event validity.
@property(nonatomic) NSUInteger validityDuration;

/// Time interval (in milliseconds) between two consecutive message transmissions.
@property(nonatomic) NSUInteger transmissionInterval;
@property(nonatomic) RelevanceDistanceKind relevanceDistance;
@property(nonatomic) RelevanceTrafficDirectionKind relevanceTrafficDirection;

@end

@interface ManagementContainerImpl : NSObject<MContainer, InitializableWithPointer, PublicPointer, UPERCodable>

@end

NS_ASSUME_NONNULL_END

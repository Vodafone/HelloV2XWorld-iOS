//
//  DENMImpl.h
//  VodafoneV2X
//
//  Created by Gonçalo Martins on 06/09/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "ManagementContainerImpl.h"
#import "SituationContainerImpl.h"
#import "LocationContainerImpl.h"
#import "CommonEnums.h"

NS_ASSUME_NONNULL_BEGIN

@protocol DENMProtocol <InitializableWithPointer, PublicPointer, UPERCodable, MContainer, SContainer, LContainer>

@required
@property(readonly) ManagementContainerImpl* managementContainer;
@property(readonly, nullable) SituationContainerImpl* situationContainer;
@property(readonly, nullable) LocationContainerImpl* locationContainer;

// ItsPduHeader
@property(readonly) NSUInteger stationID;
@property(readonly) ProtocolVersion protocolVersion;
@property(readonly) MessageID messageID;

/// This is the place where the CLLocation received from GNSSReceiver should be injected to configure automatically all internal CAM properties
/// @param location location object retreived from GPS receiver
/// @param heading CLHeading retreived from GPS receiver
- (void)locationSource:(CLLocation*)location heading:(nullable CLHeading *)heading;
- (void)appendPathHistoryPoints:(NSArray<CLLocation*> *)locations andLocation:(CLLocationCoordinate2D) coordinate;
- (void)appendPathTracesPoints:(NSArray<CLLocation*> *)locations andLocation:(CLLocationCoordinate2D) coordinate;
@end

@interface DENMImpl: NSObject<DENMProtocol>

@property(nonatomic) NSUInteger stationID;
@property(nonatomic) ProtocolVersion protocolVersion;
@property(nonatomic) MessageID messageID;

// MARK: MContainer protocol
@property(nonatomic) NSUInteger originatingStationID;
@property(nonatomic) NSUInteger sequenceNumber;
@property(nonatomic) NSDate* detectionTime;
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
@property(nonatomic) NSUInteger validityDuration;
@property(nonatomic) NSUInteger transmissionInterval;
@property(nonatomic) RelevanceDistanceKind relevanceDistance;
@property(nonatomic) RelevanceTrafficDirectionKind relevanceTrafficDirection;

// MARK: SContainer protocol
@property(nonatomic) InformationQualityKind informationQuality;
@property(nonatomic) CauseCodeKind eventCauseCode;
@property(nonatomic) NSUInteger eventSubCauseCode;
@property(nonatomic) CauseCodeKind linkedCauseCode;
@property(nonatomic) NSUInteger linkedSubCauseCode;
@property(nonatomic) NSArray<id<EventPointPublic>> *eventHistoryList;
@property(nonatomic) NSArray<id<PathPointPublic>> *tracesList;

// MARK: LContainer protocol
@property(nonatomic) V2XSpeedConfidence speedConfidence;
@property(nonatomic) CLLocationSpeed speedValue;
@property(nonatomic) V2XHeadingConfidence headingConfidence;
@property(nonatomic) CLLocationDirection headingValue;
@property(nonatomic) RoadKind roadType;

@end

NS_ASSUME_NONNULL_END

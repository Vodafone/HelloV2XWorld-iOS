//
//  LocationContainerImpl.h
//  VodafoneV2X
//
//  Created by Gonçalo Martins on 07/09/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "HighFrequencyContainerImpl.h"
#import "BasicContainerImpl.h"
#import "PathPointImpl.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, RoadKind) {
    RoadKindUrbanNoStructuralSeparationToOppositeLanes    = 0,
    RoadKindUrbanWithStructuralSeparationToOppositeLanes    = 1,
    RoadKindNonUrbanNoStructuralSeparationToOppositeLanes    = 2,
    RoadKindNonUrbanWithStructuralSeparationToOppositeLanes    = 3,
    RoadKindUnknown    = NSIntegerMax
};


typedef NS_ENUM(NSInteger, SpeedValueKind) {
    SpeedValueKindStandstill    = 0,
    SpeedValueKindOneCentimeterPerSec    = 1,
    SpeedValueKindUnavailable    = 16383
};

// MARK: LocationContainerImpl public interface
@protocol LContainer <NSObject>

@required
@property(nonatomic) V2XSpeedConfidence speedConfidence;
@property(nonatomic) CLLocationSpeed speedValue;
@property(nonatomic) V2XHeadingConfidence headingConfidence;
@property(nonatomic) CLLocationDirection headingValue;
@property(nonatomic) RoadKind roadType;
@property(nonatomic) NSArray<id<PathPointPublic>> *traces;
@end

@interface LocationContainerImpl : NSObject<LContainer, InitializableWithPointer, PublicPointer, UPERCodable>
-(void)appendTracesList:(NSArray<id<PathPointPublic>> *)traces;
@end

NS_ASSUME_NONNULL_END

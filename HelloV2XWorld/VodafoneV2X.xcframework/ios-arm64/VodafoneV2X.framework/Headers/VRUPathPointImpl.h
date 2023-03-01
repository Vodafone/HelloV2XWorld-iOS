//
//  VRUPathPointImpl.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 25/03/2022.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"

NS_ASSUME_NONNULL_BEGIN

@protocol VRUPathPoint <NSObject, InitializableWithPointer, PublicPointer, UPERCodable>

@required
@property(nonatomic) NSUInteger pathDeltaTime;
@property(nonatomic) CLLocationDegrees latitude;
@property(nonatomic) CLLocationDegrees longitude;

@property(nonatomic) CLLocationDistance altitudeValue;
@property(nonatomic) V2XAltitudeConfidence altitudeConfidence;

@property(nonatomic) NSUInteger semiMajorConfidence;
@property(nonatomic) NSUInteger semiMinorConfidence;
@property(nonatomic) NSUInteger semiMajorOrientation;

@end

@interface VRUPathPointImpl : NSObject <VRUPathPoint>

@end

NS_ASSUME_NONNULL_END

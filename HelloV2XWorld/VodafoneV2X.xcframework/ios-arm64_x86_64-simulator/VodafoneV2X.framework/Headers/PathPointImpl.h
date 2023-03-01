//
//  PathPointImpl.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 19/07/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PathPointPublic <NSObject, InitializableWithPointer, PublicPointer, UPERCodable>

@required
@property(nonatomic) CLLocationDegrees deltaLatitude;
@property(nonatomic) CLLocationDegrees deltaLongitude;
@property(nonatomic) CLLocationDistance deltaAltitude;

// if not set the value returned will be NSIntegerMin
@property(nonatomic) NSInteger pathDeltaTime;

@end

@interface PathPointImpl : NSObject <PathPointPublic>

@end

NS_ASSUME_NONNULL_END

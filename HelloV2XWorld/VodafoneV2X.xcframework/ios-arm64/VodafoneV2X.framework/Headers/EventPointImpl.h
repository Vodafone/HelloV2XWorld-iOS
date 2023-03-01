//
//  EventPointImpl.h
//  VodafoneV2X
//
//  Created by Ahmed Hamdy on 16/11/2022.
//
#import <Foundation/Foundation.h>
#import "CodingProtocols.h"

NS_ASSUME_NONNULL_BEGIN

@protocol EventPointPublic <NSObject, InitializableWithPointer, PublicPointer, UPERCodable>

@required
@property(nonatomic) CLLocationDegrees deltaLatitude;
@property(nonatomic) CLLocationDegrees deltaLongitude;
@property(nonatomic) CLLocationDistance deltaAltitude;

// if not set the value returned will be NSIntegerMin
@property(nonatomic) NSInteger eventDeltaTime;

@end

@interface EventPointImpl : NSObject <EventPointPublic>

@end

NS_ASSUME_NONNULL_END

//
//  AbsolutePositionImpl.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 21/12/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"

NS_ASSUME_NONNULL_BEGIN

@protocol AbsolutePosition <NSObject, InitializableWithPointer, PublicPointer, UPERCodable>

@property(readonly) CLLocationDegrees latitude;
@property(readonly) CLLocationDegrees longitude;

@end

@interface AbsolutePositionImpl : NSObject<AbsolutePosition>

@property(nonatomic) CLLocationDegrees latitude;
@property(nonatomic) CLLocationDegrees longitude;

@end

NS_ASSUME_NONNULL_END

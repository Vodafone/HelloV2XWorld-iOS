//
//  IVIContainersImpl.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 10/12/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "GLCImpl.h"
#import "GICPartImpl.h"

NS_ASSUME_NONNULL_BEGIN

@protocol IVIContainer <NSObject, InitializableWithPointer, PublicPointer, UPERDecodable>
@end

@protocol IVIContainers <NSObject, InitializableWithPointer, PublicPointer, UPERDecodable>

@property(readonly) NSArray<id<GeographicLocationContainer>> *glc;
@property(readonly) NSArray<id<GICPart>> *giv;

@end

@interface IVIContainersImpl : NSObject<IVIContainers>

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

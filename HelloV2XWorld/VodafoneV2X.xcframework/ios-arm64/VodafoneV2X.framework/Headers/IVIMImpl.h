//
//  IVIMImpl.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 07/12/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "CommonEnums.h"

NS_ASSUME_NONNULL_BEGIN

@protocol IVIManagementContainer;
@protocol IVIContainers;

@protocol IVIM <NSObject, InitializableWithPointer, PublicPointer, UPERDecodable>
/// Station ID
@property(readonly) NSUInteger stationID;

@property(readonly) id<IVIManagementContainer> mandatory;
@property(readonly, nullable) id<IVIContainers> optional;

@end

@interface IVIMImpl : NSObject<IVIM>

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

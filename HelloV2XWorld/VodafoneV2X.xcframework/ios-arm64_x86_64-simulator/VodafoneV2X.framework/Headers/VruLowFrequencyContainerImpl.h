//
//  VruLowFrequencyContainerImpl.h
//  VodafoneV2X
//
//  Created by Ahmed Hamdy on 20/03/2022.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "CommonEnums.h"

NS_ASSUME_NONNULL_BEGIN

@protocol VruLowFrequencyContainer <NSObject>
@property(readonly) NSInteger vruProfileIndex;
@property(readonly) NSInteger vruSubProfileIndex;
@property(nonatomic) V2XMappedProfile profileAndSubprofile;

@end

@interface VruLowFrequencyContainerImpl : NSObject<VruLowFrequencyContainer, InitializableWithPointer, PublicPointer, UPERCodable>

@end

NS_ASSUME_NONNULL_END

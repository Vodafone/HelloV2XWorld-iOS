//
//  VruHighFrequencyContainer.h
//  VodafoneV2X
//
//  Created by Ahmed Hamdy on 17/03/2022.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"

NS_ASSUME_NONNULL_BEGIN

@protocol VruHighFrequencyContainer <NSObject>
@property(nonatomic) CLLocationSpeed speedValue;
@property(nonatomic) CLLocationDirection headingValue;
@property(nonatomic) V2XHeadingConfidence headingConfidence;
@property(nonatomic) V2XSpeedConfidence speedConfidence;
@end


@interface VruHighFrequencyContainerImpl : NSObject<VruHighFrequencyContainer, InitializableWithPointer, PublicPointer, UPERCodable>

@end

NS_ASSUME_NONNULL_END


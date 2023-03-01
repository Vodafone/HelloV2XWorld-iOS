//
//  BTPBProtocol.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 03/12/2021.
//

#import <Foundation/Foundation.h>
#import "CommonEnums.h"

NS_ASSUME_NONNULL_BEGIN

@protocol BTPBProtocol <NSObject>

@required
@property(readonly) V2XDestPort destinationPort;
@property(readonly) NSInteger destinationPortInfo;

@end

NS_ASSUME_NONNULL_END

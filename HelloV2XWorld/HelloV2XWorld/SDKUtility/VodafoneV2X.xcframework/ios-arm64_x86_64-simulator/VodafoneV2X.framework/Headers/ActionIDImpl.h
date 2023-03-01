//
//  ActionIDImpl.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 10/12/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ActionID <NSObject, InitializableWithPointer, PublicPointer, UPERDecodable>

@property(readonly) NSUInteger originatingStationID;
@property(readonly) NSUInteger sequenceNumber;

@end

@interface ActionIDImpl : NSObject<ActionID>

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

//
//  SPATEMImpl.h
//  VodafoneV2X
//
//  Created by Mohamed Elabd on 24/02/2022.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "CommonEnums.h"
#import "IntersectionStateImpl.h"

NS_ASSUME_NONNULL_BEGIN

@protocol SPATEM <NSObject, InitializableWithPointer, PublicPointer, UPERDecodable>

// ItsPduHeader
@property(readonly) NSUInteger stationID;
@property(readonly) ProtocolVersion protocolVersion;
@property(readonly) MessageID messageID;

@property(readonly) NSArray<id<IntersectionState>> *intersections;
@property(readonly) NSUInteger sequenceID;
@end

@interface SPATEMImpl : NSObject<SPATEM>

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

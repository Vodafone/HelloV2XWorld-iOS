//
//  MAPEMImpl.h
//  VodafoneV2X
//
//  Created by Gonçalo Martins on 19/01/2022.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "CommonEnums.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MapData;

@protocol MAPEM <NSObject, InitializableWithPointer, PublicPointer, UPERDecodable>

@property(readonly) NSUInteger stationID;

@property(readonly) ProtocolVersion protocolVersion;

@property(readonly) MessageID messageID;

@property(readonly) id<MapData> map;

@property(readonly) NSUInteger sequenceID;

@end

@interface MAPEMImpl: NSObject<MAPEM>

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

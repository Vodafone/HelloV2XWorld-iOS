//
//  TSBMultiHopHeaderImpl.h
//  VodafoneV2X
//
//  Created by Gonçalo Martins on 01/03/2022.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "BasicHeaderProtocol.h"
#import "CommonHeaderProtocol.h"
#import "LongPosVectorProtocol.h"
#import "BTPBProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TSBMultiHopHeaderProtocol <NSObject, BasicHeaderProtocol, CommonHeaderProtocol, LongPosVectorProtocol, BTPBProtocol>

@required
@property(readonly) NSUInteger sequenceNumber;

@end

@interface TSBMultiHopHeaderImpl: NSObject<ASN1HeaderDecode, InitializableWithPointer, PublicPointer, TSBMultiHopHeaderProtocol>

// CommonHeaderInterface
@property(nonatomic) NSUInteger payloadLength;

// BTPBInterface
@property(nonatomic) V2XDestPort destinationPort;

// TSBMultiHopHeader
@property(nonatomic) NSUInteger sequenceNumber;

@end

NS_ASSUME_NONNULL_END

//
//  CodingProtocols.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 16/07/2021.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "CommonEnums.h"

NS_ASSUME_NONNULL_BEGIN

@protocol InitializableWithPointer <NSObject>

@required
- (nullable instancetype)initWith:(const void *)objectPointer;

@end

@protocol PublicPointer <NSObject>

@required
- (void *)objectPointer;

@end

@protocol ASN1Encode <NSObject>

@required
- (NSData * _Nullable)encoded;

@end

@protocol ASN1Decode <NSObject>

@required
+ (instancetype _Nullable)decodedFrom:(NSData *)data;

@end

@protocol ASN1Codable <ASN1Encode, ASN1Decode>

@end

@protocol ASN1HeaderEncode <ASN1Encode>

@end

@protocol ASN1HeaderDecode <ASN1Decode>

@required
/// Describes the size in bytes of the pointer sent
+ (NSUInteger)encodedLength;

@end

@protocol ASN1Header <ASN1HeaderEncode, ASN1HeaderDecode>

@end

/// This protocol does not represent any type of approach to Swift Codable
/// Only represents that the object itself is able to be UPER encoded.
@protocol UPEREncodable <ASN1Encode>
@end

/// This protocol does not represent any type of approach to Swift Codable
/// Only represents that the object itself is able to be UPER decoded.
@protocol UPERDecodable <ASN1Decode>
@end

/// This protocol allows the object to be UPER encoded and decoded.
@protocol UPERCodable <UPEREncodable, UPERDecodable>
@end

@protocol Randomizable <NSObject>

+ (nullable instancetype)random;

// Data outputed is encoded using UPPER
+ (nullable NSData*)randomData;

@end

@protocol PayloadSizable <NSObject>

+ (nullable NSData*)randomData:(NSInteger)payloadLength
               destinationPort:(V2XDestPort)port;

@end


NS_ASSUME_NONNULL_END

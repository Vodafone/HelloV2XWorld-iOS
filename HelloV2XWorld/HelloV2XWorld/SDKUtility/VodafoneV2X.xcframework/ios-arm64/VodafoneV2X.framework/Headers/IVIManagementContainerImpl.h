//
//  IVIManagementContainerImpl.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 10/12/2021.
//

#import <Foundation/Foundation.h>
#import "CodingProtocols.h"
#import "ActionIDImpl.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, IVIStatus) {
    IVIStatusNew = 0,
    IVIStatusUpdate = 1,
    IVIStatusCancellation = 2,
    IVIStatusNegation = 3
};

@protocol IVIManagementContainer <NSObject, InitializableWithPointer, PublicPointer, UPERDecodable>

@required

@property(readonly) NSString* countryCode;
@property(readonly) NSUInteger providerID;

@property(readonly) NSUInteger iviIdentificationNumber;
@property(readonly) IVIStatus iviStatus;

/// MARK: Optionals
@property(readonly, nullable) NSDate *timeStamp;
@property(readonly, nullable) NSDate *validFrom;
@property(readonly, nullable) NSDate *validTo;

@property(readonly, nullable) NSArray<NSNumber *> *connectedIVIStructures;
@property(readonly, nullable) NSArray<id<ActionID>> *connectedDENMs;

@end

@interface IVIManagementContainerImpl : NSObject<IVIManagementContainer>

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

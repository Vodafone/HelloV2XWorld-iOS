//
//  BasicHeaderProtocol.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 03/12/2021.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, V2XTimeBase) {
    V2XTimeBaseHalfSecond       = 0,
    V2XTimeBaseOneSecond        = 1,
    V2XTimeBaseTenSeconds       = 2,
    V2XTimeBaseHundredSeconds   = 3
};

typedef NS_ENUM(NSUInteger, V2XNextHeader) {
    V2XNextHeaderAny            = 0,
    V2XNextHeaderCommonHeader   = 1,
    V2XNextHeaderSecuredPacket  = 2
};

@protocol BasicHeaderProtocol <NSObject>

@required
@property(readonly) V2XTimeBase timeBase;
@property(readonly) NSInteger multiplier;
@property(readonly) NSInteger version;
@property(readonly) V2XNextHeader nextHeaderAfterBH;
@property(readonly) NSInteger remaingHop;

@end

NS_ASSUME_NONNULL_END

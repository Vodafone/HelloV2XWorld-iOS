//
//  VAMImpl+Randomizer.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 25/03/2022.
//

#import "VAMImpl.h"
#import "CodingProtocols.h"

NS_ASSUME_NONNULL_BEGIN

/// VAMImpl+Randomizer
/// The resulting data will represent a VAM object with correspoding header included
@interface VAMImpl (Randomizer) <Randomizable>

+ (NSData *)VAMFor:(NSArray< id<PathPointPublic> >*)pathHistory vruPathPoints:(NSArray <id<VRUPathPoint>> *)pathPrediction;
+ (nullable NSData *)randomHeader:(long)length;

@end

NS_ASSUME_NONNULL_END

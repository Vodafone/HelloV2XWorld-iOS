//
//  CrossPlatform.h
//  VodafoneV2X
//
//  Created by Nelson Silvestre on 01/04/2022.
//

#ifndef CrossPlatform_h
#define CrossPlatform_h

#define NSLog(args...) NSLogger(__FILE__, __LINE__, __PRETTY_FUNCTION__, args);

#if defined cplusplus
extern "C" {
#endif
    void NSLogger(const char *file, int lineNumber, const char *functionName, NSString *format, ...);
#if defined cplusplus
}
#endif

#if defined(RANDOMIZABLE) || defined(TARGET_OS_MAC)

#import "IVIManagementContainerImpl+Randomizer.h"
#import "IVIContainersImpl+Randomizer.h"
#import "IVIMImpl+Randomizer.h"
#import "GLCImpl+Randomizer.h"
#import "GLCPartImpl+Randomizer.h"
#import "ZoneImpl+Randomizer.h"
#import "SegmentImpl+Randomizer.h"
#import "ComputedSegmentImpl+Randomizer.h"
#import "GICPartImpl+Randomizer.h"
#import "ActionIDImpl+Randomizer.h"
#import "GBCPacketHeaderImpl+Randomizer.h"
#import "TSBMultiHopHeaderImpl+Randomizer.h"
#import "SHBPacketHeaderImpl+Randomizer.h"
#import "MAPEMImpl+Randomizer.h"
#import "VAMImpl+Randomizer.h"
#import "SPATEMImpl+Randomizer.h"
#import "ZoneImpl+Randomizer.h"
#import "SegmentImpl+Randomizer.h"
#import "IVIMImpl+Randomizer.h"
#import "VruHighFrequencyContainerImpl+Randomizer.h"
#import "VruLowFrequencyContainerImpl+Randomizer.h"
#import "VruMotionPredictionContainerImpl+Randomizer.h"

#endif

#endif /* CrossPlatform_h */

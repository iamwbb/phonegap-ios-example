//
//
//  Created by ANDREW GLOVER on 8/30/11.
//  Copyright 2011 App47 All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PhoneGap/PGPlugin.h>

@interface App47PGPlugin : PGPlugin
 
- (void) sendGenericEvent:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void) startTimedEvent:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void) endTimedEvent:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void) log:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void) configurationValue:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;

@end

//
//  App47Event.h
//  Gravy
//
//  Created by ANDREW GLOVER on 8/30/11.
//  Copyright 2011 Beacon50. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PhoneGap/PGPlugin.h>

@interface App47Event : PGPlugin {
    NSString* callbackID; 
}

@property (nonatomic, copy) NSString* callbackID;

//Instance Method  
- (void) sendGenericEvent:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;


@end

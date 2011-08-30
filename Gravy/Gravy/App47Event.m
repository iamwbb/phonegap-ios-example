//
//  App47Event.m
//  Gravy
//
//  Created by ANDREW GLOVER on 8/30/11.
//  Copyright 2011 Beacon50. All rights reserved.
//

#import "App47Event.h"
#import "EmbeddedAgent.h"

@implementation App47Event

@synthesize callbackID;

-(void)sendGenericEvent:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options  
{
    self.callbackID = [arguments pop];
    
    //Get the string that javascript sent
    NSString *eventName = [arguments objectAtIndex:0]; 
    
    //do try catch here? if failure, send back callback that indicates so
    [EmbeddedAgent sendGenericEvent:eventName];
    
    NSMutableString *stringToReturn = [NSMutableString stringWithString: @"StringReceived:"];

    //Append the received string to the string we plan to send out        
    [stringToReturn appendString: eventName];
    
    //Create Plugin Result
    PluginResult* pluginResult = [PluginResult resultWithStatus:PGCommandStatus_OK messageAsString: 
                    [stringToReturn stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]];

    [self writeJavascript: [pluginResult toSuccessCallbackString:self.callbackID]]; 
}

- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}

- (void)dealloc
{
    [super dealloc];
}

@end

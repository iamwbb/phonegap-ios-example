//
//  App47Event.m
//  Gravy
//
//  Created by ANDREW GLOVER on 8/30/11.
//  Copyright 2011 Beacon50. All rights reserved.
//

#import "App47PGPlugin.h"
#import "EmbeddedAgent.h"

#ifdef PHONEGAP_FRAMEWORK
  #import <PhoneGap/PluginResult.h>
#else
  #import "PluginResult.h"
#endif

@interface App47PGPlugin()

+ (PluginResult*) getPlugInResult: (NSString*) stringToReturn;

@end

@implementation App47PGPlugin

-(void)sendGenericEvent:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options  
{

    NSString* callbackID = [arguments pop];
    
    //Get the string that javascript sent
    NSString *eventName = [arguments objectAtIndex:0]; 
    
    //do try catch here? if failure, send back callback that indicates so
    [EmbeddedAgent sendGenericEvent:eventName];
    
    NSMutableString *stringToReturn = [NSMutableString stringWithString: @"StringReceived:"];

    //Append the received string to the string we plan to send out        
    [stringToReturn appendString: eventName];
        
//    PluginResult* pluginResult = (PluginResult *)[App47Event getPlugInResult:stringToReturn];
    
    //Create Plugin Result
    PluginResult* pluginResult = [PluginResult resultWithStatus:PGCommandStatus_OK messageAsString: 
                                  [stringToReturn stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]];

  
    [self writeJavascript: [pluginResult toSuccessCallbackString:callbackID]];
}

- (void)startTimedEvent:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options
{
    NSLog(@"startTimedEvent called!");
    
    NSString* callbackID = [arguments pop];
    
    //Get the string that javascript sent
    NSString *eventName = [arguments objectAtIndex:0]; 
    
    
    NSLog(@"event name = %@", eventName);
    //do try catch here? if failure, send back callback that indicates so
    NSString *eventID = [EmbeddedAgent startTimedEvent:eventName];
    
    NSLog(@"event id = %@", eventID);
    
    //Create Plugin Result
    PluginResult* pluginResult = [PluginResult resultWithStatus:PGCommandStatus_OK messageAsString: 
                                  [eventID stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]];
//    PluginResult* pluginResult = (PluginResult *)[App47Event getPlugInResult:eventID];
     
    [self writeJavascript: [pluginResult toSuccessCallbackString:callbackID]]; 
    
}
- (void) endTimedEvent:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options
{
    NSString* callbackID = [arguments pop];
    
    //Get the string that javascript sent
    NSString *eventName = [arguments objectAtIndex:0]; 
    
    NSLog(@"END TIMED event id = %@", eventName);
    
    [EmbeddedAgent endTimedEvent:eventName];
    
    NSMutableString *stringToReturn = [NSMutableString stringWithString: @"StringReceived:"];
    //Append the received string to the string we plan to send out        
    [stringToReturn appendString: eventName];
        
//    PluginResult* pluginResult = [PluginResult resultWithStatus:PGCommandStatus_OK messageAsString: 
//                                  [stringToReturn stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]];
    
    PluginResult* pluginResult = (PluginResult *)[App47PGPlugin getPlugInResult:stringToReturn];
    
    [self writeJavascript: [pluginResult toSuccessCallbackString:callbackID]]; 
}

//
+ (PluginResult*) getPlugInResult: (NSString*) stringToReturn 
{
    return [PluginResult resultWithStatus:PGCommandStatus_OK messageAsString: 
            [stringToReturn stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]];
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

//
//  Created by ANDREW GLOVER on 8/30/11.
//  Copyright 2011 App47 All rights reserved.
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
+ (PluginResult*) getPlugInErrorResult: (NSException*) exception;

@end

@implementation App47PGPlugin


- (void) log:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options
{
    NSString* callbackID = [arguments pop];
    @try 
    {
            
        NSString* logType = [options objectForKey:@"type"];
        if([logType isEqualToString:@"info"])
        {
           EALogInfo(@"%@",[options objectForKey:@"msg"]); 
        }
        else if([logType isEqualToString:@"warn"])
        {
            EALogWarn(@"%@",[options objectForKey:@"msg"]);
        }
        else if([logType isEqualToString:@"error"])
        {
            EALogError(@"%@",[options objectForKey:@"msg"]);
        }
        else //must be debug
        {
            EALogDebug(@"%@",[options objectForKey:@"msg"]); 
        }

        [self writeJavascript: [(PluginResult *)[App47PGPlugin getPlugInResult:@"success"] 
                                toSuccessCallbackString:callbackID]];
    }
    @catch (NSException *ex) 
    {
        [self writeJavascript: [(PluginResult *)[App47PGPlugin getPlugInErrorResult:ex] 
                                toErrorCallbackString:callbackID]];
    }
}

-(void)sendGenericEvent:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options  
{
    NSString* callbackID = [arguments pop];
    @try 
    {
      
      NSString *eventName = [arguments objectAtIndex:0]; 
      [EmbeddedAgent sendGenericEvent:eventName];
      [self writeJavascript: [(PluginResult *)[App47PGPlugin getPlugInResult:eventName] 
                              toSuccessCallbackString:callbackID]];
    }
    @catch (NSException *ex) 
    {
        [self writeJavascript: [(PluginResult *)[App47PGPlugin getPlugInErrorResult:ex] 
                                toErrorCallbackString:callbackID]];
    }
}

- (void)startTimedEvent:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options
{
    NSString* callbackID = [arguments pop];    
    @try 
    {
        NSString *eventName = [arguments objectAtIndex:0]; 
        NSString *eventID = [EmbeddedAgent startTimedEvent:eventName];
        [self writeJavascript: [(PluginResult *)[App47PGPlugin getPlugInResult:eventID] 
                              toSuccessCallbackString:callbackID]]; 
    }
    @catch (NSException *ex) 
    {
        [self writeJavascript: [(PluginResult *)[App47PGPlugin getPlugInErrorResult:ex] 
                                toErrorCallbackString:callbackID]];   
    }
    
}
- (void) endTimedEvent:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options
{
    NSString* callbackID = [arguments pop];
    @try 
    {
        NSString *eventName = [arguments objectAtIndex:0]; 
        [EmbeddedAgent endTimedEvent:eventName];
        [self writeJavascript: [(PluginResult *)[App47PGPlugin getPlugInResult:eventName] 
                                toSuccessCallbackString:callbackID]]; 
    }
    @catch (NSException *ex) 
    {
        [self writeJavascript: [(PluginResult *)[App47PGPlugin getPlugInErrorResult:ex] 
            toErrorCallbackString:callbackID]];    
    }
}


+ (PluginResult*) getPlugInResult: (NSString*) stringToReturn 
{
    return [PluginResult resultWithStatus:PGCommandStatus_OK messageAsString: 
            [stringToReturn stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]];
}

+ (PluginResult*) getPlugInErrorResult: (NSException*) exception
{
    return [PluginResult resultWithStatus:PGCommandStatus_ERROR messageAsString:[exception name]];
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
    
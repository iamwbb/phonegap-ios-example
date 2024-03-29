//
//  EmbeddedAgent.h
//
//  Copyright 2011 FoKL. All rights reserved.
//



@interface EmbeddedAgent : NSObject {
  
}

//////////////////////////////////////////////////////////////////
// Use one of the three following methods to startup the agent with the appID given on the web site. 
// 
// Insert the following line into your application:didFinishLaunchingWithOptions:launchOptions
//
//- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {    
//  
//  [AgentService configureAgentWithAppID:@"4d3610c21a78a943ea000001"];
//  // OR, assuming you have a an "EmbeddedAgentSettings.plist" file included in your project.
//  [AgentService configureAgent];
//  // OR, use a settings file with your own file name.
//  [AgentService configureAgentWithSettingsFilePath:mySettingsFilePath];
//  
//   ....
//
//  Finish app setup
//
//  return YES;
//}
//
// Use configureAgentWithAppID to configure the agent with the app id given on the web site and 
// all default settings for the embedded agent. 
// See http://www.appmetrics.com/kb/embeddedagent/default_settings.html for more information.

+ (void) configureAgentWithAppID:(NSString *) appID;

// Use configureAgentWithSettingsFilePath to load the fully qualified file path (plist file) 
// containing all default agent settings, including the app id.
+ (void) configureAgentWithSettingsFilePath:(NSString *) filePath;

// Use configureAgent to load the default settings file named EmbeddedAgentSettings.plist located
// in the application main bundle.
+ (void) configureAgent;

// Use the following methods to send generic events to the service, these will be found 
// in your "Events" tab for the App and will be broken out by name.
+ (void) sendGenericEvent:(NSString *) name;
+ (void) sendGenericEvent:(NSString *) name tags:(NSArray *) tags;

//////////////////////////////////////////////////////////////////
// Timed events allow you to keep track of significant events in your app and how long they take.
// This may be a transcation, download time, or any other performance attribute you want to 
// measure. Each timed event is identified by a name you give it. This name will be used for 
// report aggeration on the service platform.
//
// Along with each timed event you can pass in additional tags with the event both at the start of
// the event as well as the end of the event. In both cases they are optionals and the two lists 
// will be merged together when sent to the server. Tags must be an NSArray of NSStrings.
//
// In addition to tags, you may pass in a collection of key/value pairs using the userInfo parameter.
// All keys and values must be NSStrings.
// 
// When creating a timed event you must give it at least a name, tags and userInfo are optional. The 
// return of startTimedEvent: is a UUID in a NSString object that will later be used to end the timed
// event.
+ (NSString *) startTimedEvent:(NSString *)name;
+ (NSString *) startTimedEvent:(NSString *)name tags:(NSArray *)tags;
+ (NSString *) startTimedEvent:(NSString *)name userInfo:(NSDictionary *)userInfo;
+ (NSString *) startTimedEvent:(NSString *)name tags:(NSArray *)tags userInfo:(NSDictionary *)userInfo;

// To end a timed event, pass the uuid received when creating the event using one of the methods below.
// If additional tags or userInfo dictionaries are passed in when ending an event, the lists/dictionaries
// will be merged and any duplicates removed. In the case of the userInfo NSDictionary, any duplicate
// keys will override current values passed in when creating the timed event.
+ (void) endTimedEvent:(NSString *)uuid;
+ (void) endTimedEvent:(NSString *)uuid tags:(NSArray *)tags;
+ (void) endTimedEvent:(NSString *)uuid userInfo:(NSDictionary *)userInfo;
+ (void) endTimedEvent:(NSString *)uuid tags:(NSArray *)tags userInfo:(NSDictionary *)userInfo;

//////////////////////////////////////////////////////////////////
// Configuration 
+ (NSArray *) allKeysForConfigurationGroup:(NSString *) groupName;
+ (NSArray *) configurationGroupNames;

+ (NSString *) configurationStringForKey:(NSString *) key group:(NSString *)group;
+ (NSString *) configurationStringForKey:(NSString *) key group:(NSString *)group defaultValue:(NSString *)defaultValue;

+ (NSNumber *) configurationNumberForKey:(NSString *) key group:(NSString *)group;
+ (NSNumber *) configurationNumberForKey:(NSString *) key group:(NSString *)group defaultValue:(NSNumber *)defaultValue;

+ (NSDate *) configurationDateForKey:(NSString *) key group:(NSString *)group;
+ (NSDate *) configurationDateForKey:(NSString *) key group:(NSString *)group defaultValue:(NSDate *)defaultValue;

+ (BOOL) configurationBoolForKey:(NSString *) key group:(NSString *)group;
+ (BOOL) configurationBoolForKey:(NSString *) key group:(NSString *)group defaultValue:(BOOL)defaultValue;

+ (id) configurationObjectForKey:(NSString *) key group:(NSString *)group;
+ (id) configurationObjectForKey:(NSString *) key group:(NSString *)group defaultValue:(id)defaultValue;


//////////////////////////////////////////////////////////////////
// Logging.


+ (void) logMessage:(NSString *) message 
           fileName:(NSString *) fileName 
         lineNumber:(int)lineNumber 
              level:(NSString *)level
          error:(NSError *) error 
          exception:(NSException *) exception 
               tags:(NSArray *)tags;

#define EALogDebug( format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"debug" error:nil exception:nil tags:nil]
#define EALogDebugWithException(e,  format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"debug" error:nil exception:e tags:nil]
#define EALogDebugWithError(err, format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"debug" error:err exception:nil tags:nil]
#define EALogDebugWithTags( arrayOfTags,format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"debug" error:nil exception:nil tags:arrayOfTags]
#define EALogDebugWithTagsException(e, arrayOfTags, format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"debug" error:nil exception:e tags:nil]
#define EALogDebugWithTagsError(err, arrayOfTags, format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"debug" error:err exception:nil tags:nil]


#define EALogInfo( format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"info"  error:nil exception:nil tags:nil]
#define EALogInfoWithException(e,  format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"info" error:nil exception:e tags:nil]
#define EALogInfoWithError(err, format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"info" error:err exception:nil tags:nil]
#define EALogInfoWithTags( arrayOfTags,format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"info" error:nil exception:nil  tags:arrayOfTags]
#define EALogInfoWithTagsException(e, arrayOfTags, format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"info" error:nil exception:e tags:nil]
#define EALogInfoWithTagsError(err, arrayOfTags, format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"info" error:err exception:nil tags:nil]

#define EALogWarn( format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"warn"  error:nil exception:nil tags:nil]
#define EALogWarnWithException(e,  format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"warn" error:nil exception:e tags:nil]
#define EALogWarnWithError(err, format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"warn" error:err exception:nil tags:nil]
#define EALogWarnWithTags( arrayOfTags,format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"warn" error:nil exception:nil tags:arrayOfTags]
#define EALogWarnWithTagsException(e, arrayOfTags, format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"warn" error:nil exception:e tags:nil]
#define EALogWarnWithTagsError(err, arrayOfTags, format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"warn" error:err exception:nil tags:nil]


#define EALogError( format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"error" error:nil exception:nil  tags:nil]
#define EALogErrorWithException(ex, format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"error" error:nil exception:ex  tags:nil]
#define EALogErrorWithError(err, format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"error" error:err exception:nil  tags:nil]
#define EALogErrorWithTags( arrayOfTags,format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"error" error:nil exception:nil tags:arrayOfTags]
#define EALogErrorWithTagsError(err, tags,format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"error" error:err exception:nil tags:tags]
#define EALogErrorWithTagsException(ex, arrayOfTags,format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"error" error:nil exception:ex tags:arrayOfTags]

#define EALogCrashException(ex, format, ... ) [EmbeddedAgent logMessage:[NSString stringWithFormat:(format), ##__VA_ARGS__] fileName:[[NSString stringWithUTF8String:__FILE__] lastPathComponent] lineNumber:__LINE__ level:@"crash" error:nil exception:ex  tags:nil]

@end

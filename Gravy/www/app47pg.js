/**
  
 App47 Plugin for PhoneGap.
   Created by the team @ App47, Inc.

  1. Include the App47 SDK files in Xcode (follow instructions from App47 documentation)
  2. Put App47PGPlugin.h and App47PGPlugin.m into PhoneGap Plugins/ directory 
  3. Add app47pg.js into the www/ folder, and reference it in a script tag *after* phonegap.js
  4. In PhoneGap.plist (found in Supporting Files/ folder), under the 'Plugins' key, add "com.app47.sdk" w/value "App47PGPlugin"

  The plugin's JavaScript functions are under the global "window.plugins.app47" object. 
  See <sample project> for Plugin usage in sample iOS project.
 
 */

if (!PhoneGap.hasResource("App47")) {
	PhoneGap.addResource("App47");

    App47 = function() {
        this.serviceName = "com.app47.sdk";
    };         
    
    App47.prototype.sendGenericEvent = function(message, success, fail) {
        return PhoneGap.exec(success, fail, this.serviceName, "sendGenericEvent", message);
    };
    
    App47.prototype.startTimedEvent = function(name, success, fail) {
        return PhoneGap.exec(success, fail, this.serviceName, "startTimedEvent", name);
    };
    
    App47.prototype.endTimedEvent = function(name, success, fail) {
        return PhoneGap.exec(success, fail, this.serviceName, "endTimedEvent", name);
    };
    
    App47.prototype.debug = function(message, success, fail) {
        return PhoneGap.exec(success, fail, this.serviceName, "log", [{type:"debug", msg:message}]);
    };
    
    App47.prototype.info = function(message, success, fail) {
        return PhoneGap.exec(success, fail, this.serviceName, "log", [{type:"info", msg:message}]);
    };
    
    App47.prototype.warn = function(message, success, fail) {
        return PhoneGap.exec(success, fail, this.serviceName, "log", [{type:"warn", msg:message}]);
    };
    
    App47.prototype.error = function(message, success, fail) {
        return PhoneGap.exec(success, fail, this.serviceName, "log", [{type:"error", msg:message}]);
    };
    
    App47.prototype.getValue = function(grp, ky, success, fail) {
        return PhoneGap.exec(success, fail, this.serviceName, "configurationValue", [{group:grp, key:ky}]);
    };
    
    App47.install = function(){
        if (typeof window.plugins == "undefined") window.plugins = {};
        if (typeof window.plugins.app47 == "undefined") window.plugins.app47 = new App47();
        return window.plugins.app47;
    };
    
    PhoneGap.addConstructor(App47.install);
} 
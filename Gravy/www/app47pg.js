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
    
    App47.install = function(){
        if (typeof window.plugins == "undefined") window.plugins = {};
        if (typeof window.plugins.app47 == "undefined") window.plugins.app47 = new App47();
        return window.plugins.app47;
    };
    
    PhoneGap.addConstructor(App47.install);
} 
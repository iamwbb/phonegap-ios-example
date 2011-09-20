(function($){
 
	var App47Plugin;
	
	$.getScript("phonegap-1.0.0.js", function(){	
                
                
        App47Plugin = function() {
           this.serviceName = "com.app47.sdk";
        };         
                
        App47Plugin.prototype.sendGenericEvent = function(message, success, fail) {
           return PhoneGap.exec(success, fail, this.serviceName, "sendGenericEvent", message);
        };
    
                
                
//	   App47EventPlugin = {
//	     sendGenericEvent: function(message, success, fail) {
//	          return PhoneGap.exec(success, fail, "com.app47.genericevent", "sendGenericEvent", message);
//         };
//                
//        startTimedEvent: function(message, success, fail) {
//          return PhoneGap.exec(success, fail, "com.app47.starttimedevent", "startTimedEvent", message);
//        };
//                
//        endTimedEvent: function(message, success, fail) {
//          return PhoneGap.exec(success, fail, "com.app47.endtimedevent", "endTimedEvent", message);
//        };
//                
//	  };	
	});
	
	$(function(){

	    $("#submit_deal").submit(function(event, info) {
	        var descp = $("input[id=description]", this);
	        var tgs = $("input[id=tags]", this);
	
			descp.blur();
			tgs.blur();

			$.ajax({
			      type: "PUT",
			      url: 'http://ankara.herokuapp.com/',
			      data: JSON.stringify({ deal_description: descp.val() , all_tags: tgs.val() }),
			      contentType: 'application/json', // format of request payload
			      dataType: 'json', // format of the response
			      success: function(msg) { 
					$('#notice').empty();
				    $("#notice").fadeIn(3, function() { 
						$("#notice").append("<ul><li>Deal submitted!</li></ul>");
						$('form :input').val("");	        
						$("#notice").fadeOut(3200);
					});
					App47Plugin.sendGenericEvent(["deal submitted"]);
				  }
			});
			
	        return false;       
	    });

	});
 
})(jQuery);
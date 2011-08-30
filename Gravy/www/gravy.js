(function($){
 
	var App47EventPlugin;
	
	$.getScript("phonegap-1.0.0.js", function(){	
	   App47EventPlugin = {
	     sendGenericEvent: function(message, success, fail) {
	          return PhoneGap.exec(success, fail, "com.app47.genericevent", "sendGenericEvent", message);
	     }
	  };	
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
					App47EventPlugin.sendGenericEvent(["deal submitted"]);
				  }
			});
			
	        return false;       
	    });

	});
 
})(jQuery);
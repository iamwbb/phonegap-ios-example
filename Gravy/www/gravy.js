(function($){
 
 var enpointURL;
 
 $(document).ready(function(){ $(document).bind('deviceready', function(){ onDeviceReady() })});   
 
 function onDeviceReady(){
    //log call, in this case of type info. Other choices include debug, warn, and error.
    window.plugins.app47.info(["app started up"]);
    //runtime configuration, in this case in group PG with a key of endpoint_2
    //the value returned is a string (URL). The use case here is that various 
    //values can be updated/changed without redeploying new instances of an App
    window.plugins.app47.getValue("PG", "endpoint_2", 
        function(result){
          enpointURL = result;
        }, 
        function(error){
          enpointURL =  "http://localhost:8080/";
        });
 }

 $(function(){

    $("#submit_deal").submit(function(event, info) {
        var descp = $("input[id=description]", this);
        var tgs = $("input[id=tags]", this);
                             
        descp.blur();
        tgs.blur();
        
        var timedEventID = 0;
        //starting a timed event -- this returns an ID which is then 
        //used to mark the completion of the event
        window.plugins.app47.startTimedEvent(["deal submission"],  
                    function(result){  timedEventID = result; });
                             
        $.ajax({
              type: "PUT",
              //endpointURL was obtained via App47 SDK configuration value above 
              url: enpointURL, 
              data: JSON.stringify({ deal_description: descp.val() , all_tags: tgs.val() }),
              contentType: 'application/json', 
              dataType: 'json', 
              success: function(msg) { 
                $('#notice').empty();
                $("#notice").fadeIn(3, function() { 
                    $("#notice").append("<ul><li>Deal submitted!</li></ul>");
                    $('form :input').val("");	        
                    $("#notice").fadeOut(3200);
                     
                });
                //generic events have no notion of time -- they are similar to log stmts
                window.plugins.app47.sendGenericEvent(["deal submitted"]);                        
                //end the timed event started above
                window.plugins.app47.endTimedEvent([timedEventID]); 
              }
        });
        return false;       
    });
 });
 
})(jQuery);
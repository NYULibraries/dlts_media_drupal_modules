;(function ($) {
  Drupal.behaviors.dlts_clip = {
    attach: function ( context, settings ) {

      if ( flashembed.isSupported([9, 115]) ) {
    	  
    	var key = '#$623666ca2f667514416';
    	
    	var flowplayer_swf = '/media/sites/all/libraries/flowplayer/flowplayer.commercial-3.2.18.swf' ;
    	
    	var plugins_root = '/media/sites/all/libraries/flowplayer/plugins/flash/' ;
    	
    	var plugins = {
      	      f4m: {
      	        url: plugins_root + "flowplayer.f4m-3.2.10.swf"
      	      },
      	      rtmp: { 
      	        url: plugins_root + "flowplayer.rtmp-3.2.13.swf"
      	      },
      	      controls: { 
      	        url: plugins_root + "flowplayer.controls-3.2.16.swf",
      	        playlist: true
      	      },
      	      bwcheck: {
      	        url: plugins_root + "flowplayer.bwcheck-3.2.13.swf" ,
      	        dynamic: true,
      	        checkOnStart: true,
      	        qos: {
      	          screen: false
      	        },   
      	        serverType: "fms"
      	      }
      	};
    	
    	var clip = {
      	  autoPlay: false,
    	  provider: 'rtmp',
    	  urlResolvers: [ 'f4m' , 'bwcheck' ]
    	};
 
        $.each ( settings.dlts_clip.media, function ( index, media ) {
        	
          console.log ( media['f4m'] )
          
          var player = flowplayer ( media.id , flowplayer_swf, { key : key, plugins : plugins, clip : clip, playlist : [ { url : media['f4m'] } ] } ) ;
          
          player.play() ;
        	
        } ) ;
        
      }
      
    }
  }
})(jQuery);

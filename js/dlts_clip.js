; (function ($) {
  Drupal.behaviors.dlts_clip = {
    attach: function ( context, settings ) {
    	
      var detect = settings.dlts_clip.detect ;
      
      if ( detect.isiOS ) return ;
	
      var player_conf = settings.dlts_clip.player ; 

      var players = { } ;

      var playlists = { } ;

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
      } ;
      
      function clipConf ( stream ) {
        
        var conf = { } ;
        
        conf.scaling = 'fit' ;
        
        conf.provider = 'rtmp' ,
        
        conf.urlResolvers = [ 'f4m' , 'bwcheck' ] ;        	
        
        conf.url = stream.f4m ;
        
        conf.start = stream.start ;
        
        conf.duration = stream.duration ;
        
        return conf ;

      }

     $('.dlts_clip').each ( function ( ) {
    	 
       var conf ;

       var id = $(this).attr('id') ;
       
       var clip = clipConf ( settings.dlts_clip.media[id] ) ;
       
       conf = { id : id , key : player_conf.key , plugins: plugins , clip: clip } ;

       $f ( conf.id, player_conf.url, conf ) ;

     } ) ;
     
     $('.dlts_playlist').each ( function ( ) {
    	 
         var conf = {} ;

         var id = $(this).attr('id') ;
         
         conf.playlist = [] ;
         
         $.each ( settings.dlts_clip.playlists[id] , function ( index, value ) {
           conf.playlist.push ( clipConf ( settings.dlts_clip.media[value] ) ) ;
         } ) ;
         
         conf = { id : id , key : player_conf.key , plugins : plugins , playlist : conf.playlist } ;
         
         $f ( conf.id, player_conf.url, conf ) ;

     } ) ;     
      
    }
  }
})(jQuery);

(function ($, $f) {
  Drupal.behaviors.dlts_interview = {
    attach: function( context, settings ) {	  
	  if ( flashembed.isSupported([9, 115]) ) {	  
        $.each( settings.dlts.interview.streams, function( index, stream ) {
          $f( stream.id, settings.dlts.interview.player.url, {
            key: settings.dlts.interview.player.key || false,
            playlist: stream.playlist || false,
            plugins : settings.dlts.interview.player.plugins || false
          });
	    });
	  } else {
        $('.player.flowplayer').html(settings.dlts.interview.player.flash.errorMessage);
	  }
    }
  };
})(jQuery, flowplayer);
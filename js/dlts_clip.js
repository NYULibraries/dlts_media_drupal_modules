;(function ($) {
  function attach (context, settings) {
    console.log(settings)
    if (window.flowplayer) {
      flowplayer.conf = {
        //key: '#$623666ca2f667514416',
        //logo: "https://flowplayer.com/media/img/mylogo.png",
        share: false
      }
      flowplayer(function (api, root) {
        
        var parent = $(root);
        
        var fsnext = root.querySelector(".fp-next");
        
        var fsprev = root.querySelector(".fp-prev");        
        
        $('.fp-playlist a').click(function () {
          parent.attr({ 
            'data-start': $(this).attr('data-start'),
            'data-duration': $(this).attr('data-duration')
          })
        })
        
        api.bind('error', function (event, api, error) {
          console.log(error.message + ': ' + error.video.url)
          console.log(error)
        })
        
        api.bind('ready', function (elem, api, media) {
          var start = $(elem.currentTarget).attr('data-start')
          // https://github.com/video-dev/hls.js/blob/v0.7.8/doc/API.md
          
          root.querySelector(".fp-controls").appendChild(fsnext);

          root.querySelector(".fp-controls").appendChild(fsprev);          
          
          if (start) {
            api.seek(start)
          }
        })

        
      })
    }
  }
  Drupal.behaviors.dlts_clip = { attach: attach }
})(jQuery);

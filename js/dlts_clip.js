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
        
        var parent = $(root)
        
        var fsnext = parent.find('.fp-next')
        
        var fsprev = parent.find('.fp-prev')
        
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
          var controls = root.querySelector(".fp-controls")
              controls.appendChild(fsnext)
              controls.appendChild(fsprev)       
          if (start) {
            api.seek(start)
          }
        })

        
      })
    }
  }
  Drupal.behaviors.dlts_clip = { attach: attach }
})(jQuery);

;(function ($) {
  function attach (context, settings) {
    if (window.flowplayer) {
      flowplayer(function (api, root) {
        var parent = $(root);
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
          if (start) {
            api.seek(start)
          }
        })
      })
    }
  }
  Drupal.behaviors.dlts_clip = { attach: attach }
})(jQuery);

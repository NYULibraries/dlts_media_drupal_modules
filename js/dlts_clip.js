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
        api.bind('ready', function (elem) {
          var start = $(elem.currentTarget).attr('data-start')
          if (start) {
            api.seek(start)
          }
        })
      })
    }
  }
  Drupal.behaviors.dlts_clip = { attach: attach };
})(jQuery);

;(function ($) {
  function attach (context, settings) {
    return;
    flowplayer(function (api, root) {
      var parent = $(root);
      $('.fp-playlist a').click(function () {
        var start = $(this).attr('data-start');
        var duration = $(this).attr('data-duration');
        parent.attr({ 'data-start': start, 'data-duration': duration });
      });
      api.bind('ready', function (elem) {
        var start = $(elem.currentTarget).attr('data-start');
        if (start) {
          api.seek(start);
        }
      });
    });
  }
  Drupal.behaviors.dlts_clip = { attach: attach };
})(jQuery);

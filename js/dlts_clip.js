;(function ($) {
  function clipConf(stream) {
    return {
      scaling : 'fit',
      provider : 'rtmp',
      urlResolvers : [ 'f4m' , 'bwcheck' ],
      url : stream.f4m,
      start : stream.start,
      duration : stream.duration
    }
  }
  function main(context, settings) {
    var players = {};
    var playlists = {};
    var detect = settings.dlts_clip.detect;
    var player_conf = settings.dlts_clip.player;
    /** @TODO: get this from Drupal vars */
    var plugins_root = '/media/sites/all/libraries/flowplayer/plugins/flash/';
    /** @TODO: get this from Drupal vars */
    var plugins = {
      f4m: {
        url: plugins_root + "flowplayer.f4m-3.2.10.swf"
      },
      rtmp: {
        url: plugins_root + "flowplayer.rtmp-3.2.13.swf"
      },
      controls: {
        url: plugins_root + "flowplayer.controls-3.2.16.swf"
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
    flowplayer(
      function(api, root) {
        var parent = $(root);
        $('.fp-playlist a').click(function() {
          parent.attr({ 'data-start' : $(this).attr('data-start') });
          parent.attr({ 'data-duration' : $(this).attr('data-duration') });
        });
        api.bind("ready", function(elem) {
          console.log('ready');
          var start = $(elem.currentTarget).attr('data-start');
          if (start) {
            api.seek(start);
          }
        });
      }
    );
    if (!detect.isiOS && !detect.isSafari) {
      $('.dlts_clip').each(function() {
        var id = $(this).attr('id');
        var clip = clipConf(settings.dlts_clip.media[id]);
        var conf = {
          id : id,
          key : player_conf.key,
          plugins: plugins,
          clip: clip
        };
        if ($(this).hasClass('audio')) {
          plugins.controls.autoHide = false;
          plugins.controls.fullscreen = false;
        }
        $f(conf.id, player_conf.url, conf);
      });
      
      $('.dlts_playlist').each(function() {
        var id = $(this).attr('id');
        var playlist = [];
        if ($(settings.dlts_clip.playlists).size() > 1) {
          plugins.controls.playlist = true;        
        }
        $.each(settings.dlts_clip.playlists[id], function(index, value) {
          playlist.push(clipConf(settings.dlts_clip.media[value]));
        });
        $f(id, player_conf.url, {
          id : id,
          key : player_conf.key,
          plugins : plugins,
          playlist : playlist,
          clip: { 
            onBeforeBegin: function(clip, info) { 
              console.log('clip about to start')
              console.log(clip)              
              console.log(info)                         
            }
          }
        });

      });
    }
  }
  
  Drupal.behaviors.dlts_clip = { attach: main };
  
})(jQuery);

<?php

function dlts_bitstream_config($form, &$form_state) {

  // dlts_bitstream_available_flowplayer();

  /*
   * Enable/disable plugins
   * http://flowplayer.org/documentation/configuration/
   */

  /*
   * Hiddend value to store the serialized representation of flowplayer default configuration.
   * Do I need this in here? Not safe but works for now.
   */

  $form['dlts_bitstream_globals_flowplayer'] = array('#type' => 'hidden', '#value' => variable_get( 'dlts_bitstream_globals_flowplayer') );

	$form['plugins'] = array(
		'#type' => 'fieldset',
		'#title' => t('Enable/disable flowplayer plugins'),
		'#collapsed' => FALSE,
		'#collapsible' => FALSE,
	);

  $form['plugins']['dlts_bitstream_flowplayer_plugins_audio'] = array(
    '#type' => 'checkbox',
    '#title' => t('Audio'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_audio', FALSE),
  );

	$form['plugins']['dlts_bitstream_flowplayer_plugins_bwcheck'] = array(
		'#type' => 'checkbox',
		'#title' => t('Bandwidth detection'),
		'#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_bwcheck', FALSE ),
	);

	$form['plugins']['dlts_bitstream_flowplayer_plugins_controls'] = array(
		'#type' => 'checkbox',
		'#title' => t('Controlbar'),
		'#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_controls', TRUE),
	);

  $form['plugins']['dlts_bitstream_flowplayer_plugins_rtmp'] = array(
    '#type' => 'checkbox',
    '#title' => t('Streaming RTMP'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_rtmp', FALSE ),
  );

  /*
   * Audio plugin options
   * http://flowplayer.org/plugins/streaming/audio.html
   */

	$form['audio'] = array(
	  '#type' => 'fieldset',
	  '#title' => t('Audio'),
	  '#collapsed' => ( ( variable_get( 'dlts_bitstream_flowplayer_plugins_audio', FALSE) ? 0 : 1 ) ? TRUE : FALSE ),
	  '#collapsible' => TRUE,
	);

  /*
   * Bandwidth Detection plugin options
   * http://flowplayer.org/plugins/streaming/bwcheck.html
   */

	$form['bwcheck'] = array(
		'#type' => 'fieldset',
		'#title' => t('Bandwidth Detection'),
		'#collapsed' => ( ( variable_get( 'dlts_bitstream_flowplayer_plugins_bwcheck', FALSE) ? 0 : 1 ) ? TRUE : FALSE ),
		'#collapsible' => TRUE,
	);

	$form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_bitrateProfileName'] = array(
		'#type' => 'textfield',
		'#title' => t('Bitrate Profile Name'),
		'#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_bwcheck_bitrateProfileName', 'RTMPBitrateProfile' ),
		'#size' => 20,
		'#maxlength' => 100,
		'#description' => t('Used when detected bandwidth values are remembered (see the rememberBitrate setting). This is the name of the Shared Object where the bitrates are saved. You might want to change this if you have different sets of files and you want to keep the detected bandwidths separate for those sets.'),
	);

	$form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_checkOnStart'] = array(  // need to apply: false, if dynamic: true. true if dynamic: false
		'#type' => 'checkbox',
		'#title' => t('Check on Start'),
		'#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_bwcheck_checkOnStart', TRUE ),
		'#description' => t('Set this to true if you want to perform an initial bwcheck with RTMP. This way the playback can be started automatically with a bitrate based on this initial check. Relying completely on bitrate monitoring and dynamic bitrate switching might be a bit slower to adjust to the best bitrate. If you set this to true, make sure your RTMP server has the bwchecker application installed (Wowza does not have it installed by default).'),
	);

	$form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_dynamic'] = array(
		'#type' => 'checkbox',
		'#title' => t('Dynamic'),
		'#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_bwcheck_dynamic', FALSE ),
		'#description' => t('Enables dynamic stream switching (Quality Of Service monitoring) for Adobe Flash Media Server 3 and Wowza Media Server 2.'),
	);

	$form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_dynamicBuffer'] = array(
		'#type' => 'checkbox',
		'#title' => t('Dynamic buffer'),
		'#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_bwcheck_dynamicBuffer', FALSE ),
		'#description' => t('When enabled, this feature will dynamically calculate the best buffer time to suit the available bandwidth.'),
	);

	$form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_live'] = array(
		'#type' => 'checkbox',
		'#title' => t('Live'),
		'#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_bwcheck_live', FALSE ),
		'#description' => t('Set this to true with live streams.'),
	);

	$form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_netConnectionUrl'] = array(
		'#type' => 'textfield',
		'#title' => t('Net Connection Url'),
		'#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_bwcheck_netConnectionUrl', 'rtmp://fmsdev.library.nyu.edu/vod/media/' ),
		'#size' => 50,
		'#maxlength' => 256,
		'#description' => t('The URL used to check the bandwidth. For HTTP-based checking, this should point to a reference file that is loaded as part of the check. The file should reside on the same host as the plugin, or it will require domain context policies for remote loading of the file to prevent sandbox issues. For RTMP this should be a RMTP url pointing to a streaming server.'),
	);

	$form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_rememberBitrate'] = array(
		'#type' => 'checkbox',
		'#title' => t('Remember bitrate'),
		'#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_bwcheck_rememberBitrate', FALSE ),
		'#description' => t('Indicates whether the detected bandwidth should be remembered for the client browser. If true the detection is performed only once per domain and stored on the client browser. If false the detection is done every time a clip starts playing.'),
	);

	$form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_serverType'] = array(
		'#type' => 'select',
		'#title' => t('Server type'),
		'#options' => array('http' => 'HTTP', 'red5' => 'RED5', 'wowza' => 'WOWZA', 'fms' => 'Flash Media Server'),
		'#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_bwcheck_serverType', 'http' ),
		'#description' => t('Identifies the type of server that we will be checking against. Available values are http, red5, wowza, and Flash Media Server (fms).'),
	);

	$form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_switchOnFullscreen'] = array(
		'#type' => 'checkbox',
		'#title' => t('Switch on Fullscreen'),
		'#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_bwcheck_hdButton', FALSE ),
		'#description' => t('Used when dynamic is set to false. Causes a bandwidth check and a switch when entering fullscreen or exiting fullscreen. When dynamic is set to true the plugin is doing QoS monitoring and switching dynamically if needed, also taking care the screen resize that happens with fullscreen mode.'),
	);

  $form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_hdButton'] = array(
    '#type' => 'select',
    '#title' => t('HD Button'),
    '#options' => array('dock' => 'dock', 'controls' => 'controls', 'both' => 'both'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_bwcheck_hdButton', 'controls' ),
    '#description' => t('Should the HD selection button be visible?.'),
  );

  /*
   * Controls plugin options
   * http://flowplayer.org/plugins/flash/controlbar.html
   */

  $form['controls'] = array(
    '#type' => 'fieldset',
    '#title' => t('Controls'),
    '#collapsed' => ( ( variable_get( 'dlts_bitstream_flowplayer_plugins_controls', TRUE) ? 0 : 1 ) ? TRUE : FALSE ),
    '#collapsible' => TRUE,
  );

  $form['controls']['dlts_bitstream_flowplayer_plugins_controls_autoHide'] = array(
    '#type' => 'select',
    '#title' => t('Auto Hiding'),
    '#options' => array('always' => 'always', 'fullscreen' => 'fullscreen', 'never' => 'never'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_controls_autoHide', 'always' ),
    '#description' => t('The controlbar can be made to automatically hide if the user is not actively using the player.'),
  );

  $form['controls']['dlts_bitstream_flowplayer_plugins_controls_play'] = array(
    '#type' => 'checkbox',
    '#title' => t('Play Button'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_controls_play', TRUE ),
    '#description' => t('Should the play/pause button be visible?'),
  );

  $form['controls']['dlts_bitstream_flowplayer_plugins_controls_volume'] = array(
    '#type' => 'checkbox',
    '#title' => t('Volume Control'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_controls_volume', TRUE ),
    '#description' => t('Should the volume control be visible?'),
  );

  $form['controls']['dlts_bitstream_flowplayer_plugins_controls_mute'] = array(
    '#type' => 'checkbox',
    '#title' => t('Mute Button'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_controls_mute', TRUE ),
    '#description' => t('Should the mute button be visible?'),
  );

  $form['controls']['dlts_bitstream_flowplayer_plugins_controls_time'] = array(
    '#type' => 'checkbox',
    '#title' => t('Time'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_controls_time', TRUE ),
    '#description' => t('Should the time display be visible?'),
  );

  $form['controls']['dlts_bitstream_flowplayer_plugins_controls_stop'] = array(
    '#type' => 'checkbox',
    '#title' => t('Stop Button'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_controls_stop', FALSE ),
    '#description' => t('Should the stop button be visible?'),
  );

  $form['controls']['dlts_bitstream_flowplayer_plugins_controls_playlist'] = array(
    '#type' => 'checkbox',
    '#title' => t('Playlist Buttons'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_controls_playlist', FALSE ),
    '#description' => t('Should the playlist buttons be visible? The playlist buttons allow navigation through the playlist entries of the current playlist. These buttons are always hidden if there are less than two entries in the playlist.'),
  );

  $form['controls']['dlts_bitstream_flowplayer_plugins_controls_fastBackward'] = array(
    '#type' => 'checkbox',
    '#title' => t('Fast Backward Button'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_controls_fastBackward', FALSE ),
    '#description' => t('Should the fast backward button be visible? The slow motion buttons allow controlling the playback speed (from 1/8 to 8x the normal speed). These buttons are always hidden if the slowmotion plugin is not loaded, and only available with the "Modern" skin.'),
  );

  $form['controls']['dlts_bitstream_flowplayer_plugins_controls_fastForward'] = array(
    '#type' => 'checkbox',
    '#title' => t('Fast Forward Button'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_controls_fastForward', FALSE ),
    '#description' => t('Should the fast forward button be visible?'),
  );

  /*
   * RTMP plugin options
   * http://flowplayer.org/plugins/streaming/rtmp.html
   */

  $form['rtmp'] = array(
    '#type' => 'fieldset',
    '#title' => t('RTMP Plugin'),
    '#collapsed' => ( ( variable_get( 'dlts_bitstream_flowplayer_plugins_rtmp', FALSE) ? 0 : 1 ) ? TRUE : FALSE ),
    '#collapsible' => TRUE,
  );

  $form['rtmp']['dlts_bitstream_flowplayer_plugins_rtmp_netConnectionUrl'] = array(
    '#type' => 'textfield',
    '#title' => t('FlowPlayer Net Connection URL'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_rtmp_netConnectionUrl', 'rtmp://fmsdev.library.nyu.edu/vod/media/' ),
    '#size' => 50,
    '#maxlength' => 200,
    '#description' => t('The RTMP URL used to connect to the server app. This is optional and you can also specify this in the clip, so that the different clips in the playlist point to different servers.'),
  );

  $form['rtmp']['dlts_bitstream_flowplayer_plugins_rtmp_objectEncoding'] = array(
    '#type' => 'textfield',
    '#title' => t('Object Encoding'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_rtmp_objectEncoding', 3 ),
    '#size' => 50,
    '#maxlength' => 200,
    '#description' => t('The object encoding used with the streaming server. Change this to a value of 0 if you need to communicate to servers released prior to Flash Player 9 (Adobe Flash Media Server 2).'),
  );

  $form['rtmp']['dlts_bitstream_flowplayer_plugins_rtmp_proxyType'] = array(
    '#type' => 'select',
    '#title' => t('Proxy Type'),
    '#options' => array('none' => 'none', 'HTTP' => 'HTTP', 'CONNECT' => 'CONNECT', 'best' => 'best'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_plugins_rtmp_proxyType', 'best' ),
    '#description' => t('The proxyType determines which fallback methods are tried if an initial connection attempt to the server fails. Flowplayer establishes the connection by doing parallel connection attempts using RTMP and RTMPT. The one that succeeds first is used and the other one is discarded - this way the connection is established as fast as possible in firewalled and proxied network environments.'),
  );

	/*
	 * Clips
	 * http://flowplayer.org/documentation/configuration/clips.html
	 */

	$form['clip'] = array(
	  '#type' => 'fieldset',
	  '#title' => t('Clip Settings'),
	  '#collapsed' => FALSE,
	  '#collapsible' => TRUE,
	);

  $form['clip']['dlts_bitstream_flowplayer_clip_accelerated'] = array(
    '#type' => 'checkbox',
    '#title' => t('Accelerated'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_clip_accelerated', FALSE),
    '#description' => t('Flag indicating whether Flash 9 (and above) hardware-accelerated full screen mode should be used.'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_autoBuffering'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto Buffering'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_clip_autoBuffering', FALSE),
    '#description' => t('Flag indicating whether loading of clip into player\'s memory should begin straight away. When this is true and autoPlay is false then the clip will automatically stop at first frame of the video.'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_autoPlay'] = array(
    '#type' => 'checkbox',
    '#title' => t('Autoplay'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_clip_autoPlay', TRUE),
    '#description' => t('Flag indicating whether the player should start playback immediately upon loading.'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_baseUrl'] = array(
    '#type' => 'textfield',
    '#title' => t('Base Url'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_clip_baseUrl', ''),
    '#size' => 50,
    '#maxlength' => 200,
    '#description' => t('The first part of the URL of the video\'s location. This property is prepended in front of the url property (for relative URLs). If not specified, the video file is loaded from the same directory as the enclosing HTML file.'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_bufferLength'] = array(
    '#type' => 'textfield',
    '#title' => t('Buffer Length'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_clip_bufferLength', 3),
    '#size' => 5,
    '#maxlength' => 5,
    '#description' => t('The amount of video data (in seconds) which should be loaded into Flowplayer\'s memory in advance of playback commencing.'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_cuepointMultiplier'] = array(
    '#type' => 'textfield',
    '#title' => t('Cuepoint Multiplier'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_clip_cuepointMultiplier', 1000),
    '#size' => 50,
    '#maxlength' => 200,
    '#description' => t('The times of embedded cuepoints are multiplied by this value before being used. Some encoding tools embed cuepoints in seconds but Flowplayer processes cuepoints in milliseconds. Note that the times are also rounded to the nearest 100 milliseconds. For example, if a file has a cuepoint at 5.535 seconds, the cuepoint is fired at 5500 milliseconds (assuming the default multiplier value of 1000).'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_start'] = array(
    '#type' => 'textfield',
    '#title' => t('Start'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_clip_start', 0 ),
    '#size' => 50,
    '#maxlength' => 200,
    '#description' => t('The time (in seconds) at which playback should commence. This is only supported when you have a streaming server.'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_duration'] = array(
    '#type' => 'textfield',
    '#title' => t('Duration'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_clip_duration', 0 ),
    '#size' => 50,
    '#maxlength' => 200,
    '#description' => t('The time, in seconds and fractions of a second, for which a video clip should be played until playback ceases. This must always be less than or equal to the total length of the clip. Zero means to play the whole clip.'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_fadeInSpeed'] = array(
    '#type' => 'textfield',
    '#title' => t('Fade In Speed'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_clip_fadeInSpeed', 1000 ),
    '#size' => 50,
    '#maxlength' => 200,
    '#description' => t('Time in milliseconds to fade from zero to full opacity upon commencement of video playback.'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_fadeOutSpeed'] = array(
    '#type' => 'textfield',
    '#title' => t('Fade Out Speed'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_clip_fadeOutSpeed', 1000 ),
    '#size' => 50,
    '#maxlength' => 200,
    '#description' => t('Time in milliseconds to fade from full to zero opacity upon completion of video playback.'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_live'] = array(
    '#type' => 'checkbox',
    '#title' => t('Live'),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_clip_live', FALSE),
    '#description' => t('RTMP streaming servers support live streaming, which means that it is possible to setup a video camera or other live video source to stream live video data to Flowplayer. If you have an RTMP server which is providing a live video stream, you should set this property to true.'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_provider'] = array(
    '#type' => 'select',
    '#title' => t('Provider'),
    '#options' => array(
      'http' => 'HTTP',
      'rtmp' => 'RTPM',
    ),
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_clip_provider', 'http' ),
    '#description' => t('Sets a connection provider to be used for clips. Connection providers can be used to create a connection to a streaming server or to a CDN network. The value of this property *should* be the name of a configured plugin.'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_bitrate'] = array(
    '#type' => 'textfield',
    '#title' => t('Clip bitrate'),
    '#size' => 50,
    '#maxlength' => 200,
    '#default_value' => variable_get( 'dlts_bitstream_flowplayer_clip_bitrate', 800 ),
    '#description' => t('The default bitrate for all clips'),
  );

	$form['clip']['dlts_bitstream_flowplayer_clip_scaling'] = array(
		'#type' => 'select',
		'#title' => t('Scaling'),
		'#options' => array(
		  'fit' => 'Fit',
		  'half' => 'Half',
		  'orig' => 'Original',
		  'scale' => 'Scale'
		),
		'#default_value' => variable_get( 'dlts_bitstream_scaling', 'fit' ),
	);

  // field_bitstream
  // Error @ http://ortiz.bobst.nyu.edu/rosie/admin/structure/types/manage/dlts-bitstream-set/fields/field_bitstream
	return system_settings_form($form);
}

/**
 * Form validation
 *
 * Now we add a handler/function to validate the data If not, it displays an error.
 * The value report is $form_state['values'] (see http://drupal.org/node/144132#form-state).
 *
 * Notice the name of the function. It is simply the name of the form
 * followed by '_validate'. This is always the name of the default validation
 * function. An alternate list of validation functions could have been provided
 * in $form['#validate'].
 *
 */

function dlts_bitstream_config_validate($form, &$form_state) {
  $config = $pluins = array();

  /*
   * Flowplayer location
   * Do we want this to be part of the form ? Inform the user the version and support status ?
   */

  $config['player'] = url( libraries_get_path('flowplayer') . '/flowplayer-3.2.7.swf' );

  /*
   * Available Flowplayer plugins (flash). Used to provide the plugin location
   */

  $available_flow_plugins_flash = dlts_bitstream_available_flowplayer_plugins_flash();

  foreach ( $form_state['values'] as $key => $value ) {

    /*
     * Plugins
     */

    if ( preg_match('/dlts_bitstream_flowplayer_plugins_([a-zA-Z]*)_([a-zA-Z]*)$/', $key, $matches )  ) {

      if ( isset( $form_state['values']['dlts_bitstream_flowplayer_plugins_' . $matches[1] ] ) && $form_state['values']['dlts_bitstream_flowplayer_plugins_' . $matches[1]] == TRUE ) {

        /*
         * Plug-ins don't live in the same location as the JS caller, we need to provide the
         * URL parameter for each plugin.
         */

        if ( !isset( $config['plugins'][$matches[1]] ) ) {
      	  $config['plugins'][$matches[1]]['url'] = $available_flow_plugins_flash[$matches[1]];
        }

        /*
         * Config as pair of keys and values:
         *   $matches[1] = plugin name
         *   $matches[2] = plugin parameter
         *   $value = parameter value
         */

      	$config['plugins'][$matches[1]][$matches[2]] = $value;

      }
    }

    /*
     * Clip
     */

    if ( preg_match('/dlts_bitstream_flowplayer_clip_([a-zA-Z]*)$/', $key, $matches )  ) {
      if ( isset( $form_state['values']['dlts_bitstream_flowplayer_clip_' . $matches[1] ] ) && $form_state['values']['dlts_bitstream_flowplayer_clip_' . $matches[1]]  !== '' ) {
        $config['clip'][$matches[1]] = $value;
      }
    }
  }

  $form_state['values']['dlts_bitstream_globals_flowplayer'] = serialize( $config );
}
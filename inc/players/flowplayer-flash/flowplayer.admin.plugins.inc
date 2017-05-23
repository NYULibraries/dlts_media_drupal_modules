<?php

/**
 * Plugins
 */

$form['flowplayer']['plugins'] = array(
		'#type' => 'item',
		'#title' => t('Plugins'),
);

$form['flowplayer']['dlts_bitstream_flowplayer_plugins_audio'] = array(
		'#type' => 'checkbox',
		'#title' => t('Audio'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['audio']['enabled'])) ? $config['flowplayer']['player']['plugins']['audio']['enabled'] : $default['flowplayer']['player']['plugins']['audio']['enabled'],
);

$form['flowplayer']['dlts_bitstream_flowplayer_plugins_bwcheck'] = array(
		'#type' => 'checkbox',
		'#title' => t('Bandwidth detection'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['bwcheck']['enabled'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['enabled'] : $default['flowplayer']['player']['plugins']['bwcheck']['enabled'],
);

$form['flowplayer']['dlts_bitstream_flowplayer_plugins_controls'] = array(
		'#type' => 'checkbox',
		'#title' => t('Controlbar'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['controls']['enabled'])) ? $config['flowplayer']['player']['plugins']['controls']['enabled'] : $default['flowplayer']['player']['plugins']['controls']['enabled'],
);

$form['flowplayer']['dlts_bitstream_flowplayer_plugins_rtmp'] = array(
		'#type' => 'checkbox',
		'#title' => t('Streaming RTMP'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['rtmp']['enabled'])) ? $config['flowplayer']['player']['plugins']['rtmp']['enabled'] : $default['flowplayer']['player']['plugins']['rtmp']['enabled'],
);

/**
 * Audio plugin options
 * http://flowplayer.org/plugins/streaming/audio.html
*/
$form['audio'] = array(
		'#type' => 'fieldset',
		'#title' => t('Audio'),
		'#collapsed' => ( ( ( isset($config['flowplayer']['player']['plugins']['audio']['enabled'])) ? $config['flowplayer']['player']['plugins']['audio']['enabled'] : $default['flowplayer']['player']['plugins']['audio']['enabled'] ? 0 : 1 ) ? TRUE : FALSE ),
		'#collapsible' => TRUE,
);

/**
 * Bandwidth Detection plugin options
 * http://flowplayer.org/plugins/streaming/bwcheck.html
*/
$form['bwcheck'] = array(
		'#type' => 'fieldset',
		'#title' => t('Bandwidth Detection'),
		'#collapsed' => ( ( ( isset($config['flowplayer']['player']['plugins']['bwcheck']['enabled'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['enabled'] : $default['flowplayer']['player']['plugins']['bwcheck']['enabled'] ? 0 : 1 ) ? TRUE : FALSE ),
		'#collapsible' => TRUE,
);

$form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_bitrateProfileName'] = array(
		'#type' => 'textfield',
		'#title' => t('Bitrate Profile Name'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['bwcheck']['bitrateProfileName'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['bitrateProfileName'] : $default['flowplayer']['player']['plugins']['bwcheck']['bitrateProfileName'],
		'#size' => 20,
		'#maxlength' => 100,
		'#description' => t('Used when detected bandwidth values are remembered (see the rememberBitrate setting). This is the name of the Shared Object where the bitrates are saved. You might want to change this if you have different sets of files and you want to keep the detected bandwidths separate for those sets.'),
);

$form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_checkOnStart'] = array(
		'#type' => 'checkbox',
		'#title' => t('Check on Start'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['bwcheck']['checkOnStart'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['checkOnStart'] : $default['flowplayer']['player']['plugins']['bwcheck']['checkOnStart'],
		'#description' => t('Set this to true if you want to perform an initial bwcheck with RTMP. This way the playback can be started automatically with a bitrate based on this initial check. Relying completely on bitrate monitoring and dynamic bitrate switching might be a bit slower to adjust to the best bitrate. If you set this to true, make sure your RTMP server has the bwchecker application installed (Wowza does not have it installed by default).'),
);

$form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_dynamic'] = array(
		'#type' => 'checkbox',
		'#title' => t('Dynamic'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['bwcheck']['dynamic'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['dynamic'] : $default['flowplayer']['player']['plugins']['bwcheck']['dynamic'],
		'#description' => t('Enables dynamic stream switching (Quality Of Service monitoring) for Adobe Flash Media Server 3 and Wowza Media Server 2.'),
);

$form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_dynamicBuffer'] = array(
		'#type' => 'checkbox',
		'#title' => t('Dynamic buffer'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['bwcheck']['dynamicBuffer'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['dynamicBuffer'] : $default['flowplayer']['player']['plugins']['bwcheck']['dynamicBuffer'],
		'#description' => t('When enabled, this feature will dynamically calculate the best buffer time to suit the available bandwidth.'),
);

$form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_live'] = array(
		'#type' => 'checkbox',
		'#title' => t('Live'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['bwcheck']['live'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['live'] : $default['flowplayer']['player']['plugins']['bwcheck']['live'],
		'#description' => t('Set this to true with live streams.'),
);

$form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_netConnectionUrl'] = array(
		'#type' => 'textfield',
		'#title' => t('Net Connection Url'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['bwcheck']['netConnectionUrl'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['netConnectionUrl'] : $default['flowplayer']['player']['plugins']['bwcheck']['netConnectionUrl'],
		'#size' => 50,
		'#maxlength' => 256,
		'#description' => t('The URL used to check the bandwidth. For HTTP-based checking, this should point to a reference file that is loaded as part of the check. The file should reside on the same host as the plugin, or it will require domain context policies for remote loading of the file to prevent sandbox issues. For RTMP this should be a RMTP url pointing to a streaming server.'),
);

$form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_rememberBitrate'] = array(
		'#type' => 'checkbox',
		'#title' => t('Remember bitrate'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['bwcheck']['rememberBitrate'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['rememberBitrate'] : $default['flowplayer']['player']['plugins']['bwcheck']['rememberBitrate'],
		'#description' => t('Indicates whether the detected bandwidth should be remembered for the client browser. If true the detection is performed only once per domain and stored on the client browser. If false the detection is done every time a clip starts playing.'),
);

$form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_serverType'] = array(
		'#type' => 'select',
		'#title' => t('Server type'),
		'#options' => array('http' => 'HTTP', 'red5' => 'RED5', 'wowza' => 'WOWZA', 'fms' => 'Flash Media Server'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['bwcheck']['serverType'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['serverType'] : $default['flowplayer']['player']['plugins']['bwcheck']['serverType'],
		'#description' => t('Identifies the type of server that we will be checking against. Available values are http, red5, wowza, and Flash Media Server (fms).'),
);

$form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_switchOnFullscreen'] = array(
		'#type' => 'checkbox',
		'#title' => t('Switch on Fullscreen'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['bwcheck']['switchOnFullscreen'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['switchOnFullscreen'] : $default['flowplayer']['player']['plugins']['bwcheck']['switchOnFullscreen'],
		'#description' => t('Used when dynamic is set to false. Causes a bandwidth check and a switch when entering fullscreen or exiting fullscreen. When dynamic is set to true the plugin is doing QoS monitoring and switching dynamically if needed, also taking care the screen resize that happens with fullscreen mode.'),
);

$form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_hdButton'] = array(
		'#type' => 'select',
		'#title' => t('HD Button'),
		'#options' => array('dock' => 'dock', 'controls' => 'controls', 'both' => 'both'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['bwcheck']['hdButton'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['hdButton'] : $default['flowplayer']['player']['plugins']['bwcheck']['hdButton'],
		'#description' => t('Should the HD selection button be visible?.'),
);

/**
 * Controls plugin options
 * http://flowplayer.org/plugins/flash/controlbar.html
*/
$form['controls'] = array(
		'#type' => 'fieldset',
		'#title' => t('Controls'),
		'#collapsed' => ( ( ( isset($config['flowplayer']['player']['plugins']['controls']['enabled'])) ? $config['flowplayer']['player']['plugins']['controls']['enabled'] : $default['flowplayer']['player']['plugins']['controls']['enabled'] ? 0 : 1 ) ? TRUE : FALSE ),
		'#collapsible' => TRUE,
);

$form['controls']['dlts_bitstream_flowplayer_plugins_controls_autoHide'] = array(
		'#type' => 'select',
		'#title' => t('Auto Hiding'),
		'#options' => array('always' => 'always', 'fullscreen' => 'fullscreen', 'never' => 'never'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['controls']['autoHide'])) ? $config['flowplayer']['player']['plugins']['controls']['autoHide'] : $default['flowplayer']['player']['plugins']['controls']['autoHide'],
		'#description' => t('The controlbar can be made to automatically hide if the user is not actively using the player.'),
);

$form['controls']['dlts_bitstream_flowplayer_plugins_controls_play'] = array(
		'#type' => 'checkbox',
		'#title' => t('Play Button'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['controls']['play'])) ? $config['flowplayer']['player']['plugins']['controls']['play'] : $default['flowplayer']['player']['plugins']['controls']['play'],
		'#description' => t('Should the play/pause button be visible?'),
);

$form['controls']['dlts_bitstream_flowplayer_plugins_controls_volume'] = array(
		'#type' => 'checkbox',
		'#title' => t('Volume Control'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['controls']['volume'])) ? $config['flowplayer']['player']['plugins']['controls']['volume'] : $default['flowplayer']['player']['plugins']['controls']['volume'],
		'#description' => t('Should the volume control be visible?'),
);

$form['controls']['dlts_bitstream_flowplayer_plugins_controls_mute'] = array(
		'#type' => 'checkbox',
		'#title' => t('Mute Button'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['controls']['mute'])) ? $config['flowplayer']['player']['plugins']['controls']['mute'] : $default['flowplayer']['player']['plugins']['controls']['mute'],
		'#description' => t('Should the mute button be visible?'),
);

$form['controls']['dlts_bitstream_flowplayer_plugins_controls_time'] = array(
		'#type' => 'checkbox',
		'#title' => t('Time'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['controls']['time'])) ? $config['flowplayer']['player']['plugins']['controls']['time'] : $default['flowplayer']['player']['plugins']['controls']['time'],
		'#description' => t('Should the time display be visible?'),
);

$form['controls']['dlts_bitstream_flowplayer_plugins_controls_stop'] = array(
		'#type' => 'checkbox',
		'#title' => t('Stop Button'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['controls']['stop'])) ? $config['flowplayer']['player']['plugins']['controls']['stop'] : $default['flowplayer']['player']['plugins']['controls']['stop'],
		'#description' => t('Should the stop button be visible?'),
);

$form['controls']['dlts_bitstream_flowplayer_plugins_controls_playlist'] = array(
		'#type' => 'checkbox',
		'#title' => t('Playlist Buttons'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['controls']['playlist'])) ? $config['flowplayer']['player']['plugins']['controls']['playlist'] : $default['flowplayer']['player']['plugins']['controls']['playlist'],
		'#description' => t('Should the playlist buttons be visible? The playlist buttons allow navigation through the playlist entries of the current playlist. These buttons are always hidden if there are less than two entries in the playlist.'),
);

$form['controls']['dlts_bitstream_flowplayer_plugins_controls_fastBackward'] = array(
		'#type' => 'checkbox',
		'#title' => t('Fast Backward Button'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['controls']['fastBackward'])) ? $config['flowplayer']['player']['plugins']['controls']['fastBackward'] : $default['flowplayer']['player']['plugins']['controls']['fastBackward'],
		'#description' => t('Should the fast backward button be visible? The slow motion buttons allow controlling the playback speed (from 1/8 to 8x the normal speed). These buttons are always hidden if the slowmotion plugin is not loaded, and only available with the "Modern" skin.'),
);

$form['controls']['dlts_bitstream_flowplayer_plugins_controls_fastForward'] = array(
		'#type' => 'checkbox',
		'#title' => t('Fast Forward Button'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['controls']['fastForward'])) ? $config['flowplayer']['player']['plugins']['controls']['fastForward'] : $default['flowplayer']['player']['plugins']['controls']['fastForward'],
		'#description' => t('Should the fast forward button be visible?'),
);

/**
 * RTMP plugin options
 * http://flowplayer.org/plugins/streaming/rtmp.html
*/
$form['rtmp'] = array(
		'#type' => 'fieldset',
		'#title' => t('RTMP Plugin'),
		'#collapsed' => ( ( ( isset($config['flowplayer']['player']['plugins']['rtmp']['enabled'])) ? $config['flowplayer']['player']['plugins']['rtmp']['enabled'] : $default['flowplayer']['player']['plugins']['rtmp']['enabled'] ? 0 : 1 ) ? TRUE : FALSE ),
		'#collapsible' => TRUE,
);

$form['rtmp']['dlts_bitstream_flowplayer_plugins_rtmp_netConnectionUrl'] = array(
		'#type' => 'textfield',
		'#title' => t('FlowPlayer Net Connection URL'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['rtmp']['netConnectionUrl'])) ? $config['flowplayer']['player']['plugins']['rtmp']['netConnectionUrl'] : $default['flowplayer']['player']['plugins']['rtmp']['netConnectionUrl'],
		'#size' => 50,
		'#maxlength' => 200,
		'#description' => t('The RTMP URL used to connect to the server app. This is optional and you can also specify this in the clip, so that the different clips in the playlist point to different servers.'),
);

$form['rtmp']['dlts_bitstream_flowplayer_plugins_rtmp_objectEncoding'] = array(
		'#type' => 'textfield',
		'#title' => t('Object Encoding'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['rtmp']['objectEncoding'])) ? $config['flowplayer']['player']['plugins']['rtmp']['objectEncoding'] : $default['flowplayer']['player']['plugins']['rtmp']['objectEncoding'],
		'#size' => 50,
		'#maxlength' => 200,
		'#description' => t('The object encoding used with the streaming server. Change this to a value of 0 if you need to communicate to servers released prior to Flash Player 9 (Adobe Flash Media Server 2).'),
);

$form['rtmp']['dlts_bitstream_flowplayer_plugins_rtmp_proxyType'] = array(
		'#type' => 'select',
		'#title' => t('Proxy Type'),
		'#options' => array('none' => 'none', 'HTTP' => 'HTTP', 'CONNECT' => 'CONNECT', 'best' => 'best'),
		'#default_value' => (isset($config['flowplayer']['player']['plugins']['rtmp']['proxyType'])) ? $config['flowplayer']['player']['plugins']['rtmp']['proxyType'] : $default['flowplayer']['player']['plugins']['rtmp']['proxyType'],
		'#description' => t('The proxyType determines which fallback methods are tried if an initial connection attempt to the server fails. Flowplayer establishes the connection by doing parallel connection attempts using RTMP and RTMPT. The one that succeeds first is used and the other one is discarded - this way the connection is established as fast as possible in firewalled and proxied network environments.'),
);
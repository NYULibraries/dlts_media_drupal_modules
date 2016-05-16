<?php

function dlts_clip_flowplayer ( ) {
  /** Flowplayer skeleton and reference */
  $setup = ( $setup = variable_get( 'dlts_bitstream_globals_flowplayer', FALSE ) ) ? unserialize($setup) : dlts_clip_default_flowplayer_configuration();
  return $setup;
}

/**
 * Return a list of available Flowplayer Flash Plug-ins
 * http://flowplayer.org/plugins/index.html
 */
function dlts_clip_available_flowplayer_plugins_flash () {

  $plugins = file_scan_directory( libraries_get_path('flowplayer') . '/plugins/flash', '/.*\.swf$/' );

  $available = array();

  foreach ( $plugins as $path => $plugin ) {
    if ( ( preg_match( '/.([a-z]*)-\d.{4,}$/', $plugin->name, $matches ) ) ) $available[$matches[1]] = url( $path );
  }

  return $available;

}

/**
 * Return Flowplayer path and type and version
 */
function dlts_clip_flowplayer_available_flowplayer() {
  $plugins = file_scan_directory( libraries_get_path('flowplayer'), '/.*\.swf$/', array( 'recurse' => FALSE ) );
  $available = array();
  foreach ( $plugins as $path => $plugin ) {
    $available[$plugin->name]['url'] = url( $path );
    $available[$plugin->name]['filename'] = $plugin->filename;
    if ( preg_match ( '/commercial/', $plugin->name ) ) {
      $available[$plugin->name]['type'] = t('commercial');
      if ( preg_match( '/flowplayer\.?(commercial)?-?(\d\.\d{1}\.\d{1})-?(dev)?$/', $plugin->name, $matches ) ) {
        $available[$plugin->name]['version'] = $matches[2];
      }
    }
    else {
  	  $available[$plugin->name]['type'] = t('free');
    }
  }
  return $available;
}

function dlts_clip_default_flash_error() {
	$output = '<h2>' . t('Flash version 9,0 or greater is required</h2>') .
	'<h3>' . t('You have no flash plugin installed') . '</h3>' .
	'<p>'  . t('Download latest version from <a href="@adobe">here</a>', array( '@adobe' => 'http://www.adobe.com/go/getflashplayer') ) . '</p>';

	return $output;
}

function dlts_clip_default_flash_disable_error() {
	$output = '<h2>' . t('Flash version 9,0 or greater is required</h2>') .
	'<h3>' . t('You have no flash plugin installed') . '</h3>' .
	'<p>'  . t('Download latest version from <a href="@adobe">here</a>', array( '@adobe' => 'http://www.adobe.com/go/getflashplayer') ) . '</p>';

	return $output;
}

/**
 * Return Flowplayer Javascript API path and type and version
 */
function dlts_clip_flowplayer_available_flowplayer_javascript_api() {
  $available = array();
  foreach ( file_scan_directory( libraries_get_path('flowplayer'), '/.*\.js$/', array( 'recurse' => FALSE ) ) as $path => $file ) {
    $available += array( $file->name => array( 'url' => url( $path ) ) );
  }
  return $available;
}

function dlts_clip_default_flowplayer_configuration () {
  $default = array();
  $default['flowplayer'] = array(
    'player' => array(
      'version' => FALSE,
      'js_api' => FALSE,
      'url' => '',
      'commercial_key' => '',
      'flash' => array(
        'disableError' => dlts_clip_default_flash_disable_error(),
      	'errorMessage' => dlts_clip_default_flash_error(),
      ),
      'plugins' => array(
        'audio' => array(
          'enabled' => FALSE,
        ),
        'bwcheck' => array(
          'enabled' => FALSE,
          'bitrateProfileName' => 'RTMPBitrateProfile',
          'checkOnStart' => TRUE,
          'dynamic' => FALSE,
          'dynamicBuffer' => FALSE,
          'live' => FALSE,
          'netConnectionUrl' => $GLOBALS['base_url'] . '/' . libraries_get_path('flowplayer') . '/flowplayer.commercial-3.2.18.swf',
          'rememberBitrate' => FALSE,
          'serverType' => 'fms',
          'hdButton' => 'controls',
          'switchOnFullscreen' => TRUE,
        ),
        'controls' => array(
          'enabled' => TRUE,
          'autoHide' => 'always',
          'play' => TRUE,
          'volume' => TRUE,
          'mute' => TRUE,
          'time' => TRUE,
          'stop' => FALSE,
          'playlist' => FALSE,
          'fastBackward' => FALSE,
          'fastForward' => FALSE,
        ),
        'rtmp' => array(
          'enabled' => FALSE,
          'netConnectionUrl' => 'rtmp://fmsdev.library.nyu.edu/vod/media/',
          'objectEncoding' => 3,
          'proxyType' => 'best',
        ),
      ),
    ),
    'clip' => array(
      'accelerated' => FALSE,
      'autoBuffering' => FALSE,
      'autoPlay' => TRUE,
      'baseUrl' => '',
      'bufferLength' => 3,
      'cuepointMultiplier' => 1000,
      'start' => 0,
      'duration' => 0,
      'fadeInSpeed' => 1000,
      'fadeOutSpeed' => 1000,
      'live' => FALSE,
      'provider' => 'rtmp',
      'bitrate' => 800,
      'scaling' => 'fit',
    ),
  );

  return $default;

}

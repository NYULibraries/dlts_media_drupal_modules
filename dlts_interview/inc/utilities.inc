<?php

/*
 * Utility functions.
 */

/*
 * Return a list of available Flowplayer Flash Plug-ins
 * http://flowplayer.org/plugins/index.html
 */

function dlts_interview_available_flowplayer_plugins_flash() {
  $plugins = file_scan_directory( libraries_get_path('flowplayer') . '/plugins/flash', '/.*\.swf$/' );
  $available = array();
  foreach( $plugins as $path => $plugin ) {
    if ( ( preg_match( '/.([a-z]*)-\d.{4}$/', $plugin->name, $matches ) ) ) {
      $available[$matches[1]] = url( $path );
    }
  }
  return $available;
}

/*
 * Return Flowplayer path and type and version
 */

function dlts_interview_flowplayer_available_flowplayer() {
  $plugins = file_scan_directory( libraries_get_path('flowplayer'), '/.*\.swf$/', array( 'recurse' => FALSE ) );
  $available = array();
  foreach( $plugins as $path => $plugin ) {
    if ( ( preg_match( '/flowplayer\.?(commercial)?-?(\d\.\d{1}\.\d{1})-?(dev)?$/', $plugin->name, $matches ) ) ) {
      if ( $matches[1]  == '' && !isset( $matches[3] ) ) {
        $available[$plugin->name]['type'] = t('free');
      } elseif ( $matches[1]  == 'commercial' ) {
        $available[$plugin->name]['type'] = $matches[1];

      } elseif ( $matches[3]  == 'dev' ) {
        $available[$plugin->name]['type'] = $matches[3];

      } else { }

      $available[$plugin->name]['url'] = url( $path );
      $available[$plugin->name]['version'] = $matches[2];
    }
  }
  return $available;
}

/*
 * Return Flowplayer Javascript API path and type and version
 */

function dlts_interview_flowplayer_available_flowplayer_javascript_api() {
  $available = array();
  foreach( file_scan_directory( libraries_get_path('flowplayer'), '/.*\.js$/', array( 'recurse' => FALSE ) ) as $path => $file ) {
    $available += array(
      $file->name => array(
        'url' => url( $path ),
      ),
    );
  }
  return $available;
}
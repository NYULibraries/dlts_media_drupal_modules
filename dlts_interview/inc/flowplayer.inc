<?php

function dlts_interview_flowplayer( $vars, $type ) {

  $detect = mobile_detect_get_object();

  $is_mobile = $detect->isMobile();

  $is_tablet = $detect->isTablet();

  /**
   * Flowplayer skeleton and reference
   */
  $setup = unserialize( variable_get( 'dlts_bitstream_globals_flowplayer', FALSE ) );

  if ( !$setup ) {
    watchdog('dlts_interview', t('Unable to initiate Flowplayer. Please visit Bitstream handling settings for Flowplayer'), array(), WATCHDOG_ALERT );
    drupal_set_message( t('Unable to initiate Flowplayer.'), 'warning' );
    return FALSE;
  }

  $setup += array( 'playlist' => array(), 'is_mobile' => $is_mobile, 'is_tablet' => $is_tablet );

  /*
   * Node logic follows
   */
  switch ( $type ) {
    case 'clip' :
      _dlts_interview_type_dlts_clip_field_bitstream_ref( $vars, $setup );
      break;
    case 'interview' :
      _dlts_interview_type_dlts_playlist_field_playlist_ref( $vars, $setup );
      break;
    case 'bitstream_set' :
      _dlts_interview_type_dlts_bitstream_set_field_bitstream( $vars, $setup );
      break;
    default :
      return FALSE;
  }

  $setup['streams'] = array(
    array (
      'id' => _dlts_interview_flowplayer_id( $vars->nid ),
      'playlist' => $setup['playlist'],
    ),
  );

   /**
    * House cleaning
    */
  unset( $setup['clip'] );
  unset( $setup['playlist'] );
  return $setup;

}

function _dlts_interview_dlts_bitstream_set_field_bitstream( $entity, &$setup, $index = 0 ) {
  /*
   * "Inherit" from Clip
   */
  $setup['playlist'][$index] = $setup['clip'];

  foreach( (array) dlts_interview_field_get_items( $entity, 'field_bitstream' ) as $value ) {
    if ( !isset( $setup['playlist'][$index]['type'] ) ) {
      $setup['playlist'][$index]['type'] = dlts_interview_get_media_type( $value );
    }
    $setup['playlist'][$index]['bitrates'][] = _dlts_interview_bitrates( $value, $setup, $index );
  }
  $setup['playlist'][$index]['duration'] = ( ( $duration = dlts_interview_field_get_item_value( $entity, 'field_duration' ) ) ? $duration : 0 );
  $setup['playlist'][$index]['title'] = $entity->title;
  _dlts_interview_resolver( $setup, $index );
}

function _dlts_interview_type_dlts_clip_field_bitstream_ref( $entity, &$setup, $index = 0 ) {
  foreach( (array) dlts_interview_field_get_items( $entity, 'field_bitstream_ref' ) as $bitstream_ref ) {
    _dlts_interview_dlts_bitstream_set_field_bitstream( node_load( $bitstream_ref['nid'] ), $setup, $index );
    $setup['playlist'][$index]['title'] = $entity->title;
    $setup['playlist'][$index]['duration'] = ( ( $duration = dlts_interview_field_get_item_value( $entity, 'field_duration' ) ) > 0 ) ? $duration : $setup['playlist'][$index]['duration'];
    $setup['playlist'][$index]['start'] = ( ( $start  = dlts_interview_field_get_item_value( $entity, 'field_start' ) ) > 0 ) ? $start : $setup['playlist'][$index]['start'];
  }
}

function _dlts_interview_type_dlts_playlist_field_clip_ref( $entity, &$setup ) {
  foreach( (array) dlts_interview_field_get_items( $entity, 'field_clip_ref' ) as $index => $clip ) {
    _dlts_interview_type_dlts_clip_field_bitstream_ref( node_load( $clip['nid'] ), $setup, $index );
  }
  _dlts_interview_flowplayer_buttons_playlist( $setup );
}

function _dlts_interview_type_dlts_playlist_field_playlist_ref( $entity, &$setup ) {
  foreach ( (array) dlts_interview_field_get_items( $entity, 'field_playlist_ref' ) as $playlist  ) {
    _dlts_interview_type_dlts_playlist_field_clip_ref( node_load( $playlist['nid'] ), $setup );
  }
}

function _dlts_interview_type_dlts_bitstream_set_field_bitstream( $entity, &$setup ) {
  foreach ( (array) dlts_interview_field_get_items( $entity, 'field_bitstream' ) as $index => $bitstream  ) {

    if ( !isset( $setup['playlist'][$index]['type'] ) ) {
  	  $setup['playlist'][$index]['type'] = dlts_interview_get_media_type( $bitstream );
  	}

  	$setup['playlist'][$index]['bitrates'][] = _dlts_interview_bitrates( $bitstream, $setup, $index );

  	$setup['playlist'][$index]['start'] = 0;

  	$setup['playlist'][$index]['duration'] = ( ( $duration = dlts_interview_field_get_item_value( $entity, 'field_duration' ) ) ? $duration : 0 );

  	$setup['playlist'][$index]['title'] = $entity->title;

  	_dlts_interview_resolver( $setup, $index );

  }
}

function _dlts_interview_bitrates( $bitrate, $setup, $index = 0 ) {
  return array(
    'url' => dlts_interview_media_url( $bitrate['identifier'], $setup['playlist'][$index]['type'] ),
    'width' => (int) $bitrate['width'],
    'height' => (int) $bitrate['height'],
    'bitrate' => (int) $bitrate['bitrate'],
    'hd' => ( ( $bitrate['is_hd'] ? 1 : 0 ) ? TRUE : FALSE ),
    'normal' => ( ( $bitrate['is_hd'] ? 0 : 1 ) ? TRUE : FALSE ),
    'isDefault' => ( ( $bitrate['bitrate'] == variable_get( 'dlts_bitstream_flowplayer_clip_bitrate', 300 ) ) ? TRUE : FALSE ),
  );
}

function _dlts_interview_rtpm_default_clipURL( &$setup, $index = 0 ) {
  foreach ( $setup['playlist'][$index]['bitrates'] as $bitrate )  {
    if ( $bitrate['isDefault'] ) {
      $setup['playlist'][$index]['url'] = $bitrate['url'];
      unset( $setup['playlist'][$index]['bitrates'] );
      unset( $setup['playlist'][$index]['urlResolvers'] );
      unset( $setup['playlist'][$index]['bitrate'] );
      return;
    }
  }
}

/*
 * Clip resolver
 * HTTP, RTMP, bwcheck
 */
function _dlts_interview_resolver(&$setup, $index = 0) {

  /*
   * Bandwidth detection and RTMP
   * Clip resolver must be set to bwcheck
   */
  if ( isset( $setup['player']['plugins'] ) ) {
    if ( isset( $setup['player']['plugins']['bwcheck'] ) && isset( $setup['player']['plugins']['rtmp'] ) ) {
      $setup['player']['plugins']['bwcheck']['hdButton'] = TRUE; // make this a option @ flowplayer admin page?
      $setup['playlist'][$index]['urlResolvers'] = 'bwcheck';
      $setup['playlist'][$index]['provider'] = 'rtmp'; // make this a option @ flowplayer admin page?
      $setup['playlist'][$index]['netConnectionUrl'] = (isset($setup['plugins'])) ? $setup['plugins']['bwcheck']['netConnectionUrl'] : null;
      unset( $setup['playlist'][$index]['bitrate'] );
    }

    /*
     * RTMP is the provider and resolver, Bandwidth detection is disable
     */

    if ( !isset( $setup['player']['plugins']['bwcheck'] ) && isset( $setup['player']['plugins']['rtmp'] ) ) {
      $setup['playlist'][$index]['provider'] = 'rtmp';
      $setup['playlist'][$index]['netConnectionUrl'] = $setup['player']['plugins']['rtmp']['netConnectionUrl'];
      _dlts_interview_rtpm_default_clipURL( $setup, $index );
    }
  }

}

/*
 * Media Type
 */
function dlts_interview_get_media_type( $media ) {
  if ( !isset( $media['media_type'] ) ) {
    return FALSE;
  }

  $type = explode( '/', $media['media_type'] );
  return $type[0];
}

/*
 * Media URL
 * Resolve RTMP URL for videos and audio
 */
function dlts_interview_media_url( $identifier, $type = 'video' ) {
  preg_match( '/(.*)\.([^\.]+)/', $identifier, $matches );
  switch ( $type ) {
    case 'video':
      return $matches[2] . ':' . $matches[0];
      break;
    case 'audio':
      return $matches[2] . ':' . $matches[1];
      break;
    default:
     return FALSE;
  }
}

/*
 * Enable Next/Back button if playlist > 1 AND controls plug-in is enable
 */
function _dlts_interview_flowplayer_buttons_playlist( &$setup ) {
  if ( !isset( $setup['player']['plugins']['controls'] ) ) {
    return FALSE;
  }

  if (  count( $setup['playlist'] ) > 1 ) {
    $setup['player']['plugins']['controls']['playlist']  = 1;
  } else {
    unset( $setup['player']['plugins']['controls']['playlist'] );
  }
}

function _dlts_interview_flowplayer_id( $nid ) {
  return 'id-' . md5( $nid );
}

function dlts_interview_field_get_item_value( $entity, $field, $entity_type = 'node' ) {
  $items = field_get_items( $entity_type, $entity, $field );
  return $items[0]['value'];
}

function dlts_interview_field_get_items( $entity, $field, $entity_type = 'node' ) {
  return field_get_items( $entity_type, $entity, $field );
}

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

/**
 * Return Flowplayer path and type and version
 */
function dlts_interview_flowplayer_available_flowplayer() {

  $plugins = file_scan_directory( libraries_get_path('flowplayer'), '/.*\.swf$/', array( 'recurse' => FALSE ) );

  $available = array();

  foreach ( $plugins as $path => $plugin ) {

  	if ( $plugin->name == 'flowplayer') {
  	  $available[$plugin->name]['type'] = t('Free');
  	}

    else if ( ( preg_match( '/flowplayer\.?(commercial)?-?(\d\.\d{1}\.\d{1})-?(dev)?$/', $plugin->name, $matches ) ) ) {

      if ( empty ( $matches[1] ) && !isset( $matches[3] ) ) {
	    $available[$plugin->name]['type'] = t('free');
      }

      elseif ( $matches[1]  == 'commercial' ) {
        $available[$plugin->name]['type'] = $matches[1];
      }

      elseif ( $matches[3]  == 'dev' ) {
        $available[$plugin->name]['type'] = $matches[3];
      }

      $available[$plugin->name]['version'] = $matches[2];

    }

    $available[$plugin->name]['url'] = url( $path );

    $available[$plugin->name]['filename'] = $plugin->filename;

  }

  return $available;

}

/**
 * Return Flowplayer Javascript API path and type and version
 */
function dlts_interview_flowplayer_available_flowplayer_javascript_api() {

  $available = array();

  foreach ( file_scan_directory( libraries_get_path('flowplayer'), '/.*\.js$/', array( 'recurse' => FALSE ) ) as $path => $file ) {
    $available += array( $file->name => array( 'url' => url( $path ) ) );
  }

  return $available;

}

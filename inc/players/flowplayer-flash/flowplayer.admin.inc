<?php

/**
 * Enable/disable plugins
 * http://flowplayer.org/documentation/configuration/
 */
function dlts_clip_player_flowplayer_config($form, &$form_state) {

  module_load_include('inc', 'dlts_clip', 'inc/players/flowplayer-flash/flowplayer');

  module_load_include('inc', 'dlts_clip', 'inc/players/flowplayer-flash/flowplayer.admin.player');

  module_load_include('inc', 'dlts_clip', 'inc/players/flowplayer-flash/flowplayer.admin.clip');

  module_load_include('inc', 'dlts_clip', 'inc/players/flowplayer-flash/flowplayer.admin.flash');  

  /** form */

  $form['player'] = dlts_media_admin_player ( ) ;

  $form['clip'] = dlts_media_admin_clip ( ) ;
  
  $form['flash'] = dlts_media_admin_flash ( ) ;
  
  foreach ( dlts_clip_available_flowplayer_plugins_flash () as $plugin => $path ) {

    $pluginFilepath = 'flowplayer.admin.plugins.' . $plugin ;

    if ( file_exists (  __DIR__ . '/' . $pluginFilepath . '.inc' ) ) {

      module_load_include('inc', 'dlts_clip', 'inc/players/flowplayer-flash/' . $pluginFilepath ) ;

      $callback = 'dlts_clip_' . $plugin . '_plugin' ;

      if ( function_exists ( $callback ) )  {
        $form[$plugin] = $callback( ) ;      
      }

    }

  }
  
  $form['dlts_bitstream_globals_flowplayer'] = array('#type' => 'hidden', '#value' => $saved_config ) ;

  return system_settings_form ( $form ) ;
  
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
function dlts_clip_player_flowplayer_config_validate($form, &$form_state) {

  $form_state['values']['dlts_bitstream_flash_disableError'] = filter_xss($form_state['values']['dlts_bitstream_flash_disableError'], array('a', 'em', 'strong', 'h1', 'h2', 'h3', 'h4', 'h5', 'p' ) );

  $config = array(
    'player' => array(
      'url' => $form_state['values']['dlts_bitstream_flowplayer_version'],
      'flash' => array(
        'errorMessage' => $form_state['values']['dlts_bitstream_flash_disableError'],
      ),
    )
  );

  if ( !empty( $form_state['values']['dlts_bitstream_flowplayer_commercial_key'] ) ) {
    $config['player']['key'] = $form_state['values']['dlts_bitstream_flowplayer_commercial_key'];
  }

  if ( !empty( $form_state['values']['dlts_bitstream_flowplayer_version'] ) ) {
  	$config['player']['version'] = $form_state['values']['dlts_bitstream_flowplayer_version'];
  }

  if ( !empty( $form_state['values']['dlts_bitstream_flowplayer_js_api'] ) ) {
    $config['player']['js_api'] = $form_state['values']['dlts_bitstream_flowplayer_js_api'];
  }

  /**
   * Available Flowplayer plugins (flash). Used to provide the plugin location
   */

  $available_flow_plugins_flash = dlts_clip_available_flowplayer_plugins_flash();

  foreach ( $form_state['values'] as $key => $value ) {

    /** Plugin enabled? */
    if ( preg_match('/dlts_bitstream_flowplayer_plugins_([a-zA-Z]*)$/', $key, $plugin ) && $value ) {

      if ( ! isset( $config['player']['plugins'] ) ) $config['player']['plugins'] = array();

      if ( ! isset( $config['player']['plugins'][$plugin[1]] ) ) $config['player']['plugins'][$plugin[1]] = array();

      $config['player']['plugins'][$plugin[1]]['enabled'] = TRUE;

      /**
       * Plug-ins don't live in the same location as the JS caller, we need to provide the
       * URL parameter for each plugin.
       */
      $config['player']['plugins'][$plugin[1]]['url'] = $available_flow_plugins_flash[$plugin[1]];

    }

  	/** Plugins */
    if (
      preg_match('/dlts_bitstream_flowplayer_plugins_([a-zA-Z]*)_([a-zA-Z]*)$/', $key, $matches )
    ) {

      /**
       * Config as pair of keys and values:
       *   $matches[1] = plugin name
       *   $matches[2] = plugin parameter
       *   $value = parameter value
       */
      if ( isset( $config['player']['plugins'][$matches[1]] ) && $config['player']['plugins'][$matches[1]]['enabled'] ) $config['player']['plugins'][$matches[1]][$matches[2]] = $value;
    }

    /** Clip */
    if ( preg_match('/dlts_bitstream_flowplayer_clip_([a-zA-Z]*)$/', $key, $matches )  ) {
      if ( isset( $form_state['values']['dlts_bitstream_flowplayer_clip_' . $matches[1] ] ) && $form_state['values']['dlts_bitstream_flowplayer_clip_' . $matches[1]] !== '' ) {
        $config['clip'][$matches[1]] = $value;
      }
    }

    /** Remove anything that match dlts_bitstream from $form_state['values']; later on we will add a serialize version of $config as a variable */
    if ( preg_match('/dlts_bitstream/', $key, $input ) && !empty( $input ) ) unset( $form_state['values'][$key] );

  }

  $form_state['values']['dlts_bitstream_globals_flowplayer'] = serialize( array( 'flowplayer' => $config ) );

}

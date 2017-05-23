<?php

function dlts_media_admin_player () {

  /** Flowplayer flash filepath */
  $selected_player = NULL ;

  if ( isset ( $config['player'] ) ) {
    $selected_player = $config['player'] ;
  }

  /** available Flowplayer flash files */
  $available_players = array();

  /**
   * flag to determine if one of the available players is the
   * commercial version
   */
  $isCommercial = FALSE;

  /** find players inside the flowplayer library folder */
  foreach ( dlts_clip_flowplayer_available_flowplayer() as $value ) {

    /** We save the public URL but display the filename */
    $available_players += array ( $value['url'] => $value['filename'] ) ;

    /**
     * Check for selection ; if the player is the commercial version of
     * Flowplayer set flag to display the "key" field.
     */
    if (
      isset ( $value['type'] ) &&
      $value['type'] == 'commercial' &&  // commercial version ?
      $value['url'] == $selected_player  // is selected ?
    ) {
      $isCommercial = TRUE;
    }

  }

  // $commercial_key = '#$623666ca2f667514416' ;  

  $commercial_key = NULL ;
  
  if ( isset ( $config['commercial_key'] ) ) {
    $commercial_key = $config['commercial_key'] ;
  }

  /** Flowplayer flash JavaScript API filepath */
  $js_api = NULL ;

  if ( isset ( $config['js_api'] ) ) {
    $js_api = $config['js_api'] ;
  }

  /** available Flowplayer JavaScript API */
  $available_js_api = array();

  foreach ( dlts_clip_flowplayer_available_flowplayer_javascript_api() as $file => $value ) {
    $available_js_api += array ( $value['url'] => $file ) ;
  }

  $form = array ( ) ;
	
  $form['flowplayer'] = array (
    '#type' => 'fieldset' ,
    '#title' => t('Flowplayer') ,
    '#collapsed' => FALSE ,
    '#collapsible' => TRUE ,
  ) ;

  $form['flowplayer']['player'] = array (
    '#type' => 'radios' ,
    '#title' => t('Player') ,
    '#default_value' => $selected_player ,
    '#options' => $available_players ,
  ) ;

  $form['flowplayer']['js_api'] = array (
    '#type' => 'radios' ,
    '#title' => t('Javascript API') ,
    '#default_value' => $js_api ,
    '#options' => $available_js_api ,
  ) ;
  
  $form['flowplayer']['commercial_key'] = array (
    '#type' => 'textfield' ,
    '#title' => t('Commercial Key') ,
    '#default_value' => $commercial_key ,
    '#size' => 50 ,
    '#maxlength' => 100 ,
    '#description' => t('The key to enable the use of the commercial version of the player') ,
  ) ;
  
  return $form ;  

}

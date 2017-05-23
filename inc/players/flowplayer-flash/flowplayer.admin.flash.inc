<?php

function dlts_media_admin_flash () {
  
  $form = array () ;
  
  $disableError = variable_get( 'dlts_bitstream_flash_disableError', dlts_clip_default_flash_disable_error() ) ;
  
  $form['flash'] = array(
    '#type' => 'fieldset',
    '#title' => t('Flash settings'),
    '#collapsed' => TRUE,
    '#collapsible' => TRUE,
  );

  $form['flash']['disableError'] = array(
    '#type' => 'textarea',
    '#title' => t('Disable error message'),
    '#default_value' => $disableError,
    '#description' => t('Error message to be display when Flash plugin is disable or installed.'),
  );
  
  return $form ;

}

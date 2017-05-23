<?php

/**
 * Make Flowplayer understand F4M manifest files
 * http://flash.flowplayer.org/plugins/streaming/f4m.html
 */
function dlts_clip_f4m_plugin () {

  $form = array() ;

  $dvrBufferTime = 4 ;
  
  $dvrDynamicBufferTime = 4 ;

  $dynamicBufferTime = 4 ;
  
  $liveBufferTime = 4 ;
  
  $liveDynamicBufferTime = 4 ;
  
  $includeApplicationInstance = 0 ;
  
  $version = 1 ;

  $form['f4m'] = array(
    '#type' => 'fieldset',
    '#title' => t('F4M: Resolves the media URL contained in a Adobe F4M manifest file'),
    '#collapsed' => TRUE,
    '#collapsible' => TRUE,
    '#description' => 'The F4M plugin is used to parse Adobe F4M manifest files so that 
                       the referenced media files can be played back in Flowplayer. The 
                       F4M format is similar to the SMIL format, it can be configured 
                       for multi bitrate streaming and it includes extra information for
                       DVR/DRM and Adobe Http Streaming. Note: For XSS security reasons
                       Flash plugins must be located at and loaded from the same domain
                       as the core player.' ,
  );

  $form['f4m']['dvrBufferTime'] = array(
    '#type' => 'textfield',
    '#title' => t('dvrBufferTime'),
    '#default_value' => $dvrBufferTime,
    '#size' => 20,
    '#maxlength' => 100,
    '#description' => t('Buffer time used for a detected Live DVR stream.'),
  );
  
  $form['f4m']['dvrDynamicBufferTime'] = array(
    '#type' => 'textfield',
    '#title' => t('dvrDynamicBufferTime'),
    '#default_value' => $dvrDynamicBufferTime,
    '#size' => 20,
    '#maxlength' => 100,
    '#description' => t('Buffer time used for a detected Live Multi-bitrate DVR stream.'),
  );

  $form['f4m']['dynamicBufferTime'] = array(
    '#type' => 'textfield',
    '#title' => t('dynamicBufferTime'),
    '#default_value' => $dynamicBufferTime,
    '#size' => 20,
    '#maxlength' => 100,
    '#description' => t('Buffer time used for a detected Multi-bitrate stream.'),
  );

  $form['f4m']['liveBufferTime'] = array(
    '#type' => 'textfield',
    '#title' => t('liveBufferTime'),
    '#default_value' => $liveBufferTime,
    '#size' => 20,
    '#maxlength' => 100,
    '#description' => t('Buffer time used for a detected Live stream.'),
  );
  
  $form['f4m']['liveDynamicBufferTime'] = array(
    '#type' => 'textfield',
    '#title' => t('liveDynamicBufferTime'),
    '#default_value' => $liveDynamicBufferTime,
    '#size' => 20,
    '#maxlength' => 100,
    '#description' => t('Buffer time used for a detected Live Multi-bitrate stream.'),
  );
  
  $form['f4m']['includeApplicationInstance'] = array(
    '#type' => 'textfield',
    '#title' => t('includeApplicationInstance'),
    '#default_value' => $includeApplicationInstance,
    '#size' => 20,
    '#maxlength' => 100,
    '#description' => t('For RTMP connections that have application instance connections
                         like with Cloudfront CDN, parse the F4M manifests with 
                         configured baseURL RTMP connections with it\'s instance so the 
                         filenames are obtained correctly. This can be configured here 
                         or in the F4M manifest file using the 
                         urlIncludesFMSApplicationInstance tag.'),
  );
  
  $form['f4m']['version'] = array(
    '#type' => 'textfield',
    '#title' => t('version'),
    '#default_value' => $version,
    '#size' => 20,
    '#maxlength' => 100,
    '#description' => t('Which version of the F4M manifest specification is used. Must
                         be set to 2 for multi-bitrate master manifests which do not 
                         conatain any packaging information, but only link to separate 
                         manifests. Indicated by 2.0 in last part of the xmlns property
                         of the manifest tag.'),
  );  

  return $form ;
  
}

  
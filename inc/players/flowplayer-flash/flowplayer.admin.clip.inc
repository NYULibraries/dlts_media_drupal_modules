<?php

/**
 * Clips
 * http://flowplayer.org/documentation/configuration/clips.html
 */
function dlts_media_admin_clip () {

  $form = array() ;
  
  $scaling = '' ;
  
  $accelerated = '' ;
  
  $autoBuffering = '' ;
  
  $autoPlay = '' ;
  
  $baseUrl = '' ;
  
  $bufferLength = '' ;

  $cuepointMultiplier = '' ;
  
  $start = '' ;
  
  $duration = '' ;
  
  $fadeInSpeed = '' ;
  
  $fadeOutSpeed = '' ;
  
  $live = '' ;
  
  $provider = '' ;
  
  $scaling = '' ;

  $bitrate = '' ;

  $form['clip'] = array(
    '#type' => 'fieldset',
    '#title' => t('Clip Settings'),
    '#collapsed' => TRUE,
    '#collapsible' => TRUE,
  );

  $form['clip']['accelerated'] = array(
    '#type' => 'checkbox',
    '#title' => t('Accelerated'),
    '#default_value' => $accelerated,
    '#description' => t('Flag indicating whether Flash 9 (and above) hardware-accelerated
                         full screen mode should be used.'),
  );

  $form['clip']['autoBuffering'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto Buffering'),
    '#default_value' => $autoBuffering,
    '#description' => t('Flag indicating whether loading of clip into player\'s memory
                         should begin straight away. When this is true and autoPlay is 
                         false then the clip will automatically stop at first frame of
                         the video.'),
  );

  $form['clip']['autoPlay'] = array(
    '#type' => 'checkbox',
    '#title' => t('Autoplay'),
    '#default_value' => $autoPlay,
    '#description' => t('Flag indicating whether the player should start playback 
                         immediately upon loading.'),
  );
  

  $form['clip']['live'] = array(
    '#type' => 'checkbox',
    '#title' => t('Live'),
    '#default_value' => $live,
    '#description' => t('RTMP streaming servers support live streaming, which means that 
                         it is possible to setup a video camera or other live video 
                         source to stream live video data to Flowplayer. If you have an
                         RTMP server which is providing a live video stream, you should 
                         set this property to true.'),
  );  

  $form['clip']['baseUrl'] = array(
    '#type' => 'textfield',
    '#title' => t('Base Url'),
    '#default_value' => $baseUrl,
    '#size' => 50,
    '#maxlength' => 200,
    '#description' => t('The first part of the URL of the video\'s location. This 
                         property is prepended in front of the url property (for 
                         relative URLs). If not specified, the video file is loaded 
                         from the same directory as the enclosing HTML file.'),
  );

  $form['clip']['bufferLength'] = array(
    '#type' => 'textfield',
    '#title' => t('Buffer Length'),
    '#default_value' => $bufferLength,
    '#size' => 5,
    '#maxlength' => 5,
    '#description' => t('The amount of video data (in seconds) which should be loaded 
                         into Flowplayer\'s memory in advance of playback commencing.'),
  );

  $form['clip']['cuepointMultiplier'] = array(
    '#type' => 'textfield',
    '#title' => t('Cuepoint Multiplier'),
    '#default_value' => $cuepointMultiplier,
    '#size' => 50,
    '#maxlength' => 200,
    '#description' => t('The times of embedded cuepoints are multiplied by this 
                         value before being used. Some encoding tools embed cuepoints 
                         in seconds but Flowplayer processes cuepoints in milliseconds.
                         Note that the times are also rounded to the nearest 100 
                         milliseconds. For example, if a file has a cuepoint at 5.535 
                         seconds, the cuepoint is fired at 5500 milliseconds (assuming 
                         the default multiplier value of 1000).'),
  );

  $form['clip']['start'] = array(
    '#type' => 'textfield',
    '#title' => t('Start'),
    '#default_value' => $start,
    '#size' => 50,
    '#maxlength' => 200,
    '#description' => t('The time (in seconds) at which playback should commence. This 
                         is only supported when you have a streaming server.'),
  );

  $form['clip']['duration'] = array(
    '#type' => 'textfield',
    '#title' => t('Duration'),
    '#default_value' => $duration,
    '#size' => 50,
    '#maxlength' => 200,
    '#description' => t('The time, in seconds and fractions of a second, for which a 
                         video clip should be played until playback ceases. This must 
                         always be less than or equal to the total length of the clip. 
                         Zero means to play the whole clip.'),
  );

  $form['clip']['fadeInSpeed'] = array(
    '#type' => 'textfield',
    '#title' => t('Fade In Speed'),
    '#default_value' => $fadeInSpeed,
    '#size' => 50,
    '#maxlength' => 200,
    '#description' => t('Time in milliseconds to fade from zero to full opacity upon 
                         commencement of video playback.'),
  );

  $form['clip']['fadeOutSpeed'] = array(
    '#type' => 'textfield',
    '#title' => t('Fade Out Speed'),
    '#default_value' => $fadeOutSpeed,
    '#size' => 50,
    '#maxlength' => 200,
    '#description' => t('Time in milliseconds to fade from full to zero opacity upon 
                         completion of video playback.'),
  );

  $form['clip']['provider'] = array(
    '#type' => 'select',
    '#title' => t('Provider'),
    '#options' => array(
      'http' => 'HTTP',
      'rtmp' => 'RTPM',
    ),
    '#default_value' => $provider,
    '#description' => t('Sets a connection provider to be used for clips. Connection 
                         providers can be used to create a connection to a streaming 
                         server or to a CDN network. The value of this property 
                         *should* be the name of a configured plugin.'),
  );

  $form['clip']['bitrate'] = array(
    '#type' => 'textfield',
    '#title' => t('Clip bitrate'),
    '#size' => 50,
    '#maxlength' => 200,
    '#default_value' => $bitrate,
    '#description' => t('The default bitrate for all clips'),
  );

  $form['clip']['scaling'] = array(
    '#type' => 'select',
    '#title' => t('Scaling'),
    '#options' => array(
      'fit' => 'Fit',
      'half' => 'Half',
      'orig' => 'Original',
      'scale' => 'Scale'
    ),
    '#default_value' => $scaling,
  );

  return $form ;

}

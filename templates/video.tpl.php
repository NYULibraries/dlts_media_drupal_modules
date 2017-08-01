<div 
  id="<?php print $identifier ?>" 
  class="flowplayer"
  data-title="<?php print $identifier ?>"
  data-fullscreen="true" 
  data-duration="<?php print $duration ?>" 
  data-start="<?php print $start ?>" 
  data-share="<?php print $share ?>"
  data-key="<?php print $key ?>"
  data-fullscreen="true"
  <?php if ($type == 'audio') : ?>data-audio-only="true"<?php endif ?>
  >
  <video poster="<?php print $poster ?>">
    <source type="application/x-mpegurl" src="<?php print $m3u ?>">
  </video>
</div>

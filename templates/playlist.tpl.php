<style><?php print $style ?></style>
<div 
  id="<?php print $identifier ?>"
  class="dlts_playlist flowplayer is-splash"
  data-duration="<?php print $duration ?>" 
  data-start="<?php print $start ?>" 
  data-fullscreen="true"
>
  <video preload="none">
    <source type="application/x-mpegurl" src="<?php print $m3u ?>">
  </video>
  <a class="fp-prev" title="prev">&lt;</a>
  <a class="fp-next" title="next">&gt;</a>
  <div class="fp-playlist"><?php print $links ?></div>
</div>

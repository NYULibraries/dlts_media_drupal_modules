<?php

/**
 * @file
 * DLTS Clip
 */
/**
 * Implements hook_drush_command().
 *
 * In this hook, you specify which commands your
 * drush module makes available, what it does and
 * description.
 *
 * Notice how this structure closely resembles how
 * you define menu hooks.
 *
 * @see drush_parse_command()
 *   for a list of recognized keys.
 *
 * @return
 *   An associative array describing your command(s).
 */
function dlts_clip_drush_command() {
  $items = array();
  $items['import-bitstream'] = array(
    'callback' => 'dlts_clip_import_bitstream',
    'description' => dt('Import bitstream from a JSON document.'),
    'options' => array(
      'source' => dt('JSON document filepath.'),
    ),
  );
  return $items;
}

/**
 * Implements hook_drush_help().
 *
 * This function is called whenever a drush user calls
 * 'drush help <name-of-your-command>'
 *
 * @param
 *   A string with the help section(prepend with 'drush:')
 *
 * @return
 *   A string with the help text for your command.
 */
function dlts_clip_drush_help($section) {
  switch ($section) {
    case 'drush:import-bitstream':
      return dt("Some day someone will document this module");
      break;
  }
}

function dlts_clip_import_bitstream($source = FALSE) {

  include_once(__DIR__ . '/includes/common.inc');

  include_once(__DIR__ . '/includes/datasource.inc');

  include_once(__DIR__ . '/includes/create.inc');

  $json = ($source) ? $source : drush_get_option('source', NULL);

  if (!$json) dlts_clip_exit('No source to import', 'error');

  $files = (is_dir($json)) ? file_scan_directory($source, '/(.*)\.json$/', array('recurse' => FALSE)) : array((object) array('uri' => $json));

  create_bitstream_from_json($files);

}

function dlts_clip_exit($message = NULL, $status) {
  drush_log($message, $status);
  die();
}
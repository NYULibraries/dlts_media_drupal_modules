<?php
/**
 * @file
 * dlts_playable_bitstreams.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dlts_playable_bitstreams_user_default_permissions() {
  $permissions = array();

  // Exported permission: access administration pages.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: access all views.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: access content.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: access content overview.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: access contextual links.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: access dashboard.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(),
    'module' => 'dashboard',
  );

  // Exported permission: access devel information.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: access site in maintenance mode.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: access site reports.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: access toolbar.
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'toolbar',
  );

  // Exported permission: access user profiles.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: administer actions.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer blocks.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: administer content types.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: administer dlts utilities.
  $permissions['administer dlts utilities'] = array(
    'name' => 'administer dlts utilities',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'dlts_utilities',
  );

  // Exported permission: administer features.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: administer filters.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: administer image styles.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: administer menu.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: administer modules.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer nodes.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: administer pathauto.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: administer permissions.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: administer restful.
  $permissions['administer restful'] = array(
    'name' => 'administer restful',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'restful',
  );

  // Exported permission: administer search.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(),
    'module' => 'search',
  );

  // Exported permission: administer services.
  $permissions['administer services'] = array(
    'name' => 'administer services',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: administer shortcuts.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: administer site configuration.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer software updates.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer taxonomy.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: administer themes.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer url aliases.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: administer users.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: administer uuid.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(),
    'module' => 'uuid',
  );

  // Exported permission: administer views.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: block IP addresses.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: bypass node access.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: cancel account.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: change own username.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: create article content.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create dlts_bitstream_set content.
  $permissions['create dlts_bitstream_set content'] = array(
    'name' => 'create dlts_bitstream_set content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create dlts_clip content.
  $permissions['create dlts_clip content'] = array(
    'name' => 'create dlts_clip content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create dlts_collection content.
  $permissions['create dlts_collection content'] = array(
    'name' => 'create dlts_collection content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create dlts_creativework content.
  $permissions['create dlts_creativework content'] = array(
    'name' => 'create dlts_creativework content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create dlts_partner content.
  $permissions['create dlts_partner content'] = array(
    'name' => 'create dlts_partner content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create dlts_playlist content.
  $permissions['create dlts_playlist content'] = array(
    'name' => 'create dlts_playlist content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create page content.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create url aliases.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: customize shortcut links.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: delete any article content.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any dlts_bitstream_set content.
  $permissions['delete any dlts_bitstream_set content'] = array(
    'name' => 'delete any dlts_bitstream_set content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any dlts_clip content.
  $permissions['delete any dlts_clip content'] = array(
    'name' => 'delete any dlts_clip content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any dlts_collection content.
  $permissions['delete any dlts_collection content'] = array(
    'name' => 'delete any dlts_collection content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any dlts_creativework content.
  $permissions['delete any dlts_creativework content'] = array(
    'name' => 'delete any dlts_creativework content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any dlts_partner content.
  $permissions['delete any dlts_partner content'] = array(
    'name' => 'delete any dlts_partner content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any dlts_playlist content.
  $permissions['delete any dlts_playlist content'] = array(
    'name' => 'delete any dlts_playlist content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any page content.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own article content.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own dlts_bitstream_set content.
  $permissions['delete own dlts_bitstream_set content'] = array(
    'name' => 'delete own dlts_bitstream_set content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own dlts_clip content.
  $permissions['delete own dlts_clip content'] = array(
    'name' => 'delete own dlts_clip content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own dlts_collection content.
  $permissions['delete own dlts_collection content'] = array(
    'name' => 'delete own dlts_collection content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own dlts_creativework content.
  $permissions['delete own dlts_creativework content'] = array(
    'name' => 'delete own dlts_creativework content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own dlts_partner content.
  $permissions['delete own dlts_partner content'] = array(
    'name' => 'delete own dlts_partner content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own dlts_playlist content.
  $permissions['delete own dlts_playlist content'] = array(
    'name' => 'delete own dlts_playlist content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own page content.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete revisions.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in 1.
  $permissions['delete terms in 1'] = array(
    'name' => 'delete terms in 1',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any article content.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any dlts_bitstream_set content.
  $permissions['edit any dlts_bitstream_set content'] = array(
    'name' => 'edit any dlts_bitstream_set content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any dlts_clip content.
  $permissions['edit any dlts_clip content'] = array(
    'name' => 'edit any dlts_clip content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any dlts_collection content.
  $permissions['edit any dlts_collection content'] = array(
    'name' => 'edit any dlts_collection content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any dlts_creativework content.
  $permissions['edit any dlts_creativework content'] = array(
    'name' => 'edit any dlts_creativework content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any dlts_partner content.
  $permissions['edit any dlts_partner content'] = array(
    'name' => 'edit any dlts_partner content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any dlts_playlist content.
  $permissions['edit any dlts_playlist content'] = array(
    'name' => 'edit any dlts_playlist content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any page content.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own article content.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own dlts_bitstream_set content.
  $permissions['edit own dlts_bitstream_set content'] = array(
    'name' => 'edit own dlts_bitstream_set content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own dlts_clip content.
  $permissions['edit own dlts_clip content'] = array(
    'name' => 'edit own dlts_clip content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own dlts_collection content.
  $permissions['edit own dlts_collection content'] = array(
    'name' => 'edit own dlts_collection content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own dlts_creativework content.
  $permissions['edit own dlts_creativework content'] = array(
    'name' => 'edit own dlts_creativework content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own dlts_partner content.
  $permissions['edit own dlts_partner content'] = array(
    'name' => 'edit own dlts_partner content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own dlts_playlist content.
  $permissions['edit own dlts_playlist content'] = array(
    'name' => 'edit own dlts_playlist content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own page content.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit terms in 1.
  $permissions['edit terms in 1'] = array(
    'name' => 'edit terms in 1',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: execute php code.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: get a system variable.
  $permissions['get a system variable'] = array(
    'name' => 'get a system variable',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: get any binary files.
  $permissions['get any binary files'] = array(
    'name' => 'get any binary files',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: get own binary files.
  $permissions['get own binary files'] = array(
    'name' => 'get own binary files',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: manage features.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: notify of path changes.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: perform unlimited index queries.
  $permissions['perform unlimited index queries'] = array(
    'name' => 'perform unlimited index queries',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: revert revisions.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: save file information.
  $permissions['save file information'] = array(
    'name' => 'save file information',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: search content.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(),
    'module' => 'search',
  );

  // Exported permission: select account cancellation method.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: set a system variable.
  $permissions['set a system variable'] = array(
    'name' => 'set a system variable',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: switch shortcut sets.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: switch users.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: use advanced search.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(),
    'module' => 'search',
  );

  // Exported permission: use ctools import.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(),
    'module' => 'ctools',
  );

  // Exported permission: use text format filtered_html.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format full_html.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: view mobile detect debug.
  $permissions['view mobile detect debug'] = array(
    'name' => 'view mobile detect debug',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'mobile_detect',
  );

  // Exported permission: view own unpublished content.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: view revisions.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: view the administration theme.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  return $permissions;
}

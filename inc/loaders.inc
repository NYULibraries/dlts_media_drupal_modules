<?php

/**
 * A wildcard loader for dlts_clip nodes, using the clip identifier.
 *
 * @parameter $identifier
 *  The value of field_identifier for a dlts_clip node.
 *
 * @return
 * A node object with the given value for field_identifier.
 *
 * @todo
 * field_identifier is supposed to be unique across all books, but we do
 * no checking of this assumption.
 * @todo
 * Does the query need to be tagged as node_access? We're checking node_access
 * via the menu system, but since the loader is called before access is
 * checked, adding a check here might save an entity_load if the user's not
 * going to have access anyway, at the cost of an extra JOIN here.
 */
function dlts_clip_load ( $identifier ) {

  $query = new EntityFieldQuery;

  $identifier = filter_xss($identifier);

  $result = $query
  ->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'dlts_clip')
  ->propertyCondition('status', 1)
  ->fieldCondition('field_identifier', 'value', $identifier, '=')
  ->addTag('node_access')
  ->execute();

  if ( !empty($result['node']) ) {
  	$keys = array_keys( $result['node'] );
  	return node_load( array_pop( $keys ) );
  }

  else {
  	return FALSE;
  }

}

/**
 * A wildcard loader for dlts_creativework nodes, using the CreativeWork identifier.
 *
 * @parameter $identifier
 *  The value of field_identifier for a dtls_creativework node.
 *
 * @return
 * A node object with the given value for field_identifier.
 *
 * @todo
 * field_identifier is supposed to be unique across all CreativeWork, but we do
 * no checking of this assumption.
 * @todo
 * Does the query need to be tagged as node_access? We're checking node_access
 * via the menu system, but since the loader is called before access is
 * checked, adding a check here might save an entity_load if the user's not
 * going to have access anyway, at the cost of an extra JOIN here.
 */
function dlts_creativework_load ( $identifier ) {

  $query = new EntityFieldQuery;

  $identifier = filter_xss($identifier);

  $result = $query
  	->entityCondition('entity_type', 'node')
  	->entityCondition('bundle', 'dlts_creativework')
  	->propertyCondition('status', 1)
  	->fieldCondition('field_identifier', 'value', $identifier, '=')
  	->addTag('node_access')
  	->execute();

  if ( !empty($result['node']) ) {
    $keys = array_keys( $result['node'] );
  	return node_load( array_pop( $keys ) );
  }

}

/**
 * A wildcard loader for dlts_playlist nodes, using the playlist identifier.
 *
 * @parameter $identifier
 *  The value of field_identifier for a dlts_playlist node.
 *
 * @return
 * A node object with the given value for field_identifier.
 *
 * @todo
 * field_identifier is supposed to be unique across all playlist, but we do
 * no checking of this assumption.
 * @todo
 * Does the query need to be tagged as node_access? We're checking node_access
 * via the menu system, but since the loader is called before access is
 * checked, adding a check here might save an entity_load if the user's not
 * going to have access anyway, at the cost of an extra JOIN here.
 */
function dlts_playlist_load ( $identifier ) {

  $query = new EntityFieldQuery;

  $identifier = filter_xss($identifier);

  $result = $query
   	->entityCondition('entity_type', 'node')
   	->entityCondition('bundle', 'dlts_playlist')
   	->propertyCondition('status', 1)
   	->fieldCondition('field_identifier', 'value', $identifier, '=')
   	->addTag('node_access')
   	->execute();

  if ( !empty($result['node']) ) {
    $keys = array_keys( $result['node'] );
   	return node_load( array_pop( $keys ) );
  }

}

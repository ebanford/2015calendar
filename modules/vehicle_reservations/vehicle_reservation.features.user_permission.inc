<?php
/**
 * @file
 * vehicle_reservation.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vehicle_reservation_user_default_permissions() {
  $permissions = array();

  // Exported permission: create vehicle_reservation content.
  $permissions['create vehicle_reservation content'] = array(
    'name' => 'create vehicle_reservation content',
    'roles' => array(
      0 => 'Vehicle Admin',
      1 => 'Vehicle Users',
      2 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any vehicle_reservation content.
  $permissions['delete any vehicle_reservation content'] = array(
    'name' => 'delete any vehicle_reservation content',
    'roles' => array(
      0 => 'Vehicle Admin',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own vehicle_reservation content.
  $permissions['delete own vehicle_reservation content'] = array(
    'name' => 'delete own vehicle_reservation content',
    'roles' => array(
      0 => 'Vehicle Admin',
      1 => 'Vehicle Users',
      2 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any vehicle_reservation content.
  $permissions['edit any vehicle_reservation content'] = array(
    'name' => 'edit any vehicle_reservation content',
    'roles' => array(
      0 => 'Vehicle Admin',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own vehicle_reservation content.
  $permissions['edit own vehicle_reservation content'] = array(
    'name' => 'edit own vehicle_reservation content',
    'roles' => array(
      0 => 'Vehicle Admin',
      1 => 'Vehicle Users',
      2 => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}

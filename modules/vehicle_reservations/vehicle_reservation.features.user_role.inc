<?php
/**
 * @file
 * vehicle_reservation.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function vehicle_reservation_user_default_roles() {
  $roles = array();

  // Exported role: Vehicle Admin.
  $roles['Vehicle Admin'] = array(
    'name' => 'Vehicle Admin',
    'weight' => '4',
  );

  // Exported role: Vehicle Users.
  $roles['Vehicle Users'] = array(
    'name' => 'Vehicle Users',
    'weight' => '3',
  );

  return $roles;
}

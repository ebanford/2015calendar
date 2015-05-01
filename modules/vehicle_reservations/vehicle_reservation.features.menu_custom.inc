<?php
/**
 * @file
 * vehicle_reservation.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function vehicle_reservation_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-vehicle-reservation-menu.
  $menus['menu-vehicle-reservation-menu'] = array(
    'menu_name' => 'menu-vehicle-reservation-menu',
    'title' => 'Vehicle Reservation Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Vehicle Reservation Menu');


  return $menus;
}

<?php
/**
 * @file
 * vehicle_reservation.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function vehicle_reservation_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-vehicle-reservation-menu:node/add/vehicle-reservation
  $menu_links['menu-vehicle-reservation-menu:node/add/vehicle-reservation'] = array(
    'menu_name' => 'menu-vehicle-reservation-menu',
    'link_path' => 'node/add/vehicle-reservation',
    'router_path' => 'node/add/vehicle-reservation',
    'link_title' => 'Add Vehicle Reservation',
    'options' => array(
      'query' => array(
        'destination' => 'vehicle/calendar',
      ),
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '10',
  );
  // Exported menu link: menu-vehicle-reservation-menu:vehicle/calendar
  $menu_links['menu-vehicle-reservation-menu:vehicle/calendar'] = array(
    'menu_name' => 'menu-vehicle-reservation-menu',
    'link_path' => 'vehicle/calendar',
    'router_path' => 'vehicle/calendar',
    'link_title' => 'Vehicle Calendar',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: navigation:node/add/vehicle-reservation
  $menu_links['navigation:node/add/vehicle-reservation'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/vehicle-reservation',
    'router_path' => 'node/add/vehicle-reservation',
    'link_title' => 'Vehicle reservation',
    'options' => array(
      'attributes' => array(
        'title' => 'Vehicle Reservation entries',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:vehicle/calendar
  $menu_links['navigation:vehicle/calendar'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'vehicle/calendar',
    'router_path' => 'vehicle/calendar',
    'link_title' => 'Week Calendar',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add Vehicle Reservation');
  t('Vehicle Calendar');
  t('Vehicle reservation');
  t('Week Calendar');


  return $menu_links;
}

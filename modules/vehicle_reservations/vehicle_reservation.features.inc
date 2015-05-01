<?php
/**
 * @file
 * vehicle_reservation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function vehicle_reservation_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function vehicle_reservation_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function vehicle_reservation_node_info() {
  $items = array(
    'vehicle_reservation' => array(
      'name' => t('Vehicle reservation'),
      'base' => 'node_content',
      'description' => t('Vehicle Reservation entries'),
      'has_title' => '1',
      'title_label' => t('Travel Destination'),
      'help' => '',
    ),
  );
  return $items;
}

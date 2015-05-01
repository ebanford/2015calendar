<?php
/**
 * @file
 * vehicle_reservation.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function vehicle_reservation_taxonomy_default_vocabularies() {
  return array(
    'fleet_vehicles' => array(
      'name' => 'FleetVehicles',
      'machine_name' => 'fleet_vehicles',
      'description' => 'Vehicles in fleet',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}

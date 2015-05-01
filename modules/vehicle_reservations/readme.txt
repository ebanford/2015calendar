Vehicle Reservations Setup

Requirements

* Can book three vehicles on a calendar
* Reservations don't overlap
* Role for vehicle users
* Admin can export data for custom timeframe
* Easy to use on mobile device
* Can add default account to user profile

Needed Modules:

calendar
colors
date views
field_default_token (for default account)
views_data_export

There are aspects of the Vehicle Reservation feature that can not be saved in code, and must be set up when the feature is installed.

* enable module Vehicle Reservation
* enable module Views UI 

* add taxonomy terms fo Fleet Vehicles
* admin/structure/taxonomy
** Truck
** Blue Malibu
** Silver Malibu

* edit blocks
** admin/structure/block
** Add these to left sidebar, in this order:
*** Vehicle Reservation Menu
*** 'View: Vehicle Calendar: My reservations' block 
*** 'vehicle_calendar-views_data_export_1' block

** export is only for roles Admin and Vehicle Admin
** all get this for page restrictions:

vehicle
vehicle/*
vehicles
vehicles/* 

* Views

** admin/structure/views
** Edit Vehicle Calendar view
** Month Calendar
** Format, Show, Settings, All displays, Stripes based on taxonomy
** Since there is only one taxon, no need to set which
** Blue Malibu: #0000ff
** Silver Malibu: #c0c0c0
** Truck: #ff0000
** save
** do again for Day Calendar
** save

* URL Alias
** admin/config/search/path
** alias for taxon not set because just added terms
* Edit for each term:
** vehicles/blue-malibu
** vehicles/silver-malibu
** vehicles/truck

* disable module Views UI

<?php
/**
 * @file
 * vehicle_reservation.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function vehicle_reservation_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'vehicle_calendar';
  $view->description = '';
  $view->tag = 'Calendar';
  $view->base_table = 'node';
  $view->human_name = 'Vehicle Calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Vehicle Calendar';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create vehicle_reservation content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Export Trip Data';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_driver' => 'field_driver',
    'field_which_vehicle' => 'field_which_vehicle',
  );
  $handler->display->display_options['row_options']['colors']['legend'] = 'taxonomy';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'page' => '#ffffff',
    'cals_news' => '#ffffff',
    'cals_people_profile' => '#ffffff',
    'cals_slide' => '#ffffff',
    'vehicle_reservation' => '#ffffff',
    'webform' => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['taxonomy_field'] = 'field_which_vehicle';
  $handler->display->display_options['row_options']['colors']['calendar_colors_vocabulary'] = array(
    'field_which_vehicle' => '4',
  );
  $handler->display->display_options['row_options']['colors']['calendar_colors_taxonomy'] = array(
    4 => '#0000ff',
    5 => '#c0c0c0',
    3 => '#ff0000',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Driver */
  $handler->display->display_options['fields']['field_driver']['id'] = 'field_driver';
  $handler->display->display_options['fields']['field_driver']['table'] = 'field_data_field_driver';
  $handler->display->display_options['fields']['field_driver']['field'] = 'field_driver';
  $handler->display->display_options['fields']['field_driver']['label'] = '';
  $handler->display->display_options['fields']['field_driver']['element_label_colon'] = FALSE;
  /* Field: Content: Which Vehicle */
  $handler->display->display_options['fields']['field_which_vehicle']['id'] = 'field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['table'] = 'field_data_field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['field'] = 'field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['label'] = '';
  $handler->display->display_options['fields']['field_which_vehicle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_which_vehicle']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Travel Date */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_start_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Sort criterion: Content: Travel Date -  start date (field_start_date) */
  $handler->display->display_options['sorts']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['sorts']['field_start_date_value']['field'] = 'field_start_date_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Month Calendar */
  $handler = $view->new_display('page', 'Month Calendar', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Driver */
  $handler->display->display_options['fields']['field_driver']['id'] = 'field_driver';
  $handler->display->display_options['fields']['field_driver']['table'] = 'field_data_field_driver';
  $handler->display->display_options['fields']['field_driver']['field'] = 'field_driver';
  $handler->display->display_options['fields']['field_driver']['label'] = '';
  $handler->display->display_options['fields']['field_driver']['element_label_colon'] = FALSE;
  /* Field: Content: Which Vehicle */
  $handler->display->display_options['fields']['field_which_vehicle']['id'] = 'field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['table'] = 'field_data_field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['field'] = 'field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['label'] = '';
  $handler->display->display_options['fields']['field_which_vehicle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_which_vehicle']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Travel Date */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_start_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_start_date.field_start_date_value' => 'field_data_field_start_date.field_start_date_value',
  );
  $handler->display->display_options['path'] = 'vehicle/calendar/month';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Month Calendar';
  $handler->display->display_options['menu']['weight'] = '6';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Calendar';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Week Calendar */
  $handler = $view->new_display('page', 'Week Calendar', 'page_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'week';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Driver */
  $handler->display->display_options['fields']['field_driver']['id'] = 'field_driver';
  $handler->display->display_options['fields']['field_driver']['table'] = 'field_data_field_driver';
  $handler->display->display_options['fields']['field_driver']['field'] = 'field_driver';
  $handler->display->display_options['fields']['field_driver']['label'] = '';
  $handler->display->display_options['fields']['field_driver']['element_label_colon'] = FALSE;
  /* Field: Content: Which Vehicle */
  $handler->display->display_options['fields']['field_which_vehicle']['id'] = 'field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['table'] = 'field_data_field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['field'] = 'field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['label'] = '';
  $handler->display->display_options['fields']['field_which_vehicle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_which_vehicle']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Travel Date */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_start_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'week';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_start_date.field_start_date_value' => 'field_data_field_start_date.field_start_date_value',
  );
  $handler->display->display_options['path'] = 'vehicle/calendar/week';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Week Calendar';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Week Calendar';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Day Calendar */
  $handler = $view->new_display('page', 'Day Calendar', 'page_3');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'day';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'day';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['colors']['legend'] = 'taxonomy';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'page' => '#ffffff',
    'cals_news' => '#ffffff',
    'cals_people_profile' => '#ffffff',
    'cals_slide' => '#ffffff',
    'vehicle_reservation' => '#ffffff',
    'webform' => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['taxonomy_field'] = 'field_which_vehicle';
  $handler->display->display_options['row_options']['colors']['calendar_colors_vocabulary'] = array(
    'field_which_vehicle' => '4',
  );
  $handler->display->display_options['row_options']['colors']['calendar_colors_taxonomy'] = array(
    4 => '#0000ff',
    5 => '#c0c0c0',
    3 => '#ff0000',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Driver */
  $handler->display->display_options['fields']['field_driver']['id'] = 'field_driver';
  $handler->display->display_options['fields']['field_driver']['table'] = 'field_data_field_driver';
  $handler->display->display_options['fields']['field_driver']['field'] = 'field_driver';
  $handler->display->display_options['fields']['field_driver']['label'] = '';
  $handler->display->display_options['fields']['field_driver']['element_label_colon'] = FALSE;
  /* Field: Content: Which Vehicle */
  $handler->display->display_options['fields']['field_which_vehicle']['id'] = 'field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['table'] = 'field_data_field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['field'] = 'field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['label'] = '';
  $handler->display->display_options['fields']['field_which_vehicle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_which_vehicle']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Travel Date */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_start_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'day';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_start_date.field_start_date_value' => 'field_data_field_start_date.field_start_date_value',
  );
  $handler->display->display_options['path'] = 'vehicle/calendar/day';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Day Calendar';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Year */
  $handler = $view->new_display('page', 'Year', 'page');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'year';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'year';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['colors']['legend'] = 'taxonomy';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'page' => '#ffffff',
    'cals_news' => '#ffffff',
    'cals_people_profile' => '#ffffff',
    'cals_slide' => '#ffffff',
    'vehicle_reservation' => '#ffffff',
    'webform' => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['taxonomy_field'] = 'field_which_vehicle';
  $handler->display->display_options['row_options']['colors']['calendar_colors_vocabulary'] = array(
    'field_which_vehicle' => '6',
  );
  $handler->display->display_options['row_options']['colors']['calendar_colors_taxonomy'] = array(
    41 => '#0000ff',
    46 => '#c0c0c0',
    36 => '#ff0000',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Travel Date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['field_start_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['delta_offset'] = '0';
  /* Field: Content: Which Vehicle */
  $handler->display->display_options['fields']['field_which_vehicle']['id'] = 'field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['table'] = 'field_data_field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['field'] = 'field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'year';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_start_date.field_start_date_value' => 'field_data_field_start_date.field_start_date_value',
  );
  $handler->display->display_options['path'] = 'vehicle/calendar/year';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Year';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'mini';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '1';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_start_date.field_start_date_value' => 'field_data_field_start_date.field_start_date_value',
  );

  /* Display: Upcoming */
  $handler = $view->new_display('block', 'Upcoming', 'block_2');
  $handler->display->display_options['display_description'] = 'Upcoming events block';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_start_date.field_start_date_value' => 'field_data_field_start_date.field_start_date_value',
  );

  /* Display: Export trip data */
  $handler = $view->new_display('views_data_export', 'Export trip data', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'Export past 30 days';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%timestamp-full.%view.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Driver */
  $handler->display->display_options['fields']['field_driver']['id'] = 'field_driver';
  $handler->display->display_options['fields']['field_driver']['table'] = 'field_data_field_driver';
  $handler->display->display_options['fields']['field_driver']['field'] = 'field_driver';
  /* Field: Content: Account Number */
  $handler->display->display_options['fields']['field_account_number']['id'] = 'field_account_number';
  $handler->display->display_options['fields']['field_account_number']['table'] = 'field_data_field_account_number';
  $handler->display->display_options['fields']['field_account_number']['field'] = 'field_account_number';
  /* Field: Content: Which Vehicle */
  $handler->display->display_options['fields']['field_which_vehicle']['id'] = 'field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['table'] = 'field_data_field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['field'] = 'field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Beginning Mileage */
  $handler->display->display_options['fields']['field_beginning_mileage']['id'] = 'field_beginning_mileage';
  $handler->display->display_options['fields']['field_beginning_mileage']['table'] = 'field_data_field_beginning_mileage';
  $handler->display->display_options['fields']['field_beginning_mileage']['field'] = 'field_beginning_mileage';
  /* Field: Content: Travel Date */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = 'Start Date';
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Travel Date */
  $handler->display->display_options['fields']['field_start_date_2']['id'] = 'field_start_date_2';
  $handler->display->display_options['fields']['field_start_date_2']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_2']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_2']['label'] = 'End Date';
  $handler->display->display_options['fields']['field_start_date_2']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Ending Mileage */
  $handler->display->display_options['fields']['field_ending_mileage']['id'] = 'field_ending_mileage';
  $handler->display->display_options['fields']['field_ending_mileage']['table'] = 'field_data_field_ending_mileage';
  $handler->display->display_options['fields']['field_ending_mileage']['field'] = 'field_ending_mileage';
  /* Field: Content: Fuel level at start of trip */
  $handler->display->display_options['fields']['field_fuel_level_at_start_of_tri']['id'] = 'field_fuel_level_at_start_of_tri';
  $handler->display->display_options['fields']['field_fuel_level_at_start_of_tri']['table'] = 'field_data_field_fuel_level_at_start_of_tri';
  $handler->display->display_options['fields']['field_fuel_level_at_start_of_tri']['field'] = 'field_fuel_level_at_start_of_tri';
  /* Field: Content: Comment */
  $handler->display->display_options['fields']['field_comment']['id'] = 'field_comment';
  $handler->display->display_options['fields']['field_comment']['table'] = 'field_data_field_comment';
  $handler->display->display_options['fields']['field_comment']['field'] = 'field_comment';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Travel Date -  start date (field_start_date) */
  $handler->display->display_options['sorts']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['sorts']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Travel Date -  start date (field_start_date) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_start_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator_id'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['label'] = 'Travel Date ';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['identifier'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['remember_roles'] = array(
    2 => 0,
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_start_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_start_date_value']['year_range'] = '-1:+1';
  $handler->display->display_options['path'] = 'vehicle/calendar/export-all';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page_1' => 0,
    'page_2' => 0,
    'page_3' => 0,
    'page' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'page_4' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: My reservations */
  $handler = $view->new_display('block', 'My reservations', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My reservations';
  $handler->display->display_options['display_description'] = 'List of my vehicle reesrvations';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['type'] = 'ol';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Travel Date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['field_start_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['delta_offset'] = '0';
  /* Field: Content: Driver */
  $handler->display->display_options['fields']['field_driver']['id'] = 'field_driver';
  $handler->display->display_options['fields']['field_driver']['table'] = 'field_data_field_driver';
  $handler->display->display_options['fields']['field_driver']['field'] = 'field_driver';
  $handler->display->display_options['fields']['field_driver']['label'] = '';
  $handler->display->display_options['fields']['field_driver']['element_label_colon'] = FALSE;
  /* Field: Content: Which Vehicle */
  $handler->display->display_options['fields']['field_which_vehicle']['id'] = 'field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['table'] = 'field_data_field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['field'] = 'field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['label'] = '';
  $handler->display->display_options['fields']['field_which_vehicle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_which_vehicle']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now - 14 days';
  $handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_start_date.field_start_date_value' => 'field_data_field_start_date.field_start_date_value',
  );

  /* Display: Week List */
  $handler = $view->new_display('page', 'Week List', 'page_4');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'week';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Driver */
  $handler->display->display_options['fields']['field_driver']['id'] = 'field_driver';
  $handler->display->display_options['fields']['field_driver']['table'] = 'field_data_field_driver';
  $handler->display->display_options['fields']['field_driver']['field'] = 'field_driver';
  $handler->display->display_options['fields']['field_driver']['label'] = '';
  $handler->display->display_options['fields']['field_driver']['element_label_colon'] = FALSE;
  /* Field: Content: Which Vehicle */
  $handler->display->display_options['fields']['field_which_vehicle']['id'] = 'field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['table'] = 'field_data_field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['field'] = 'field_which_vehicle';
  $handler->display->display_options['fields']['field_which_vehicle']['label'] = '';
  $handler->display->display_options['fields']['field_which_vehicle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_which_vehicle']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Travel Date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'week';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_start_date.field_start_date_value' => 'field_data_field_start_date.field_start_date_value',
  );
  $handler->display->display_options['path'] = 'vehicle/calendar/list';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'List Week';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['vehicle_calendar'] = $view;

  return $export;
}

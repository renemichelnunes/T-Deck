#pragma once
#include <lvgl.h>

/*home screen*/
lv_obj_t * frm_home;
lv_obj_t * frm_home_symbol_lbl;
lv_obj_t * frm_home_title;
lv_obj_t * frm_home_title_lbl;
lv_obj_t * frm_home_btn_contacts;
lv_obj_t * frm_home_btn_contacts_lbl;
lv_obj_t * btn_test;
lv_obj_t * lbl_btn_test;
lv_obj_t * frm_home_btn_settings;
lv_obj_t * frm_home_btn_settings_lbl;
lv_obj_t * frm_home_contacts_img;
lv_obj_t * frm_home_frm_date_time;
lv_obj_t * frm_home_time_lbl;
lv_obj_t * frm_home_date_lbl;
lv_obj_t * frm_home_bat_lbl;
lv_obj_t * frm_home_wifi_lbl;
lv_obj_t * frm_home_activity_led;
lv_obj_t * frm_home_rssi_chart;
lv_chart_series_t * frm_home_rssi_series;
lv_chart_series_t  * frm_home_snr_series;

/*contacts form*/
lv_obj_t * frm_contacts;
lv_obj_t * frm_contacts_btn_back;
lv_obj_t * frm_contacts_btn_back_lbl;
lv_obj_t * frm_contacts_list;
lv_obj_t * frm_contacts_btn_add;
lv_obj_t * frm_contacts_btn_add_lbl;
lv_obj_t * frm_contatcs_btn_title;
lv_obj_t * frm_contatcs_btn_title_lbl;
/*add contact form*/
lv_obj_t * frm_add_contact;
lv_obj_t * frm_add_contacts_btn_title;
lv_obj_t * frm_add_contacts_btn_title_lbl;
lv_obj_t * frm_add_contact_textarea_id;
lv_obj_t * frm_add_contact_textarea_name;
lv_obj_t * frm_add_contact_textarea_key;
lv_obj_t * btn_frm_add_contatcs_close;
lv_obj_t * lbl_btn_frm_add_contacts_close;
lv_obj_t * frm_add_contacts_btn_add;
lv_obj_t * frm_add_contacts_btn_add_lbl;
/*edit contact form*/
lv_obj_t * frm_edit_contacts;
lv_obj_t * frm_edit_btn_title;
lv_obj_t * frm_edit_btn_title_lbl;
lv_obj_t * frm_edit_text_ID;
lv_obj_t * frm_edit_text_name;
lv_obj_t * frm_edit_text_key;
lv_obj_t * frm_edit_btn_ok;
lv_obj_t * frm_edit_btn_ok_lbl;
lv_obj_t * frm_edit_btn_back;
lv_obj_t * frm_edit_btn_back_lbl;
lv_obj_t * frm_edit_btn_del;
lv_obj_t * frm_edit_btn_del_lbl;
/*chat form*/
lv_obj_t * frm_chat;
lv_group_t * frm_chat_group;
lv_obj_t * frm_chat_btn_title;
lv_obj_t * frm_chat_btn_title_lbl;
lv_obj_t * frm_chat_list;
lv_obj_t * frm_chat_text_ans;
lv_obj_t * frm_chat_btn_send;
lv_obj_t * frm_chat_btn_send_lbl;
lv_obj_t * frm_chat_btn_back;
lv_obj_t * frm_chat_btn_back_lbl;
lv_obj_t * frm_chat_btn_kb;
lv_obj_t * frm_chat_btn_kb_lbl;
lv_obj_t * kb;
/*settings form*/
lv_obj_t * frm_settings;
lv_obj_t * frm_settings_btn_title;
lv_obj_t * frm_settings_btn_title_lbl;
lv_obj_t * frm_settings_btn_back;
lv_obj_t * frm_settings_btn_back_lbl;
lv_obj_t * frm_settings_name;
lv_obj_t * frm_settings_id;
lv_obj_t * frm_settings_key;
lv_obj_t * frm_settings_id_section;
lv_obj_t * frm_settings_id_cont;
lv_obj_t * frm_settings_id_page;
lv_obj_t * frm_settings_obj_id;
lv_obj_t * frm_settings_btn_generate;
lv_obj_t * frm_settings_btn_generate_lbl;
lv_obj_t * frm_settings_btn_generate_key;
lv_obj_t * frm_settings_btn_generate_key_lbl;
lv_obj_t * frm_settings_admin_password;
lv_obj_t * frm_settings_dx_section;
lv_obj_t * frm_settings_dx_page;
lv_obj_t * frm_settings_obj_dx;
lv_obj_t * frm_settings_switch_dx;
lv_obj_t * frm_settings_switch_dx_lbl;
lv_obj_t * frm_settings_day;
lv_obj_t * frm_settings_month;
lv_obj_t * frm_settings_year;
lv_obj_t * frm_settings_hour;
lv_obj_t * frm_settings_minute;
lv_obj_t * frm_settings_date_lbl;
lv_obj_t * frm_settings_time_lbl;
lv_obj_t * frm_settings_btn_setDate;
lv_obj_t * frm_settings_btn_setDate_lbl;
lv_obj_t * frm_settings_obj_ui;
lv_obj_t * frm_settings_color;
lv_obj_t * frm_settings_btn_color_lbl;
lv_obj_t * frm_settings_btn_applycolor;
lv_obj_t * frm_settings_btn_applycolor_lbl;
lv_obj_t * frm_settings_btn_wifi;
lv_obj_t * frm_settings_btn_wifi_lbl;
lv_obj_t * frm_settings_wifi_ssid;
lv_obj_t * frm_settings_wifi_auth;
lv_obj_t * frm_settings_wifi_ch;
lv_obj_t * frm_settings_wifi_rssi;
lv_obj_t * frm_settings_wifi_mac;
lv_obj_t * frm_settings_wifi_ip;
lv_obj_t * frm_settings_wifi_mask;
lv_obj_t * frm_settings_wifi_gateway;
lv_obj_t * frm_settings_wifi_dns;
lv_obj_t * frm_settings_wifi_http_btn;
lv_obj_t * frm_settings_wifi_http_label;
lv_obj_t * frm_settings_btn_wifi_conf;
lv_obj_t * frm_settings_btn_wifi_conf_lbl;
lv_obj_t * frm_settings_brightness_roller;
lv_obj_t * frm_settings_brightness_lbl;
lv_obj_t * frm_settings_brightness_section;
lv_obj_t * frm_settings_brightness_page;
lv_obj_t * frm_settings_obj_brightness;
lv_obj_t * frm_settings_menu;
lv_obj_t * frm_settings_context;
lv_obj_t * frm_settings_root_page;
lv_obj_t * frm_settings_root_section;
lv_obj_t * frm_settings_timezone;
/*notification form*/
lv_obj_t * frm_not;
lv_obj_t * frm_not_lbl;
lv_obj_t * frm_not_symbol_lbl;
/*form wifi*/
lv_obj_t * frm_wifi;
lv_obj_t * frm_wifi_btn_title;
lv_obj_t * frm_wifi_btn_title_lbl;
lv_obj_t * frm_wifi_list;
lv_obj_t * frm_wifi_btn_scan;
lv_obj_t * frm_wifi_btn_scan_lbl;
lv_obj_t * frm_wifi_btn_back;
lv_obj_t * frm_wifi_btn_back_lbl;
lv_obj_t * frm_wifi_connected_to_lbl;
/*form wifi auth simple*/
lv_obj_t * frm_wifi_simple;
lv_obj_t * frm_wifi_simple_title_lbl;
lv_obj_t * frm_wifi_simple_ta_pass;
lv_obj_t * frm_wifi_simple_btn_connect;
lv_obj_t * frm_wifi_simple_btn_connect_lbl;
lv_obj_t * frm_wifi_simple_btn_see;
lv_obj_t * frm_wifi_simple_btn_see_lbl;
lv_obj_t * frm_wifi_simple_btn_back;
lv_obj_t * frm_wifi_simple_btn_back_lbl;
/*form wifi auth login*/
lv_obj_t * frm_wifi_login;
lv_obj_t * frm_wifi_login_title_lbl;
lv_obj_t * frm_wifi_login_ta_login;
lv_obj_t * frm_wifi_login_ta_pass;
lv_obj_t * frm_wifi_login_btn_connect;
lv_obj_t * frm_wifi_login_btn_connect_lbl;
lv_obj_t * frm_wifi_login_btn_see;
lv_obj_t * frm_wifi_login_btn_see_lbl;
lv_obj_t * frm_wifi_login_btn_back;
lv_obj_t * frm_wifi_login_btn_back_lbl;
/*form forget network*/
lv_obj_t * frm_forget_net;
lv_obj_t * frm_forget_net_btn_forget;
lv_obj_t * frm_forget_net_btn_forget_lbl;
lv_obj_t * frm_forget_net_btn_back;
lv_obj_t * frm_forget_net_btn_back_lbl;
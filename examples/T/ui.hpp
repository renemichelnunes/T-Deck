#pragma once
#include <lvgl.h>

/*home screen*/
lv_obj_t * init_screen;
lv_obj_t * btn_contacts;
lv_obj_t * lbl_btn_contacts;
lv_obj_t * btn_test;
lv_obj_t * lbl_btn_test;
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
lv_obj_t * frm_edit_btn_ok;
lv_obj_t * frm_edit_btn_ok_lbl;
lv_obj_t * frm_edit_btn_back;
lv_obj_t * frm_edit_btn_back_lbl;
lv_obj_t * frm_edit_btn_del;
lv_obj_t * frm_edit_btn_del_lbl;
/*chat form*/
lv_obj_t * frm_chat;
lv_obj_t * frm_chat_btn_title;
lv_obj_t * frm_chat_btn_title_lbl;
lv_obj_t * frm_chat_list;
lv_obj_t * frm_chat_text_ans;
lv_obj_t * frm_chat_btn_send;
lv_obj_t * frm_chat_btn_send_lbl;
lv_obj_t * frm_chat_btn_back;
lv_obj_t * frm_chat_btn_back_lbl;
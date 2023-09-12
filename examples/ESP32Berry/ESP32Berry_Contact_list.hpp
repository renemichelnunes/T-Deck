#pragma once
#include "ESP32Berry_Config.hpp"
#include "ESP32Berry_AppBase.hpp"
#include "Contacts.hpp"

class AppContactList : public AppBase {
private:
  lv_style_t msgStyle;
  lv_obj_t *addBtn;
  lv_obj_t *list;
  int display_width;
  void draw_ui();

public:
  AppContactList(Display *display, System *system, Network *network, const char *title);
  ~AppContactList();
  Contact_list contact_list;
  void refresh_contact_list();
  void add_contact();
  void tg_event_handler(lv_event_t *e);
  lv_obj_t * getList();
  void close_app();
};
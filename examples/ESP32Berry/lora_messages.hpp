#pragma once
#include <vector>
#include <Arduino.h>

struct lora_packet{
    char id[7];
    char msg[200];
    char status[7];
};

struct lora_contact_messages{
    char id[7];
    std::vector <lora_packet> messages;
};

class lora_incomming_messages{
  private:
    std::vector <lora_contact_messages> messages;
  public:
    lora_incomming_messages();
    ~lora_incomming_messages();
    bool addMessage(lora_packet packet);
    uint32_t find(char * id);
    std::vector <lora_packet> getMessages(char * id);
};
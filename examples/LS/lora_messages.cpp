#include <lora_messages.hpp>
#include <stdio.h>
#include <cstring>

void lora_incomming_packets::add(lora_packet pkt){
    try{
        this->lora_packets.push_back(pkt);
    }
    catch(std::exception &e){
        Serial.println("lora_incomming_packets::add error ");
        Serial.println(e.what());
    }
}

lora_packet lora_incomming_packets::get(){
    lora_packet p = this->lora_packets[0];
    this->lora_packets.erase(this->lora_packets.begin());
    return p;
}

bool lora_incomming_packets::has_packets(){
    return this->lora_packets.size() > 0;
}

void lora_outgoing_packets::add(lora_packet pkt){
    this->lora_packets.push_back(pkt);
}

bool lora_outgoing_packets::has_packets(){
    return this->lora_packets.size() > 0;
}

bool lora_outgoing_packets::del(const char * id){
    if(this->has_packets())
        for(uint8_t i = 0; i < this->lora_packets.size(); i++)
            if(strcmp(this->lora_packets[i].id, id) == 0){
                this->lora_packets.erase(this->lora_packets.begin() + i);
                return true;
            }
        return false;
}

lora_outgoing_packets::lora_outgoing_packets(int16_t (*transmit_func_callback)(uint8_t *, size_t)){
    this->transmit_func_callback = transmit_func_callback;
}

/// @brief Creates a string with a sequence of 6 chars between letters and numbers randomly, the contact's id.
/// @param size 
/// @return std::string
std::string generate_ID(uint8_t size){
  srand(time(NULL));
  static const char alphanum[] = "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  std::string ss;

  for (int i = 0; i < size; ++i) {
    ss[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
  }
  return ss;
}

lora_packet * lora_outgoing_packets::check_packets(){
    uint32_t r = 100;
    void * pkt = malloc(sizeof(lora_packet));
    uint32_t pkt_size = 0;
    
    // Calculate in miliseconds between 1 and 5 seconds
    r = rand() % 50;
    if(r < 10)
        r += 10;
    r *= 100;
    // Remove the confirmed packets and set a new timeout for the unconfirmed ones.
    for(int i = 0; i < this->lora_packets.size(); i++){
        // If a message gets an ack, delete it, if not, update his timeout ack.
        if(this->lora_packets[i].confirmed){
            Serial.printf("processTransmitingPackets - %s confirmed", this->lora_packets[i].id);
            this->lora_packets.erase(this->lora_packets.begin() + i);
        }else if(this->lora_packets[i].timeout > millis() && !this->lora_packets[i].confirmed){ // If time is up and not confirmed, renew the timeout (between 1 and 5 seconds, increments in hundreds of miliseconds)
            this->lora_packets[i].timeout = millis() + r;
        }
    }

    for(int i = 0; i < this->lora_packets.size(); i++){
        if(this->lora_packets[i].timeout < millis()){
            // Creating a packet accordingly by the type
            if(lora_packets[i].type == LORA_PKT_ANNOUNCE){
                pkt_size = sizeof(lora_packet_announce);
                memcpy(pkt, (void*)'\0', sizeof(lora_packet));
                // Generating packet info
                strcpy(((struct lora_packet_announce *)pkt)->sender, lora_packets[i].sender);
                ((struct lora_packet_announce *)pkt)->type = lora_packets[i].type;
                strcpy(((struct lora_packet_announce *)pkt)->id, generate_ID(6).c_str());
                Serial.println("Announcement packet ready");
            }
            else if(lora_packets[i].type == LORA_PKT_ACK){
                pkt_size = sizeof(lora_packet_ack);
                memcpy(pkt, (void*)'\0', sizeof(lora_packet));
                // Generating packet info
                strcpy(((struct lora_packet_ack *)pkt)->id, generate_ID(6).c_str());
                strcpy(((struct lora_packet_ack *)pkt)->sender, lora_packets[i].sender);
                strcpy(((struct lora_packet_ack *)pkt)->destiny, lora_packets[i].destiny);
                ((struct lora_packet_ack *)pkt)->type = lora_packets[i].type;
                // destiny message ID to ack
                strcpy(((struct lora_packet_ack *)pkt)->status, lora_packets[i].status); 
                Serial.println("ACK packet ready");
            }
            else if(lora_packets[i].type == LORA_PKT_DATA){
                pkt_size = sizeof(lora_packet_data);
                memcpy(pkt, (void*)'\0', sizeof(lora_packet));
                // Generating packet info
                ((struct lora_packet_data *)pkt)->type = lora_packets[i].type;
                strcpy(((struct lora_packet_data *)pkt)->id, generate_ID(6).c_str());
                strcpy(((struct lora_packet_data *)pkt)->sender, lora_packets[i].sender);
                strcpy(((struct lora_packet_data *)pkt)->destiny, lora_packets[i].destiny);
                ((struct lora_packet_data *)pkt)->hops = 10;
                strncpy(((struct lora_packet_data *)pkt)->data, lora_packets[i].data, lora_packets[i].data_size);
                ((struct lora_packet_data *)pkt)->data_size = lora_packets[i].data_size;
                Serial.println("Data packet ready");
            }
            else if(lora_packets[i].type == LORA_PKT_PING){

            }
            else if(lora_packets[i].type == LORA_PKT_COMM){

            }

            // Transmit the packet.
            if(pkt != NULL){
                this->transmit_func_callback((uint8_t*)pkt, pkt_size);
            }
        }
    }
    free(pkt);
    pkt = NULL;
}

bool lora_pkt_history::add(char * pkt_id){
    if(this->history.size() > 20)
        this->history.erase(this->history.begin());
    try{
        this->history.push_back(pkt_id);
        return true;
    }catch(std::exception &e){
        Serial.print("lora_pkt_history::add error ");
        Serial.println(e.what());
        return false;
    }
}

bool lora_pkt_history::exists(char * pkt_id){
    for(uint8_t i = 0; i < this->history.size(); i++)
        if(strcmp(this->history[i], pkt_id) == 0)
            return true;
    return false;
}

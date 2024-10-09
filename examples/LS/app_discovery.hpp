#pragma once
#include <Arduino.h>
#include <vector>

#define APP_DISCOVERY 1

class discovery_node{
    public:
        char node_id[7];
        uint8_t hops;
        discovery_node(char * node_id, uint8_t hops);
};

class discovery{
    private:
        std::vector<discovery_node> list;
    public:
        bool exists(char * node_id);
        void add(discovery_node node);
        discovery_node * getNode(char * node_id);
        uint32_t deliveryTime(char * node_id);
        uint32_t responseTime(char * node_id);
};
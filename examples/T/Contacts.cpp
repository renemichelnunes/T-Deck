#include "Contacts.hpp"
#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>
/// @brief Constructor with name and id as parameters.
/// @param name 
/// @param id 
Contact::Contact(String name, String id){
    this->name = name;
    this->id = id;
}
/// @brief Contructor.
Contact::Contact(){
    
}
/// @brief Get the name of the contact.
/// @return String
String Contact::getName(){
    return this->name;
}
/// @brief Get the ID of the contact.
/// @return String
String Contact::getID(){
    return this->id;
}
/// @brief Get the key of the contact.
/// @return String
String Contact::getKey(){
    return this->key;
}
/// @brief Used with an iterator to compare contacts by ID.
/// @param other 
/// @return bool
bool Contact::operator==( Contact other){
    return (id == other.id);
}
/// @brief Set a contact's name.
/// @param name 
void Contact::setName(String name){
    this->name = name;
}
/// @brief Set a contact's ID.
/// @param id 
void Contact::setID(String id){
    this->id = id;
}
/// @brief Set a contact's key.
/// @param key 
void Contact::setKey(String key){
    this->key = key;
}
/// @brief Used to compare contacts by name in a sort method.
/// @param c1 
/// @param c2 
/// @return static bool
static bool cmp_name( Contact &c1,  Contact &c2){
    return c1.getName() < c2.getName();
}
/// @brief Add a contact and sort the list by name.
/// @param c 
/// @return bool
bool Contact_list::add(Contact c){
    try{
        if(this->find(c))
            return false;
        this->list.push_back(c);
        std::sort(this->list.begin(), this->list.end(), cmp_name);
    }
    catch(exception ex){
        return false;
    }
    return true;
}
Contact_list::Contact_list(){
    
}

Contact_list::~Contact_list(){
    this->list.clear();
}
/// @brief Return the actual list size.
/// @return 
uint32_t Contact_list::size(){
    return this->list.size();
}
/// @brief Return a copy of a contact object from the list at the given index.
/// @param index 
/// @return Contact
Contact  Contact_list::getContact(uint32_t index){
    try{
        return list.at(index);
    }
    catch(exception e){
        Serial.println(e.what());
        return Contact();
    }
}
/// @brief Return a pointer to the contact on the list.
/// @param id 
/// @return Contact *
Contact *Contact_list::getContactByID(String id)
{
    if(list.size() > 0){
        for(uint32_t i = 0; i < list.size(); i++)
            if(strcmp(list[i].getID().c_str(), id.c_str()) == 0)
                return &this->list[i];
    }
    return NULL;
}
/// @brief Delete a contact from the list.
/// @param c 
/// @return bool
bool Contact_list::del(Contact c){
    std::vector<Contact>::iterator it = std::find(this->list.begin(), this->list.end(), c);
    if(it != this->list.end()){
        this->list.erase(it);
    }
    else
        return false;
    return true;
}
/// @brief Return true if a contact is found.
/// @param c 
/// @return bool
bool Contact_list::find(Contact &c){
    std::vector<Contact>::iterator it = std::find(this->list.begin(), this->list.end(), c);
    if(it != this->list.end()){
        c = this->getContact(std::distance(this->list.begin(), it));
        return true;
    }
    else
        return false;
}
/// @brief Return a copy of the list object.
/// @return vector <Contact>
vector <Contact> Contact_list::getList(){
    return list;
}
/// @brief Change the contacts inrange status based on a timeout value defined by the user.
// Should be called periodically.
void Contact_list::check_inrange(){
    if(this->list.size() > 0){
        for(uint32_t index = 0; index < this->list.size(); index++){
            if(millis() - this->list[index].timeout >= this->check_period){
                this->list[index].inrange = false;
                this->list[index].timeout += this->check_period;
            }
        }
    }
}
/// @brief Set the inrange timeout period in minutes.
/// @param min 
void Contact_list::setCheckPeriod(uint8_t min){
    if(min >= 1)
        this->check_period = min * 60 * 1000L;
}
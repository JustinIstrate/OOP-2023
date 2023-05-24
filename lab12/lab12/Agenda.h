#pragma once
#include "Contact.h"
#include "Prieten.h"
#include "Coleg.h"
#include "Cunoscut.h"
#include <string>
#include <vector>
class Agenda {
    std::vector<Contact*> list;
  public:
    Agenda();
    ~Agenda() {
        for (auto i : list)
            delete i;
    };
    Contact* search_by_name(std::string name){
        for (Contact* i : list)
            if (i->get_name() == name)
                return i;
        return 0;
    };
    void delete_by_name(std::string name){
        for (int i = 0; i < list.size();i++)
            if (list[i]->get_name()==name) {
                list.erase(list.begin() + i);
                break;
        }    
    };
    void add_contact(Contact* contact) {
        list.push_back(contact);
    };
    std::vector<Prieten*> get_friends() {
        std::vector<Prieten*> friends;
        for (auto i : list)
        if (i->get_type() == Type::Prieten)
                friends.push_back(static_cast<Prieten*>(i));
        return friends;
    }
};
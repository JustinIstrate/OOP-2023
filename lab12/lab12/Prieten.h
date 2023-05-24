#pragma once
#include "Contact.h"
#include <string>

class Prieten : public Contact {
    std::string phone_number;
    std::string adress;
    std::string birth_date;

  public:
    Prieten(const std::string name,const std::string number,const std::string addr,const std::string birth)
        : Contact(name), phone_number(number), adress(addr), birth_date(birth){};
    Type get_type() const override {
        return Type::Prieten;
    }
    const std::string get_phone() {
        return phone_number;
    }
    const std::string get_addr() {
        return adress;
    }
    const std::string get_birth() {
        return birth_date;
    }
};
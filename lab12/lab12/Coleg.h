#pragma once
#include "Contact.h"
#include <string>

class Coleg : public Contact {
    std::string phone_number;
    std::string company;
    std::string adress;

  public:
    Coleg(const std::string name,const std::string number,const std::string addr,const std::string company)
        : Contact(name), phone_number(number), adress(addr), company(company){};
    Type get_type() const override {
        return Type::Coleg;
    }
    const std::string get_phone() {
        return phone_number;
    }
    const std::string get_addr() {
        return adress;
    }
    const std::string get_company() {
        return company;
    }
};
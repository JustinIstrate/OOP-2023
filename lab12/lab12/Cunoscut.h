#pragma once
#include "Contact.h"
#include <string>

class Cunoscut : public Contact {
	std::string phone_number;
  public:
    Cunoscut(const std::string name,const std::string number) :Contact(name),phone_number(number) {};
    Type get_type() const override {
        return Type::Cunoscut;
    }
    const std::string get_phone() {
        return phone_number;
    }
};
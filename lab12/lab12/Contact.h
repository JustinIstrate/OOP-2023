#pragma once
#include <string>
enum class Type { Prieten, Cunoscut, Coleg };

class Contact {
    std::string name;

  public:
    Contact(const std::string& value) : name(value){};
    virtual ~Contact() {
    }
    virtual Type get_type() const = 0;
    const std::string get_name() {
        return name;
    }
};
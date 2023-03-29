#define _CRT_SECURE_NO_WARNINGS
#include "json.h"
using namespace std;
JsonValue::~JsonValue() {
}
NullValue::NullValue() {
}

void NullValue::print(std::ostream& out) {
    out << "NULL";
}

NumberValue::NumberValue(int value) : xvalue(value) {
}

void NumberValue::print(std::ostream& out) {
    out << xvalue;
}

StringValue::StringValue(const string value) : xvalue(value) {
}

void StringValue::print(std::ostream& out) {
    out << xvalue;
}

ArrayValue::ArrayValue() : count(0) {
}

void ArrayValue::add(JsonValue* value) {
    
    xvalue[count++] = value;
    
}

void ArrayValue::print(std::ostream& out) {
    out << "[";
    for (int i = 0; i < count; i++)
        out << xvalue[i] << ", ";
    out << "]";
}

ObjectValue::ObjectValue() : count(0) {
}

void ObjectValue::add(const char* name, JsonValue* value) {
    strcpy(xname, name);
    xvalue[count++] = value;
}

void ObjectValue::print(std::ostream& out) {
    out << "{";
    for (int i = 0; i < count; i++) {
        out << xname << ": ";
        xvalue[i]->print(out);
        out << ","
            << " ";
    }
    out << "}";
}

ObjectValue::operator unsigned() const {
    return count;
}

BoolValue::BoolValue(bool value): xvalue(value){

}

void BoolValue::print(std::ostream& out) {
    out << xvalue;
}

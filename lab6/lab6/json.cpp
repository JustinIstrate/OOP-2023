#define _CRT_SECURE_NO_WARNINGS
#include "json.h"
#include <cstring>
#include <string.h>
#include <stdio.h>
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

void ArrayValue::add(NumberValue* value) {
    xvalue[count++] = value;
}
void ArrayValue::add(StringValue* value) {
    xvalue[count++] = value;
}
void ArrayValue::print(std::ostream& out) {
    out << "[";
    xvalue[0]->print(out);
    for (int i = 1; i < count; i++) {
        out << ", ";
        xvalue[i]->print(out);
    }
    out << " ]";
}

ObjectValue::ObjectValue() : count(0) {
}

void ObjectValue::add(const string name, StringValue* value) {

    xname[count++] = name;
    xvalue[count-1] = value;
}
void ObjectValue::add(const string name, BoolValue* value) {
    xname[count++] = name;
    xvalue[count-1] = value;
}
void ObjectValue::add(const string name, NumberValue* value) {
    xname[count++] = name;
    xvalue[count-1] = value;
}
void ObjectValue::add(const string name, NullValue* value) {
    xname[count++] = name;
    xvalue[count-1] = value;
}
void ObjectValue::add(const string name, ArrayValue* value) {
    xname[count++] = name;
    xvalue[count-1] = value;
}
void ObjectValue::add(const string name, ObjectValue* value) {
    xname[count++] = name;
    xvalue[count-1] = value;
}

void ObjectValue::print(std::ostream& out) {
    out << "{";
    out << xname[0] << ": ";
    xvalue[0]->print(out);
    for (int i = 1; i < count; i++) {
        out << ", ";
        out << xname[i] << ": ";
        xvalue[i]->print(out);
    }
    out << "}";
}

ObjectValue::operator unsigned() const {
    return count;
}

BoolValue::BoolValue(bool value) : xvalue(value) {
}

void BoolValue::print(std::ostream& out) {
    if (xvalue == 1)
        out << "TRUE";
    else
        out << "FALSE";
}

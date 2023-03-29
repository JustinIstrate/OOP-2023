#pragma once

#include <iostream>
#include <ostream>
#include <string.h>
#include <cstring>
using namespace std;

class JsonValue {
    int xvalue;
  public:
    virtual ~JsonValue() = 0;

    virtual void print(std::ostream& out) = 0;
};

class NullValue : public JsonValue {
  public:
    NullValue();
    virtual void print(std::ostream& out);
};
class NumberValue : public JsonValue {
    int xvalue;

  public:
    NumberValue(int value);
    virtual void print(std::ostream& out);
};
class BoolValue : public JsonValue {
    bool xvalue;

  public:
    BoolValue(bool value);
    virtual void print(std::ostream& out);
};
class StringValue : public JsonValue {
    string xvalue;

  public:
    StringValue(const string value);
    virtual void print(std::ostream& out);
};
class ArrayValue : public JsonValue {
    JsonValue* xvalue[16];
    int count;
    public:
    ArrayValue();
    void add(JsonValue* value);
    virtual void print(std::ostream& out);
};
class ObjectValue : public JsonValue {
    char* xname;
    JsonValue* xvalue[16];
    int count;
    public:
    ObjectValue();
    void add(const char* name, JsonValue* value);
    virtual void print(std::ostream& out);
    operator unsigned() const;
};
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <stdio.h>
#include <iostream>
using namespace std;

template <typename T>

class CircularQueue {
    T* circ_buffer;
    int capacity;
    int front;
    int back;
    int size1;

  public:
    CircularQueue(int capacity) : capacity(capacity), front(0), back(0), size1(0) {
        circ_buffer = new T[capacity];
    }
    ~CircularQueue() {
        delete[] circ_buffer;
    }
    void push(T x) {
        if (size1 == capacity) {
            circ_buffer[front] = x;
            front = capacity-1;
        } else {
            front = size1;
            circ_buffer[front] = x;
            size1++;
        }
    }
    void pop() {
        if (empty())
            throw std::out_of_range("queue is empty");
        size1--;
        back++;
    }
    T& Front() {
        if (empty())
            throw std::out_of_range("queue is empty");
        return circ_buffer[front];
    }
    T& Back() {
        if (empty())
            throw std::out_of_range("queue is empty");
        return circ_buffer[back];
    }
    int size() {
        return size1;
    }
    bool empty() {
        if (size1 == 0)
            return true;
        return false;
    }
};

TEST_CASE("CircularQueue<unsigned> checking size") {
    CircularQueue<unsigned> queue(4);

    queue.push(23);
    queue.push(342);
    REQUIRE(queue.size() == 2);
}
TEST_CASE("CircularQueue<unsigned> add & pop") {
    CircularQueue<string> queue(4);
    queue.push("ana");
    queue.pop();
    REQUIRE(queue.empty());
}
TEST_CASE("CircularQueue<unsigned> first and last ") {
    CircularQueue<unsigned> queue(4);
    REQUIRE_THROWS(queue.Front());
    REQUIRE_THROWS(queue.Back());
}
TEST_CASE("CircularQueue<unsigned> if first is 5th added element ") {
    CircularQueue<string> queue(4);
    queue.push("a");
    queue.push("b");
    queue.push("c");
    queue.push("d");
    queue.push("e");
    REQUIRE(queue.Front() == "e");
}
TEST_CASE("CircularQueue<unsigned> add 1000 elements") {
    CircularQueue<unsigned> queue(4);

    for (unsigned i = 0; i < 1000; i++)
        queue.push(i);
    while (!queue.empty())
        queue.pop();
    REQUIRE(queue.size() == 0);
}
TEST_CASE("CircularQueue<unsigned> check if back is the first added element") {
        CircularQueue<unsigned> queue(4);
        queue.push(234);
        queue.push(123);
        queue.push(45);
        queue.push(93);
        REQUIRE(queue.Back() == 234);
}
/*
int main() {
    CircularQueue<unsigned> buff(10);
    buff.push(2);
    buff.push(6);
    buff.push(1342);
    buff.push(142);
    buff.push(56);
    buff.push(56343);
    buff.pop();
    buff.pop();
    buff.pop();
    buff.pop();
    cout << buff.size() << endl;
    cout << "front : " << buff.Front();
    cout << endl;
    cout << "back : " << buff.Back();
    return 0;
}*/ 
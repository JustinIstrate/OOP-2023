#define _CRT_SECURE_NO_WARNINGS
#include "Movie.h"
#include <cstring>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;
void Movie::set_name(const char* text) {
    strcpy(this->name, text);
}

void Movie::set_score(double x) {
    this->score = x;
}

void Movie::set_year(int year) {
    this->year = year;
}

void Movie::set_length(int length) {
    this->length = length;
}

const char* Movie::get_name() {
    return name;
}

int Movie::get_year() const {
    return year;
}

double Movie::get_score() const {
    return score;
}

int Movie::get_length() const {
    return length;
}

int Movie::get_passedyears() const {
    return 2023 - year;
}

void MovieSeries::init() {
    count = 0;
}

void MovieSeries::add(Movie* p) {
    v[count++] = *p;
}

void MovieSeries::sort() {
    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++)
            if (v[i].get_passedyears() > v[j].get_passedyears())
                std::swap(v[i], v[j]);
}

void MovieSeries::print() {
    for (int i = 0; i < count; i++)
        cout << "Movie name :" << v[i].get_name() << ", score : " << v[i].get_score()
             << " , length: " << v[i].get_length() << " , year : " << v[i].get_year() << endl;
}

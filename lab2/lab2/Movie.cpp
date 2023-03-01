#include "Movie.h"
#include <cstring>
#include <stdio.h>
#include <algorithm>
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

void MovieSeries::init() {
    this->count = 0;
}

void MovieSeries::add(Movie* p) {

    this->v[count++] = *p;
}

void MovieSeries::sort() {
    for (int i = 0; i < count-1; i++)
        for (int j = i + 1; j < count; j++)
            if (this->v[i].get_passedyears() > this->v[j].get_passedyears())
                std::swap(this->v[i], this->v[j]);
}

void MovieSeries::print() {
    for (int i = 0; i < count; i++)
        printf(
              "Movie number %d: name %c :  '/n' score %d: '/n' length %d: '/n' year %d: ",
              this->v[i].get_name(),
              this->v[i].get_score(),
              this->v[i].get_length(),
              this->v[i].get_year());
}

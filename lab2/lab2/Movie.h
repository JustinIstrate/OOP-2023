#pragma once
#include <iostream>

class Movie {
    char name[257];
    int year;
    int length;
    double score;

  public:
    void set_name(const char* text);
    void set_score(double x);
    void set_year(int year);
    void set_length(int length);
    const char* get_name();
    int get_year() const;
    double get_score() const;
    int get_length() const;
    int get_passedyears() const;
};
int movie_compare_name(Movie p1, Movie p2);
int movie_compare_year(Movie p1, Movie p2);
int movie_compare_score(Movie p1, Movie p2);
int movie_compare_length(Movie p1, Movie p2);
int movie_compare_passed_years(Movie p1, Movie p2);
class MovieSeries {
    Movie v[16];
    int count;

  public:
    void init();
    void add(Movie* p);
    void sort();
    void print();
};
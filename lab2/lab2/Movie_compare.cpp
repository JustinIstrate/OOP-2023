#include "Movie.h"
#include <cstring>
#include <time.h>

int movie_compare_name(Movie p1, Movie p2) {
    return strcmp(p1.get_name(), p2.get_name());
}
int movie_compare_year(Movie p1, Movie p2) {
    if (p1.get_year() > p2.get_year())
        return 1;
    if (p1.get_year() == p2.get_year())
        return 0;
    if (p1.get_year() < p2.get_year())
        return -1;
}
int movie_compare_score(Movie p1, Movie p2) {
    if (p1.get_score() > p2.get_score())
        return 1;
    if (p1.get_score() == p2.get_score())
        return 0;
    if (p1.get_score() < p2.get_score())
        return -1;
}
int movie_compare_length(Movie p1, Movie p2) {
    if (p1.get_length() > p2.get_length())
        return 1;
    if (p1.get_length() == p2.get_length())
        return 0;
    if (p1.get_length() < p2.get_length())
        return -1;
}
int movie_compare_passed_years(Movie p1, Movie p2) {
    if (p1.get_passedyears() > p2.get_passedyears())
        return 1;
    if (p1.get_passedyears() == p2.get_passedyears())
        return 0;
    if (p1.get_passedyears() < p2.get_passedyears())
        return -1;
}
#define _CRT_SECURE_NO_WARNINGS
#include "MyLibrary.h"
#include <ostream>
#include <cstring>
#include <string>
#include <cstdarg>
using namespace std;

MyLibrary::MyLibrary(std::ostream& output_stream) : output_stream(output_stream), books_count(-1), books(NULL){};

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int* books)
    : output_stream(output_stream), books_count(books_count) {
    this->books = new int[books_count];
    for (int i = 0; i < books_count; i++)
        this->books[i] = books[i];
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max): output_stream(output_stream),books_count(books_count) {
    books = new int[books_count];
    for (int i = 0; i < books_count; i++)
        books[i] = rand() % (max - min + 1) + min;
}

MyLibrary::MyLibrary(std::ostream& output_stream, const char* books_values) : output_stream(output_stream) {
    char aux[255];
    books = new int[strlen(books_values)];
    strcpy(aux, books_values);
    char* p;
    p = strtok(aux, ";");
    books_count = 0;
    while (p) {
        books[books_count++] = stoi(p);
        p = strtok(NULL, ";");
    }
}
MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, ...) : output_stream(output_stream),books_count(books_count){
    books = new int[books_count];
    va_list args;
    va_start(args, books_count);
    for (int i = 0; i < books_count; i++)
        books[i] = va_arg(args, int);
}

MyLibrary::MyLibrary(std::initializer_list<int> v) : output_stream(std::cout) {
    books = new int[books_count];
}

MyLibrary::~MyLibrary() {
    delete[] books;
}

void MyLibrary::print_books() {
    if (books_count == -1)
        output_stream << "-1" <<'\n';
    else {
        output_stream << "Found " << books_count << " books: ";
        for (int i = 0; i < books_count; i++)
            output_stream << books[i] << ' ';
        output_stream << '\n';
    }
}

void MyLibrary::update_book_id_by_index(unsigned book_index, int book_id) {
    if (book_index <= books_count)
        books[book_index] = book_id;
}

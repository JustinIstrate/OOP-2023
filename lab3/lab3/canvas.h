#pragma once
class Canvas {
  public:
    // contructor will call the clear method
    int a[100][100];
    int linesa;
    int columnsa;

    Canvas(int lines, int columns);

    // set the character at the position x and y to value
    void set_pixel(int x, int y, char value);

    // tuples of x, y, value
    void set_pixels(int count, ...);

    void clear();
    void print() const;
};
#include "canvas.h"
#include <cstdarg>
#include <iostream>
using namespace std;
Canvas::Canvas(int lines, int columns) {
    clear();
    linesa = lines;
    columnsa = columns;
}

void Canvas::set_pixel(int x, int y, char value) {
    a[x][y] = value;
}

void Canvas::set_pixels(int count, ...) {
    va_list args;
    va_start(args, count);

    setpixel(va_arg(args, int), va_arg(args, int), va_arg(args, int));

    va_end(args);
}

void Canvas::clear() {
    for (int i = 0; i < linesa; i++)
        for (int j = 0; j < columnsa; j++)
            a[i][j] = 0;
}

void Canvas::print() const {
    for (int i = 0; i < linesa; i++) {
        for (int j = 0; j < columnsa; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}

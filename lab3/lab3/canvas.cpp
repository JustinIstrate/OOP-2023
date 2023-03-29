#include "canvas.h"
#include <cstdarg>
#include <iostream>
using namespace std;
Canvas::Canvas(int lines, int columns) {
    linesa = lines;
    columnsa = columns;
    for (int i = 0; i < linesa; i++)
        for (int j = 0; j < columnsa; j++)
            a[i][j] = 0;
}
void Canvas::set_pixel(int x, int y, int value) {
    a[x][y] = value;
}

void Canvas::set_pixels(int count, ...) {
    va_list args;
    int v[3],a,b,c;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 3; j++)
            v[j] = va_arg(args, int);
        a = v[0];
        b = v[1];
        c = v[2];
        set_pixel(a, b, c);
        // set_pixel(va_arg(args, int), va_arg(args, int), va_arg(args, char));
    }
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

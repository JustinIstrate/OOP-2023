#include "complex.h"

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}
bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex& Complex::operator()(double real, double imag) {
    real_data += real;
    imag_data+=imag;
    return *this;
}

Complex& Complex::operator++() {
    real_data += 1;
    imag_data += 1;
    return *(this);
}

Complex Complex::operator++(int) {
    Complex rez(real_data, imag_data);
    real_data += 1;
    imag_data += 1;
    return (rez);
}
Complex& Complex::operator--() {
    real_data -= 1;
    imag_data -= 1;
    return *(this);
}

Complex Complex::operator--(int) {
    Complex rez(real_data, imag_data);
    real_data -= 1;
    imag_data -= 1;
    return (rez);
}

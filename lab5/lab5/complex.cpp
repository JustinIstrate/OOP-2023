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

Complex operator+(const Complex& l, const Complex& r) {
    double real = l.real() + r.real();
    double imag = l.imag() + r.imag();
    Complex rez(real, imag);
    return rez;
}
Complex operator+(const Complex& l, double r) {
    Complex rez(r, 0);
    return l + rez;
}
Complex operator+(double l, const Complex& r) {
    Complex aux(l, 0);
    return aux + r;
}

Complex operator-(const Complex& obj) {
    double real = 0 - obj.real();
    double imag = 0 - obj.imag();
    Complex rez(real, imag);
    return rez;
}
Complex operator-(const Complex& l, const Complex& r) {
    double real = l.real() - r.real();
    double imag = l.imag() - r.imag();
    Complex rez(real, imag);
    return rez;
}
Complex operator-(const Complex& l, double r) {
    Complex rez(r, 0);
    return l - rez;
}
Complex operator-(double l, const Complex& r) {
    Complex aux(l, 0);
    return aux - r;
}
Complex operator*(const Complex& l, const Complex& r) {
    double real = l.real() * r.real() - l.imag() * r.imag();
    double imag = l.real() * r.imag() + l.imag() * r.real();
    Complex rez(real, imag);
    return rez;
}
Complex operator*(const Complex& l, double r) {
    Complex rez(r, 0);
    return l * rez;
}
Complex operator*(double l, const Complex& r) {
    Complex aux(l, 0);
    return aux * r;
}
bool operator==(const Complex& l, const Complex& r) {
    if (l.real() == r.real() && l.imag() == r.imag())
        return true;
    return false;
}
bool operator!=(const Complex& l, const Complex& r) {
    if (l.real() == r.real() && l.imag() == r.imag())
        return false;
    return true;
}
std::ostream& operator<<(std::ostream& out, const Complex& complex) {
    out << complex.real() << "+" << complex.imag() << "i";
    return out;
}
#pragma once
#include <iostream>
#include <ostream>

// operatori care trebuie implementati:
// 1. op+, op-, op*
// care sa accepte doua numere complexe, un numar complex si un numar real, sau un numar real si un numar complex
// (9 in total)
// 2. op- unar
// 3. op== si op!=
// 4. op<< de streamuri pentru afisare
// 5. op++ prefixat si postfixat si op-- prefixat si postfixat
// 6. op() cu semnificatia de mai jos
// total: 18 operatori

// op++ postfixat TREBUIE sa foloseasca op++ prefixat
// op-- postfixat TREBUIE sa foloseasca op-- prefixat

// op+, op-, op* care iau un numar real TREBUIE sa foloseasca respectivii care iau numere complexe
// eg: op+(Complex, double) va apela op+(Complex, Complex)

class Complex {
  private:
    double real_data;
    double imag_data;

  public:
    Complex();
    Complex(double real, double imag);
    // daca numarul are doar o parte reala
    bool is_real() const;

    double real() const;
    double imag() const;
    // absolutul numarului
    double abs() const;
    // conjugatul
    Complex conjugate() const;

    Complex& operator()(double real, double imag);
    
    Complex& operator++();
    Complex operator++(int);
    Complex& operator--();
    Complex operator--(int);
};

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
    double real = l.real() * r.real()-l.imag()*r.imag();
    double imag = l.real() * r.imag()+l.imag()*r.real();
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
std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
    //out << complex.real() << "+" << complex.imag() << "i";
    return out;
}
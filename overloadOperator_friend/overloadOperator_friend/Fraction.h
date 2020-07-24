#pragma once
#include <iostream>

class Fraction {
private:
    int m_numerator;
    int m_denominator;

    int nod(int a, int b);
    Fraction reduce();

public:
    Fraction(int numerator = 0, int denominator = 1) : m_numerator(numerator), m_denominator(denominator)
    {

    }
    void print();

    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(int number, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, int number);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
    friend std::istream& operator>>(std::istream& in, Fraction& f1);
};

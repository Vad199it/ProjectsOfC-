#include <iostream>
#include "Fraction.h"

void Fraction::print()
{
    std::cout << m_numerator << "/" << m_denominator << "\n";
}

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
    out << f1.m_numerator << "/" << f1.m_denominator;
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& f1) {
    char c;
    in >> f1.m_numerator;
    in >> c;
    in >> f1.m_denominator;

    return in;
}

Fraction operator*(const Fraction& f1, const Fraction& f2) {
    return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator).reduce();
}

Fraction operator*(int number, const Fraction& f2) {
    return Fraction(number * f2.m_numerator, f2.m_denominator).reduce();
}

Fraction operator*(const Fraction& f1, int number) {
    return number * f1;
}

int Fraction::nod(int a, int b) {
    return (b == 0) ? (a > 0 ? a : -a) : nod(b, a % b);
}

Fraction Fraction::reduce() {
    int numberNod = nod(m_numerator, m_denominator);
    m_numerator /= numberNod;
    m_denominator /= numberNod;

    return Fraction(m_numerator, m_denominator);
}
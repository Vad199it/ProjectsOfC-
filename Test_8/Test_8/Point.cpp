#include <iostream>
#include <cmath>
#include "Point.h"

void Point::print() {
    std::cout << "(" << m_a << " : " << m_b << ")" << "\n";
}

double distanceFrom(Point &p1, Point& p2) {
    return sqrt((p1.m_a - p2.m_a) * (p1.m_a - p2.m_a) + (p1.m_b - p2.m_b) * (p1.m_b - p2.m_b));
}
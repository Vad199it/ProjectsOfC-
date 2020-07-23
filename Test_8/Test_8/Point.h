#pragma once

class Point {
public:
    int m_a;
    int m_b;

    Point(int a = 0, int b = 0) : m_a(a), m_b(b)
    {

    }

    void print();
    double friend distanceFrom(Point& p1, Point& p2);
};

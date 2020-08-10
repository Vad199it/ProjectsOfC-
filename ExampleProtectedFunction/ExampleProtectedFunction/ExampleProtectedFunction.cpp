#include <iostream>
#include <vector>

class Shape {
public:
	virtual std::ostream& print(std::ostream& out) const = 0;

	friend std::ostream& operator<<(std::ostream& out, const Shape &sh);

	virtual ~Shape() {}
};

std::ostream& operator<<(std::ostream& out, const Shape& sh)
{
	return sh.print(out);
}

class Point
{
private:
	int m_x = 0;
	int m_y = 0;
	int m_z = 0;

public:
	Point(int x, int y, int z)
		: m_x(x), m_y(y), m_z(z)
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
		return out;
	}
};

class Triangle : public Shape {
private:
	Point m_point1;
	Point m_point2;
	Point m_point3;
public:
	Triangle(Point p1, Point p2, Point p3)
		:m_point1(p1), m_point2(p2), m_point3(p3)
	{

	}

	virtual std::ostream& print(std::ostream& out) const override {
		return out << m_point1 << m_point2 << m_point3;
	}
};

class Circle : public Shape {
private:
	Point m_point1;
	int m_radius;
public:
	Circle(Point p, int r) 
		:m_point1(p), m_radius(r)
	{

	}

	int getRadius();
	virtual std::ostream& print(std::ostream& out) const override{
		return out << m_point1 << m_radius;
	}
};

int Circle::getRadius() {
	return m_radius;
}

int getLargestRadius(std::vector<Shape*> v) {
	int largeRadius{};

	for (Shape* p : v) {
		if (Circle *c = dynamic_cast<Circle*>(p)) {
			if (c->getRadius() > largeRadius)
			largeRadius = c->getRadius();
		}
	}
	return largeRadius;
}

int main()
{
	std::vector<Shape*> v;
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	v.push_back(new Circle(Point(4, 5, 6), 3));

	// Вывод элементов вектора v здесь

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // реализуйте эту функцию

// Удаление элементов вектора v здесь

}
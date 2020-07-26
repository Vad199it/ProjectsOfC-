#include <iostream>
#include <cstdint>
#include <cmath>

class FixedPoint {
private:
	std::int16_t m_wholePart;
	std::int8_t m_fractionalPart;
public:
	FixedPoint(std::int16_t wholePart = 0.0, std::int8_t fractionalPart = 0.0)
		:m_wholePart(wholePart), m_fractionalPart(fractionalPart)
	{
		if (m_fractionalPart > 100)
			m_fractionalPart = 99;
		if(m_fractionalPart < - 100)
			m_fractionalPart = -99;

		if (m_wholePart < 0.0 || m_fractionalPart < 0.0) {
			if (m_wholePart > 0.0)
				m_wholePart = -m_wholePart;
			if (m_fractionalPart > 0.0)
				m_fractionalPart = -m_fractionalPart;
		}

	}

	FixedPoint(double number) {
		m_wholePart = static_cast<int16_t>(number);
		m_fractionalPart = static_cast<int8_t>(round((number - m_wholePart) * 100));
	}

	operator double() const;
	friend std::ostream& operator<<(std::ostream& out, FixedPoint &point);
	friend std::istream& operator>>(std::istream& in, FixedPoint& point);
	friend FixedPoint operator+(FixedPoint fp1, FixedPoint fp2);
	friend bool operator==(FixedPoint fp1, FixedPoint fp2);
	FixedPoint operator-();
};


bool operator==(FixedPoint fp1, FixedPoint fp2) {
	if (fp1.m_fractionalPart = fp2.m_fractionalPart && fp1.m_wholePart == fp2.m_wholePart)
		return true;
	return false;
}

FixedPoint operator+(FixedPoint fp1, FixedPoint fp2) {
	return FixedPoint(static_cast<double>(fp1) + static_cast<double>(fp2));
}

FixedPoint::operator double() const {
	return m_wholePart + static_cast<double>(m_fractionalPart)/100;
}

std::istream& operator>>(std::istream& in, FixedPoint& point) {
	char c;
	in >> point.m_wholePart;
	in >> c;
	in >> point.m_fractionalPart;
	return in;
}

std::ostream& operator<<(std::ostream& out, FixedPoint &point) {
	out << static_cast<double>(point);
	return out;
}
FixedPoint FixedPoint::operator-()
{
	return FixedPoint(-m_wholePart, -m_fractionalPart);
}

void SomeTest()
{
	std::cout << std::boolalpha;
	std::cout << (FixedPoint(0.75) + FixedPoint(1.23) == FixedPoint(1.98)) << '\n'; // оба значения положительные, никакого переполнения
	std::cout << (FixedPoint(0.75) + FixedPoint(1.50) == FixedPoint(2.25)) << '\n'; // оба значения положительные, переполнение
	std::cout << (FixedPoint(-0.75) + FixedPoint(-1.23) == FixedPoint(-1.98)) << '\n'; // оба значения отрицательные, никакого переполнения
	std::cout << (FixedPoint(-0.75) + FixedPoint(-1.50) == FixedPoint(-2.25)) << '\n'; // оба значения отрицательные, переполнение
	std::cout << (FixedPoint(0.75) + FixedPoint(-1.23) == FixedPoint(-0.48)) << '\n'; // второе значение отрицательное, никакого переполнения
	std::cout << (FixedPoint(0.75) + FixedPoint(-1.50) == FixedPoint(-0.75)) << '\n'; // второе значение отрицательное, возможно переполнение
	std::cout << (FixedPoint(-0.75) + FixedPoint(1.23) == FixedPoint(0.48)) << '\n'; // первое отрицательное, никакого переполнения
	std::cout << (FixedPoint(-0.75) + FixedPoint(1.50) == FixedPoint(0.75)) << '\n'; // первое отрицательное, возможно переполнение
}

int main()
{
	SomeTest();

	FixedPoint a(-0.48);
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // введите 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';

	return 0;
}


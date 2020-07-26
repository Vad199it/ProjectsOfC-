#include <cassert>
#include <iostream>

class Drob
{
private:
	int m_numerator;
	int m_denominator;

public:
	// Конструктор по умолчанию
	Drob(int numerator = 0, int denominator = 1) :
		m_numerator(numerator), m_denominator(denominator)
	{
		assert(denominator != 0);
	}
private:
	// Конструктор копирования
	Drob(const Drob& drob) :
		m_numerator(drob.m_numerator), m_denominator(drob.m_denominator)
	{
		// Нет необходимости выполнять проверку denominator здесь, так как эта проверка уже осуществляется в конструкторе класса Drob
		std::cout << "Copy constructor worked here!\n"; // просто чтобы показать, что это работает
	}
public:
	friend std::ostream& operator<<(std::ostream& out, const Drob& d1);
};

std::ostream& operator<<(std::ostream& out, const Drob& d1)
{
	out << d1.m_numerator << "/" << d1.m_denominator;
	return out;
}

int main()
{
	Drob sixSeven(Drob(6, 7));
	std::cout << sixSeven;
	return 0;
}
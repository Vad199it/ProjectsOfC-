#include <iostream>

class Parent
{
public:
	int m_value;

	int getValue();
};

int Parent::getValue() {
	return 10 * m_value;
}

class Child : public Parent
{
private:
	using Parent::m_value;

public:
	Child(int value)
	{
		m_value = value;
	}

	int getValue() = delete;
};

int main()
{
	Child child(9);

	// Следующее не сработает, поскольку m_value и getValue() были переопределёны как private
	std::cout << child.m_value;
	std::cout << child.getValue();

	return 0;
}
#include <iostream>

class Fruit {
private:
	std::string m_name;
	std::string m_color;
public:
	Fruit(std::string name = "", std::string color = "")
		: m_name(name), m_color(color)
	{

	}
	std::string getName();
	std::string getColor();
};

std::string Fruit::getName() {
	return m_name;
}

std::string Fruit::getColor() {
	return m_color;
}

class Apple : public Fruit {
public:
	Apple(std::string color, std::string name = "apple")
		:Fruit(name, color)
	{

	}
};

class Banana : public Fruit {
public:
	Banana(std::string color = "yellow", std::string name = "banana")
		:Fruit(name, color)
	{

	}
};

class GrannySmith : public Apple {
public:
	GrannySmith(std::string color = "green", std::string name = "Granny Smith apple")
		:Apple(name, color)
	{

	}
};

int main()
{
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}


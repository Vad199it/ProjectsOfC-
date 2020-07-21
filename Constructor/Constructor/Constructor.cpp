#include <iostream>
#include <string>


class Ball {
private:
	std::string m_color;
	double m_radius;

public:
	Ball(double radius, const std::string &color = "Red") {
		m_color = color;
		m_radius = radius;
	}

	Ball(const std::string &color = "Red", double radius = 20.0) {
		m_color = color;
		m_radius = radius;
	}

	void print() {
		std::cout << m_radius << " " << m_color << std::endl;
	}
};

int main()
{
	Ball def;
	def.print();

	Ball black("black");
	black.print();

	Ball thirty(30.0);
	thirty.print();

	Ball blackThirty("black", 30.0);
	blackThirty.print();

	return 0;
}

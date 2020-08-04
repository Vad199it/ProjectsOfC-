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

    std::string getName() const;
    std::string getColor() const;
};

std::string Fruit::getName() const{
    return m_name;
}

std::string Fruit::getColor() const {
    return m_color;
}

class Apple : public Fruit {
private:
    double m_fiber;
public:
    Apple(std::string name = "", std::string color = "", double fiber = 0.0)
        : Fruit(name, color), 
          m_fiber(fiber)
    {

    }

    friend std::ostream& operator<< (std::ostream &out, Apple apple);
};

std::ostream& operator<< (std::ostream &out, Apple apple) {
    out << apple.getName() << apple.getColor() << apple.m_fiber;
    return out;
}

class Banana : public Fruit {
public:
    Banana(std::string name = "", std::string color = "")
        : Fruit(name, color)
    {

    }

    friend std::ostream& operator<< (std::ostream& out, const Banana &banana);
};

std::ostream& operator<< (std::ostream& out, const Banana &banana) {
    out << banana.getName() << banana.getColor();
    return out;
}

int main()
{
    const Apple a("Red delicious", "red", 7.3);
    std::cout << a;

    const Banana b("Cavendish", "yellow");
    std::cout << b;
}


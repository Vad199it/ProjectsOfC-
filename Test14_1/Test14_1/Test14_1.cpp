#include <iostream>
#include <stdexcept>

class Fraction {
private:
    int m_numerator;
    int m_denominator;
public:
    Fraction(int numerator = 0 , int denominator = 1)
        :m_numerator(numerator), m_denominator(denominator)
    {
        if (m_denominator == 0) 
            throw std::runtime_error("Your fraction has an invalid denominator.");
    }

    void print();
};

void Fraction::print() {
    std::cout << m_numerator << "/" << m_denominator;
}

int main()
{
    std::cout << "Enter the numerator: ";
    int numerator;
    std::cin >> numerator;
    std::cout << "Enter the denominator: ";
    int denominator;
    std::cin >> denominator;
    try {
        Fraction fraction(numerator, denominator);
        fraction.print();
    } 
    catch (std::exception& exeption) {
        std::cout << "Error: " << exeption.what();
    }
}


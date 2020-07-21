#include <iostream>

class Numbers {
public:
    int m_firstNumber;
    int m_secondNumber;

    void set(int firstNumber, int secondNumber) {
        m_firstNumber = firstNumber;
        m_secondNumber = secondNumber;
    }

    void print() {
        std::cout << m_firstNumber << " " << m_secondNumber;
    }
};

int main()
{
    Numbers n1;
    n1.set(3, 3);

    Numbers n2{ 4, 4 };

    n1.print();
    n2.print();

    return 0;
}


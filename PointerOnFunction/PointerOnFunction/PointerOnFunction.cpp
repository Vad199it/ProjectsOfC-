#include <iostream>
#include <functional>
#include <array>

using arithmeticFsn = std::function<int(int, int)>;

struct ArithmeticStruct {
    char symbol;
    arithmeticFsn fcn;
};

int getNumber() {
    int number(0);
    std::cin >> number;
    return number;
}

char getSymbol() {
    char symbol(0);
    do {
        std::cin >> symbol;
    } while (symbol != '+' && symbol != '*' && symbol != '/' && symbol != '-');
    return symbol;
}

int sum(int fNumber, int Snumber) {
    return fNumber + Snumber;
}

int subtract(int fNumber, int Snumber) {
    return fNumber + Snumber;
}

int multiply(int fNumber, int Snumber) {
    return fNumber * Snumber;
}

int divide(int fNumber, int Snumber) {
    return fNumber / Snumber;
}


//arithmeticFsn getArithmeticFsn(char symbol) {
//    switch (symbol){
//    default:
//    case '+': return sum;
//    case '-': return subtract;
//    case '*': return multiply;
//    case '/': return divide;
//    }
//}
static std::array<ArithmeticStruct, 4> arrayOfArithmeticStruct{ {
 {'+', sum},
 {'-', subtract},
 {'*', multiply},
 {'/', divide}
 } };

arithmeticFsn getArithmeticFsn(char symbol) {
    for (ArithmeticStruct& arithStruct : arrayOfArithmeticStruct)
    {
        if (arithStruct.symbol == symbol)
            return arithStruct.fcn;
    }
}


int main()
{
    int firstNumber = getNumber();
    int secondNumber = getNumber();
    char symbol = getSymbol();
    arithmeticFsn getFunction;
    getFunction = getArithmeticFsn(symbol);
    std::cout << getFunction(firstNumber, secondNumber);

}

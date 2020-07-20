#include <iostream>

int factorial(int number){
	if (number == 0) return 1;
	return factorial(number - 1) * number;
}

int summValueOfNumber(int number) {
	if (number < 10) return number;
	return summValueOfNumber(number / 10) + number % 10;
}

void getBinary(unsigned int number) {
	if (number == 0) return;

	getBinary(number / 2);

	std::cout << number % 2;
}

void printData(int number) {
	if (number == 0)  std::cout << 0;
	else
	getBinary(static_cast<unsigned int>(number));
}

int main()
{
	printData(-20);
}


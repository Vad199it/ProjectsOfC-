#include <iostream>

void printString(const char *string) {
	while (*string != '\0') {
		std::cout << *string << std::endl;
		++string;
	}
}

int main()
{
	printString("Hello, world!");
}


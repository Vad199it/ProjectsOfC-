#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
using iterat = std::vector<int>::iterator;

int getRandomNumber(int min, int max) {
	int r = ((rand() % max) + min);
	return r;
}

int getNumber() {
	int number(0);
	std::cin >> number;
	return number;
}

void createArray(std::vector<int> &arr,int number, int getFactor, int lengthOfNumbers) {
	for (int i(0); i < lengthOfNumbers; ++i) {
		arr.push_back(pow((number + i), 2) * getFactor);
	}
}

void findElement( int &number, std::vector<int> arr, bool& flag) {
	iterat it;
	do {
		std::cin >> number;
		it = std::find(arr.begin(), arr.end(), number);
		if (it == arr.end()) flag = false;
		else {
			arr.erase(it);
		}
	} while (arr.size() != 0 && flag);
}

int FindNearNumber(int &number, std::vector<int> arr) {
	return *std::min_element(arr.begin(), arr.end(),
		[&number](int a, int b) {
			return std::abs(a - number) < std::abs(b - number);
		});
}

void printResult(bool flag,int number, int nearNumber) {
	if (flag == false) {
		if (abs(nearNumber - number) > 4) {
			std::cout << "You lost";
		}
		else {
			std::cout << "You lost";
			std::cout << nearNumber;
		}
	}
	else std::cout << "Win";
}

int main()
{
	srand((int)time(0));
	int getFactor = getRandomNumber(2, 3);

	int number = getNumber();
	int lengthOfNumbers = getNumber();

	std::vector<int> arr;
	createArray(arr, number, getFactor, lengthOfNumbers);

	std::cout << getFactor << std::endl;

	bool flag = true;
	findElement(number, arr, flag);
	int nearNumber = FindNearNumber(number, arr);
	printResult(flag, number, nearNumber);
}


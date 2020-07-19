#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Student {
	std::string name;
	int mark;
};

void sortArray(std::vector<Student> &array, int length) {
	for (int i(0); i < length; ++i) {
		int maxIndex = i;
		for (int j = i + 1; j < length; ++j) {
			if (array[maxIndex].mark < array[j].mark)
				maxIndex = j;
		}
		std::swap(array[i], array[maxIndex]);
	}
}

void printResult(const std::vector<Student> &array, int length) {
	for (int count(0); count < length; ++count) {
		std::cout << "Enter a name: ";
		std::cout << array[count].name;
		std::cout << std::endl;
		std::cout << "Enter a mark: ";
		std::cout << array[count].mark;
		std::cout << std::endl;
	}
}

void checkInput(int &countStudent) {
	do {
		std::cout << "How many students ?" << std::endl;
		std::cin >> countStudent;
	} while (countStudent > 100 || countStudent < 0);
}

int main()
{
	int countStudent{};
	checkInput(countStudent);

	std::vector<Student> arrayStudent(countStudent);

	for (int count(0); count < countStudent; ++count) {
		std::cout << "Enter a name: ";
		std::cin >> arrayStudent[count].name;
		std::cout << "Enter a mark: ";
		std::cin >> arrayStudent[count].mark;
	}

	sortArray(arrayStudent, arrayStudent.size());
	printResult(arrayStudent, arrayStudent.size());
}


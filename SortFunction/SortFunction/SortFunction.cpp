#include <iostream>
#include <cstdlib>
#include <algorithm>

void SortChoise(int mass[], int length) {

	for (int startIndex = 0; startIndex < length - 1; ++startIndex) {
		int smallIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex) {
			if (mass[currentIndex] < mass[smallIndex]) {
				smallIndex = currentIndex;
			}
		}
		std::swap(mass[startIndex], mass[smallIndex]);
	}
}

void bubbleSort(int mass[], int length){
	for (int i = 0; i < length - 1; ++i) {
		bool flag = false;
		for (int j = 0; j < length - i - 1; ++j) {
			if (mass[j] > mass[j + 1]) {
				std::swap(mass[j], mass[j + 1]);
				flag = true;
			}
		}

		if (!flag) {
			std::cout << i + 1 << ":" << std::endl;
			break;
		}
	}
}

int main()
{
	int array[6]{ 10, 20, 20, 60, 40, 50 };
	int length = sizeof(array) / sizeof(array[0]);
	std::cout << array[0] << array[1] << array[2] << array[3] << array[4] << array[5] << std::endl;
	std::sort(array, array + length);
	std::cout << array[0] << array[1] << array[2] << array[3] << array[4] << array[5];

}
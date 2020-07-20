#include <iostream>

// array - это массив, в котором мы проводим поиски
// target - это искомое значение
// min - это индекс минимальной границы массива, в котором мы осуществляем поиск
// max - это индекс максимальной границы массива, в котором мы осуществляем поиск 
// binarySearch() должен возвращать индекс искомого значения, если оно обнаружено. В противном случае, возвращаем -1
int binarySearch(int* array, int target, int min, int max)
{
	int index(0);
	do {
		index = (max + min) / 2;
		if (array[index] == target) return index;
		(array[index] > target) ? max = index - 1 : min = min + 1;
	} while (min <= max);
	return -1;
}

int recursBinarySearch(int* array, int target, int min, int max)
{
	if (min > max) return -1;
	int index(0);
	index = (max + min) / 2;
	if (array[index] == target) return index;
		(array[index] > target) ? 
		recursBinarySearch(array, target, min, max - 1)  : recursBinarySearch(array, target, min + 1, max);
	
}

int main()
{
	int array[] = { 4, 7, 9, 13, 15, 19, 22, 24, 28, 33, 37, 41, 43, 47, 50 };

	std::cout << "Enter a number: ";
	int x;
	std::cin >> x;

	int index = recursBinarySearch(array, x, 0, 14);

	if (array[index] == x)
		std::cout << "Good! Your value " << x << " is on position " << index << " in array!\n";
	else
		std::cout << "Fail! Your value " << x << " isn't in array!\n";
	return 0;
}
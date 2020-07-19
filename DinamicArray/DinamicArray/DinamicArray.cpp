#include <iostream>
#include <string>

void SortChoise(std::string mass[], int length) {

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

int main()
{
    std::cout << "How many?" << std::endl;
    int length;
    std::cin >> length;

    std::string* array = new std::string[length]; // выделяем динамиескую память, для переменной типа int - int length = new int; 

    for (int count = 0; count < length; ++count) {
        std::cout << "Enter name:" << std::endl;
        std::cin >> array[count];
    }

    SortChoise(array, length);
    for (int count{}; count < length; ++count) {
        std::cout << "Name:" << array[count] << std::endl;
    }

    delete[] array; // освобождаем память
    array = nullptr;// обнуляем указатель
}

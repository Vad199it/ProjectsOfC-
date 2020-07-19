#include <iostream>

enum Subject {
    HP,
    TORCH,
    ARROW,
    MaxLength
};

int countTotalItems(const int *array) {
    int i{};
    for (int j{}; j < MaxLength; ++j) {
        i = i + array[j];
    }
    
    return i;
}

int main()
{
    int subjectArray[4]{0};
    subjectArray[Subject::HP] = 3;
    subjectArray[Subject::TORCH] = 6;
    subjectArray[Subject::ARROW] = 12;
    std::cout << countTotalItems(subjectArray);
}


#include <iostream>
#include <array>
#include <cassert>

class Stack {
public:
    std::array <int, 10> arr;
    int length;

    void reset() {
        arr = { 0 };
        length = 0;
    }

    bool push(int value) {
        if (length < 11) {
            arr[length++] = value;
            return true;
        }
        else return false;
            
    }

    int pop() {
        assert(length > 0 && "Not value");
        return arr[--length];
    }

    void print() {
        std::cout << "(";
        for (int count(0); count < length; ++count)
            std::cout << " " << arr[count] << " ";
            std::cout << ")";

    }
};

int main()
{
    Stack stack;
    stack.reset();

    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
  
}


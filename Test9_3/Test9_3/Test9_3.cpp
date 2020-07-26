#include <iostream>
#include <cassert>

class IntArray {
private:
	int m_length = 0;
	int *m_data = nullptr;
public:
	IntArray(int length): 
		m_length(length)
	{
		assert(length > 0);
		m_data = new int[length];
	}

	IntArray(const IntArray &intArray) : 
		m_length(intArray.m_length)
	{
		m_data = new int[m_length];

		for (int i (0); i < m_length; ++i){
			m_data[i] = intArray.m_data[i];
		}
	}

	int& operator[](int number);
	IntArray& operator=(IntArray& intArray);
	friend std::ostream& operator<<(std::ostream& out, IntArray intArray);

	~IntArray(){
		delete[] m_data;
	}
};

IntArray& IntArray::operator=(IntArray& intArray) {
	if (this == &intArray)
		return *this;

	delete[] m_data;
	m_length = intArray.m_length;

	m_data = new int[m_length];

	for (int i(0); i < m_length; ++i) {
		m_data[i] = intArray.m_data[i];
	}

	return *this;
}

int& IntArray::operator[](int number) {
	assert(number >= 0);
	assert(number < m_length);
	return m_data[number];
}

std::ostream& operator<<(std::ostream& out, IntArray intArray) {
	for (int i(0); i < intArray.m_length; ++i) {
		out << intArray.m_data[i];
	}
	return out;
}

IntArray fillArray()
{
	IntArray a(6);
	a[0] = 6;
	a[1] = 7;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;
	a[5] = 8;

	return a;
}

int main()
{
	IntArray a = fillArray();
	std::cout << a << '\n';

	IntArray b(1);
	a = a;
	b = a;

	std::cout << b << '\n';

	return 0;
}


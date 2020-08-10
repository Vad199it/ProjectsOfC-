#include <iostream>

template <class T>
class Pair1 {
private:
	T m_fvalue;
	T m_svalue;
public:
	Pair1(T fvalue, T svalue)
		: m_fvalue(fvalue), m_svalue(svalue)
	{

	}

	T first() {
		return m_fvalue;
	}

	T first() const {
		return m_fvalue;
	}

	T second() {
		return m_svalue;
	}

	T second() const{
		return m_svalue;
	}
};

int main()
{
	Pair1<int> p1(6, 9);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2(3.4, 7.8);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}
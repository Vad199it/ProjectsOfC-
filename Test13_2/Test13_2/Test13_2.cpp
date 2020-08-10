#include <iostream>

template <class T, class S>
class Pair {
private:
	T m_fvalue;
	S m_svalue;
public:
	Pair(T fvalue, S svalue)
		:m_fvalue(fvalue), m_svalue(svalue)
	{

	}

	T first() {
		return m_fvalue;
	}

	T first() const{
		return m_fvalue;
	}

	S second() {
		return m_svalue;
	}

	S second() const {
		return m_svalue;
	}
};

int main()
{
	Pair<int, double> p1(6, 7.8);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2(3.4, 5);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
}


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

	S second() {
		return m_svalue;
	}
};

template <class S>
class StringValuePair: public Pair<std::string, S> {
public:
	StringValuePair(std::string fvalue, S svalue)
		:Pair<std::string, S>(fvalue, svalue)
	{

	}
};


int main()
{
	StringValuePair<int> svp("Amazing", 7);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
}


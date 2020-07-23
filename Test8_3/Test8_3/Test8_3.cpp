#include <iostream>
#include <ctime>
#include "Monster.h"
#include "MonsterGenerator.h"


int main()
{
	srand(static_cast<unsigned int>(time(0)));
	rand(); 

	Monster m = MonsterGenerator::generateMonster();
	m.print();

	return 0;
}


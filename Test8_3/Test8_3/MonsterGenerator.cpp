#include <iostream>
#include <array>
#include "Monster.h"
#include "MonsterGenerator.h"



int MonsterGenerator::getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

Monster MonsterGenerator::generateMonster() {

	Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1));
	int hp = getRandomNumber(1, 100);
	static std::array<std::string, 6> arrName{"Vadzim", "Mila", "Alesya", "Jack", "Anna", "Lesha"};

	return Monster(type, arrName[getRandomNumber(0, 5)], hp);
}
#include "Monster.h"
#include <array>
#include <cstdlib>
#include <ctime>

std::array<Monster::MonsterData, Monster::MAX_TYPES> Monster::monsterData =
{ {
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
} };

int getRandomNumber(int min, int max) {
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

Monster Monster::getRandomMonster() { // !!!! Пытался в статическом методе вызвать метод класса(getRandomNumber() был методом). 
									  //Ошибка: Нестатическая ссылка не член должна указываться относительно заданного 
									  //объекта.(Метод класса требует ОБЪЕКТ, а статический метод работает без него => ошибка)
	int rNumber = getRandomNumber(0, MAX_TYPES - 1);
	return Monster(static_cast<Type>(rNumber));
}

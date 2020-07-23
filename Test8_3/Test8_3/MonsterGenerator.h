#pragma once

class Monster;

class MonsterGenerator {
public:
	static Monster generateMonster();
	static int getRandomNumber(int min, int max);
};

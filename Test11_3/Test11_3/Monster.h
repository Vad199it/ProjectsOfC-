#pragma once
#include "Creature.h"
#include <array>

class Monster : public Creature {
public:
	struct MonsterData {
		std::string name;
		char symbol;
		int health;
		int damage;
		int gold;

	};
	enum Type {
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES
	};
	static int m;
	static std::array<MonsterData, MAX_TYPES> monsterData;

	Monster(Type type)
		: Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health, 
				   monsterData[type].damage, monsterData[type].gold)
	{

	}

	static Monster getRandomMonster();
};

int getRandomNumber(int min, int max);
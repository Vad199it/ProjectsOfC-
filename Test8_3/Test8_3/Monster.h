#pragma once
#include <iostream>

class Monster {
public:
	enum MonsterType {
		Dragon,
		Goblin,
		Ogre,
		Orc,
		Skeleton,
		Troll,
		Vampire,
		Zombie,
		MAX_MONSTER_TYPES
	};

private:
	MonsterType m_type;
	std::string m_name;
	int m_hp;

public:
	Monster(MonsterType type, std::string name, int hp) :
		m_type(type), m_name(name), m_hp(hp)
	{

	}
	std::string getTypeString(MonsterType type);
	void print();
};
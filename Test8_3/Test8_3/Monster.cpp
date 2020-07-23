#include <iostream>
#include "Monster.h"

std::string Monster::getTypeString(MonsterType type) {
	switch (type) {
	default:
	case Monster::Dragon: return "Dragon";
	case Monster::Goblin: return "Goblin";
	case Monster::Ogre: return "Ogre";
	case Monster::Orc: return "Orc";
	case Monster::Skeleton: return "Skeleton";
	case Monster::Troll: return "Troll";
	case Monster::Vampire: return "Vampire";
	case Monster::Zombie: return "Zombie";
	}
}

void Monster::print() {

	std::cout << m_name << " is the " << getTypeString(m_type) << " that has " << m_hp << " health points.";
}
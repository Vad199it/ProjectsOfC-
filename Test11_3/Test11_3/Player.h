#pragma once
#include "Creature.h"

class Player : public Creature {
private:
	int m_level = 1;

public:
	Player(std::string name) 
		: Creature(name, '@', 10, 1, 0)
	{

	}

	void levelUp();
	int getLevel();
	bool hasWon();
};
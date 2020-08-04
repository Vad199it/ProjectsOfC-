#pragma once
#include <iostream>

class Creature {
protected:
	std::string m_name;
	char m_symbol;
	int m_health;
	int m_countAttack;
	int m_countGold;
public:
	Creature(std::string name = "", char symbol = ' ', int health = 0, int countAttack = 0, int countGold = 0)
		:m_name(name), m_symbol(symbol), m_health(health), m_countAttack(countAttack), m_countGold(countGold)
	{

	}
	const std::string& getName();
	char getSymbol();
	int getHealth();
	int getCountAttack();
	int getGold();
	void reduceHealth(int value);
	bool isDead();
	void addGold(int gold);
};
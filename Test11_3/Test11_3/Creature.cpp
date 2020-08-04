#include <iostream>
#include "Creature.h"

const std::string& Creature::getName() {
	return m_name;
}

char Creature::getSymbol() {
	return m_symbol;
}

int Creature::getHealth() {
	return m_health;
}

int Creature::getCountAttack() {
	return m_countAttack;
}

int Creature::getGold() {
	return m_countGold;
}

void Creature::reduceHealth(int value) {
	m_health -= value;
}

bool Creature::isDead() {
	return m_health <= 0;
}

void Creature::addGold(int gold) {
	m_countGold += gold;
}
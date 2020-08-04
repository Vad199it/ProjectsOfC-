#include "Player.h"

void Player::levelUp() {
	m_level += 1;
	m_countAttack += 1;

}

int Player::getLevel() {
	return m_level;
}

bool Player::hasWon() {
	return m_level == 20;
}
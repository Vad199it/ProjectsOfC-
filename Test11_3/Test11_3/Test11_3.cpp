#include <iostream>
#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include <cstdlib>
#include <ctime>

void attackMonster(Monster &monster, Player &player) {
	if (player.isDead())
		return;
	monster.reduceHealth(player.getCountAttack());
	std::cout << "You hit the " << monster.getName() << " for " << player.getCountAttack() << " damage.\n";

	if (monster.isDead()) {
		std::cout << "You killed the " << monster.getName() << ".\n";
		player.levelUp();
		std::cout << "You are now level " << player.getLevel() << ".\n";
		player.addGold(monster.getGold());
		std::cout << "You found " << monster.getGold() << "gold.\n";
	}
}

void attackPlayer(Monster& monster, Player& player) {
	if (monster.isDead())
		return;
	player.reduceHealth(monster.getCountAttack());
	std::cout << "The " << monster.getName() << "hit you for " << monster.getCountAttack() <<" damage.\n";
}

void fightMonster(Player &player) {
	Monster monster = Monster::getRandomMonster();
	std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ")." << "\n";
	char answer;

	while (!player.isDead() && !monster.isDead()) {
		do {
			std::cout << "(R)un or (F)ight:" << "\n";
			std::cin >> answer;
		} while (answer != 'R' && answer != 'F');

		if (answer == 'F') {
			attackMonster(monster, player);
			attackPlayer(monster, player);
		}
		else {
			int chance = getRandomNumber(0, 1);
			if (chance) {
				std::cout << "You failed to flee.\n";
				attackPlayer(monster, player);
				continue;
			}
			else {
				std::cout << "You successfully fled.\n";
				return;
			}
		}
	}
}


int main()
{
	srand(static_cast<unsigned int>(time(0)));
	rand();

	std::cout << "Enter your name: ";
	std::string playerName;
	std::cin >> playerName;
	Player player(playerName);
	std::cout << "Welcome, " << playerName << "\n";

	while (!player.isDead() && !player.hasWon()) {
		fightMonster(player);
	}

	if (player.isDead()) {
		std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << "gold.\n";
		std::cout << "Too bad you can't take it with you!\n";
	}

	else 
		std::cout << "You won!!! You have " << player.getGold() << " gold.\n";

	return 0;
}



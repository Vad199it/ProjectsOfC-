#include <iostream>
#include <array>
#include <ctime>
#include "Card.h"
#include "Deck.h"


enum class BlackjackResult
{
	BLACKJACK_PLAYER_WIN,
	BLACKJACK_DEALER_WIN,
	BLACKJACK_NICHIA
};

char getValue() {

	char choise;
	do {
		std::cout << "You are want taking card: y or n" << std::endl;
		std::cin >> choise;
	} while (choise != 'y' && choise != 'n');

	return choise;
}

BlackjackResult playBlackjack(Deck &deck) {
	int playerPoint{};
	int dealerPoint{};
	int playerCountT{};
	int dealerCountT{};

	dealerPoint += deck.dealCard().getCardValue(dealerCountT);
	std::cout << "The dealer is showing: " << dealerPoint << '\n';
	playerPoint += deck.dealCard().getCardValue(playerCountT);
	playerPoint += deck.dealCard().getCardValue(playerCountT);

	while (1) {
		std::cout << "The gamer is showing: " << playerPoint << '\n';
		
		char variant = getValue();
		if (variant == 'n') {
			break;
		}

		playerPoint += deck.dealCard().getCardValue(playerCountT);
		if (playerPoint > 21 && playerCountT == 0) {
			return BlackjackResult::BLACKJACK_DEALER_WIN;
		}
		if (playerPoint > 21 && playerCountT != 0) {
			playerPoint -= 10;
		}

	}

	while (dealerPoint < 17) {
		dealerPoint += deck.dealCard().getCardValue(dealerCountT);
		std::cout << "The dealer now has: " << dealerPoint << '\n';
		
		if (dealerPoint > 21 && dealerCountT == 0)
			return BlackjackResult::BLACKJACK_PLAYER_WIN;
		if (dealerPoint > 21 && dealerCountT != 0)
			dealerPoint -= 10;
	}

	if (playerPoint > dealerPoint)		return BlackjackResult::BLACKJACK_PLAYER_WIN;
	else if (playerPoint < dealerPoint) return BlackjackResult::BLACKJACK_DEALER_WIN;
	else								return BlackjackResult::BLACKJACK_NICHIA;
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	rand();

	Deck deck;
	deck.shuffleDeck();

	switch (playBlackjack(deck))
	{
	case BlackjackResult::BLACKJACK_PLAYER_WIN:
		std::cout << "You won!!!";
		break;
	case BlackjackResult::BLACKJACK_DEALER_WIN:
		std::cout << "You lost!!!";
		break;
	case BlackjackResult::BLACKJACK_NICHIA:
		std::cout << "Dead heat!!!";
		break;
	default:
		std::cout << "Error, try to replay";
		break;
	}

	return 0;
}

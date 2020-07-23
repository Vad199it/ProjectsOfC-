#pragma once
#include <array>
#include "Card.h"

class Deck {
private:
	std::array<Card, 52> deck;
	static void swapCard(Card& card1, Card& card2);
	int m_cardIndex = 0;
	static int getRandomNumber(int min, int max);
public:
	Deck()
	{
		int card{};
		for (int i(0); i < Card::MAX_RANKS; ++i) {
			for (int j(0); j < Card::MAX_SUITS; ++j) {
				deck[card] = Card(static_cast<Card::CardRank>(i), static_cast<Card::CardSuit>(j));
				++card;
			}
		}
	}
	void printDeck() const;
	void shuffleDeck();
	const Card& dealCard();
	
};

#include <iostream>
#include "Deck.h"
#include "Card.h"

void Deck::printDeck() const {
	for (Card card : deck) {
		card.printCard();
		std::cout << ' ';
	}
	std::cout << std::endl;
}

void Deck::swapCard(Card & card1, Card & card2) {
	Card temp = card1;
	card1 = card2;
	card2 = temp;
}

void Deck::shuffleDeck() {
	for (int i(0); i < 52; ++i) {
		int swapIndex = getRandomNumber(0, 51);
		swapCard(deck[i], deck[swapIndex]);
	}
	m_cardIndex = 0;
}

const Card& Deck::dealCard() {
	return deck[m_cardIndex++];
}

int Deck::getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
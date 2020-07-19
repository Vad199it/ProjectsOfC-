#include <iostream>
#include <array>
#include <ctime>

enum class BlackjackResult
{
	BLACKJACK_PLAYER_WIN,
	BLACKJACK_DEALER_WIN,
	BLACKJACK_NICHIA
};

enum CardSuit
{
	SUIT_TREFU,
	SUIT_BYBNU,
	SUIT_CHERVU,
	SUIT_PIKI,
	MAX_SUITS
};

enum CardRank
{
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_VALET,
	RANK_DAMA,
	RANK_KOROL,
	RANK_TYZ,
	MAX_RANKS
};


struct Card
{
	CardRank rank;
	CardSuit suit;
};

void printCard(const Card &card) {
	switch (card.rank) {
	case RANK_2: std::cout << "2"; 
		break;
	case RANK_3: std::cout << "3";
		break;
	case RANK_4: std::cout << "4";
		break;
	case RANK_5: std::cout << "5";
		break;
	case RANK_6: std::cout << "6";
		break;
	case RANK_7: std::cout << "7";
		break;
	case RANK_8: std::cout << "8";
		break;
	case RANK_9: std::cout << "9";
		break;
	case RANK_10: std::cout << "10";
		break;
	case RANK_VALET: std::cout << "V";
		break;
	case RANK_DAMA: std::cout << "D";
		break;
	case RANK_KOROL: std::cout << "K";
		break;
	case RANK_TYZ: std::cout << "T";
		break;
	default:
		std::cout << "error";
		break;
	}

	switch (card.suit)
	{
	case SUIT_TREFU: std::cout << "T";
		break;
	case SUIT_BYBNU: std::cout << "B";
		break;
	case SUIT_CHERVU: std::cout << "C";
		break;
	case SUIT_PIKI: std::cout << "P";
		break;
	default:
		std::cout << "error";
		break;
	}
}

void printDeck(const std::array<Card, 52> &deck) {
	for (Card card : deck) {
		printCard(card);
		std::cout << ' ';
	}
	std::cout << std::endl;
}

void swapCard(Card &card1, Card &card2) {
	Card temp = card1;
	card1 = card2;
	card2 = temp;
}

void shuffleDeck(std::array<Card, 52> &deck) {
	for (int i(0); i < 52; ++i) {
		int r = ((rand() % 51) + 0);
		swapCard(deck[i], deck[r]);
	}
}

int getCardValue(const Card& card, int &countT)
{
	switch (card.rank)
	{
	case RANK_2:		
		return 2;
	case RANK_3:		
		return 3;
	case RANK_4:		
		return 4;
	case RANK_5:		
		return 5;
	case RANK_6:		
		return 6;
	case RANK_7:		
		return 7;
	case RANK_8:		
		return 8;
	case RANK_9:		
		return 9;
	case RANK_10:		
		return 10;
	case RANK_VALET:	
		return 10;
	case RANK_DAMA:	        
		return 10;
	case RANK_KOROL:	
		return 10;
	case RANK_TYZ:
		++countT;
		return 11;
	default:
		std::cout << "error";
		break;
	}
	return 0;
}

char getValue() {

	char choise;
	do {
		std::cout << "You are want taking card: y or n" << std::endl;
		std::cin >> choise;
	} while (choise != 'y' && choise != 'n');

	return choise;
}

BlackjackResult playBlackjack(std::array<Card, 52> &deck) {
	
	Card* card = &deck[0];
	int playerPoint{};
	int dealerPoint{};
	int countPlayerT{};
	int countDealerT{};
	
	dealerPoint += getCardValue(*card++, countDealerT);
	std::cout << "The dealer is showing: " << dealerPoint << '\n';
	playerPoint += getCardValue(*card++, countPlayerT);
	playerPoint += getCardValue(*card++, countPlayerT);

	while (1) {
		std::cout << "The gamer is showing: " << playerPoint << '\n';
		if (playerPoint > 21 && countPlayerT == 0) {
			return BlackjackResult::BLACKJACK_DEALER_WIN;
		}
		if(playerPoint > 21 && countPlayerT != 0){
				playerPoint -= 10;
		}

		char variant = getValue();
		if (variant == 'n') {
			break;
		}
		playerPoint += getCardValue(*card++, countPlayerT);
	}
	while (dealerPoint < 17) {
		dealerPoint += getCardValue(*card++, dealerPoint);
		std::cout << "The dealer now has: " << dealerPoint << '\n';

		if (dealerPoint > 21 && countDealerT == 0)
			return BlackjackResult::BLACKJACK_PLAYER_WIN;
		if (dealerPoint > 21 && countDealerT != 0)
			dealerPoint -= 10;
	}

	if (playerPoint > dealerPoint) return BlackjackResult::BLACKJACK_PLAYER_WIN;
	if (playerPoint == dealerPoint) return BlackjackResult::BLACKJACK_NICHIA;
}

int main()
{
	std::array<Card, 52> deck;
	int card{};

	for (int i(0); i < CardRank::MAX_RANKS; ++i) {
		for (int j(0); j < CardSuit::MAX_SUITS; ++j) {
			deck[card].rank = static_cast<CardRank>(i);
			deck[card].suit = static_cast<CardSuit>(j);
			++card;
		}
	}

	srand((int)time(0));
	shuffleDeck(deck);


	if (playBlackjack(deck) == BlackjackResult::BLACKJACK_PLAYER_WIN)
		std::cout << "You won!!!";
	else if (playBlackjack(deck) == BlackjackResult::BLACKJACK_DEALER_WIN)
		std::cout << "You lost!!!";
	else 
		std::cout << "Dead heat!!!";
}

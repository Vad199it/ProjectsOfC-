#pragma once

class Card {
public:
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

	enum CardSuit
	{
		SUIT_TREFU,
		SUIT_BYBNU,
		SUIT_CHERVU,
		SUIT_PIKI,
		MAX_SUITS
	};

private:
	CardRank m_rank;
	CardSuit m_suit;

public:
	Card(CardRank rank = MAX_RANKS, CardSuit suit = MAX_SUITS) :
		m_rank(rank), m_suit(suit)
	{

	}
	void printCard() const;
	int getCardValue(int& countT) const;
};

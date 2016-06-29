#pragma once

#include <vector>
#include <random>
#include <time.h>
#include <iostream>

struct Card {
	char suit;
	// Suit
	// - S - Spades
	// - H - Hearts
	// - D - Diamonds
	// - C - Clubs
	char value;

	bool used;

	bool isEqual(Card second) {
		if (this->suit == second.suit) {
			return true;
		}
		else if (this->value == second.value) {
			return true;
		}
		else return false;
	}
};

class Deck {
private:
	int randomNumber(int min, int max) { // Generate a random number between min and max
		srand((unsigned)time(0));
		int range  = (max - min);
		return min + int((range * rand()) / (RAND_MAX + 1.0));
	}

	std::vector<Card> mDeck;
public:
	Deck();
	~Deck();

	Card getRandomCardNoDuplicate(std::vector<Card> currentCards);

	// Operators
	friend bool operator== (const Card &n1, const Card &n2);
};
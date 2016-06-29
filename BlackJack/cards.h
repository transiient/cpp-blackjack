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

	bool used; // actually use this

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
	std::vector<Card> mDeck;

	int randomNumber(int min, int max) { // Generate a random number between min and max
		srand((unsigned)time(0));
		int range  = (max - min);
		return min + int((range * rand()) / (RAND_MAX + 1.0));
	}

	void flushDeckToDefault() {
		mDeck.push_back({ 'S', 'K', false });
		mDeck.push_back({ 'S', 'Q', false });
		mDeck.push_back({ 'S', 'J', false });
		mDeck.push_back({ 'S', '1', false });
		mDeck.push_back({ 'S', '2', false });
		mDeck.push_back({ 'S', '3', false });
		mDeck.push_back({ 'S', '4', false });
		mDeck.push_back({ 'S', '5', false });
		mDeck.push_back({ 'S', '6', false });
		mDeck.push_back({ 'S', '7', false });
		mDeck.push_back({ 'S', '8', false });
		mDeck.push_back({ 'S', '9', false });
		mDeck.push_back({ 'S', 'A', false });

		mDeck.push_back({ 'H', 'K', false });
		mDeck.push_back({ 'H', 'Q', false });
		mDeck.push_back({ 'H', 'J', false });
		mDeck.push_back({ 'H', '1', false });
		mDeck.push_back({ 'H', '2', false });
		mDeck.push_back({ 'H', '3', false });
		mDeck.push_back({ 'H', '4', false });
		mDeck.push_back({ 'H', '5', false });
		mDeck.push_back({ 'H', '6', false });
		mDeck.push_back({ 'H', '7', false });
		mDeck.push_back({ 'H', '8', false });
		mDeck.push_back({ 'H', '9', false });
		mDeck.push_back({ 'H', 'A', false });

		mDeck.push_back({ 'D', 'K', false });
		mDeck.push_back({ 'D', 'Q', false });
		mDeck.push_back({ 'D', 'J', false });
		mDeck.push_back({ 'D', '1', false });
		mDeck.push_back({ 'D', '2', false });
		mDeck.push_back({ 'D', '3', false });
		mDeck.push_back({ 'D', '4', false });
		mDeck.push_back({ 'D', '5', false });
		mDeck.push_back({ 'D', '6', false });
		mDeck.push_back({ 'D', '7', false });
		mDeck.push_back({ 'D', '8', false });
		mDeck.push_back({ 'D', '9', false });
		mDeck.push_back({ 'D', 'A', false });

		mDeck.push_back({ 'C', 'K', false });
		mDeck.push_back({ 'C', 'Q', false });
		mDeck.push_back({ 'C', 'J', false });
		mDeck.push_back({ 'C', '1', false });
		mDeck.push_back({ 'C', '2', false });
		mDeck.push_back({ 'C', '3', false });
		mDeck.push_back({ 'C', '4', false });
		mDeck.push_back({ 'C', '5', false });
		mDeck.push_back({ 'C', '6', false });
		mDeck.push_back({ 'C', '7', false });
		mDeck.push_back({ 'C', '8', false });
		mDeck.push_back({ 'C', '9', false });
		mDeck.push_back({ 'C', 'A', false });
	}
public:
	Deck();
	~Deck();

	Card getRandomCardNoDuplicate();
	
	void setCardUsed(Card card);
	void setCardUnused(Card card);

	// Operators
	friend bool operator== (const Card &n1, const Card &n2);
};
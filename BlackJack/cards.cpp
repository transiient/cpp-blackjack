#include "cards.h"

Deck::Deck() {
	flushDeckToDefault();
}

Deck::~Deck() {
	//.
}

void Deck::setCardUsed(Card card) {
	// Mark a card as used
	auto it = std::find(mDeck.begin(), mDeck.end(), card);
	if(it != mDeck.end())
		it->used = true;
}
void Deck::setCardUnused(Card card) {
	// Mark a card as unused / remove a card's used mark
	auto it = std::find(mDeck.begin(), mDeck.end(), card);
	if (it != mDeck.end())
		it->used = false;
}

Card Deck::getRandomCardNoDuplicate() {
	//NOTE: 52 cards - 0 to 51

	int randomCardIndex = randomNumber(0, 51);
	std::cout << "Generated a random number." << std::endl; // succeeds

	std::vector<Card> unusedCards; // Make a new vector for unused cards

	for (int count = 0; count < mDeck.size() - 1; count++) { // For every card in the main deck, we want to check to see if it's marked used
		if (!mDeck[count].used) { // Apparently it's failing here.
			unusedCards.push_back(mDeck[count]);
		} // If it is used, just loop the for statement
	}

	setCardUsed(unusedCards[randomCardIndex]);
	return unusedCards[randomCardIndex];
}

bool operator== (const Card &n1, const Card &n2)
{
	return n1.suit == n2.suit && n1.value == n2.value;
}
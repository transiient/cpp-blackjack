#include "cards.h"

Deck::Deck() {
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

Deck::~Deck() {
	//.
}

Card Deck::getRandomCardNoDuplicate(std::vector<Card> currentCards) {
	//NOTE: 52 cards - 0 to 51

	int cardIndex = randomNumber(0, 51);
	std::cout << "Generated a random number." << std::endl; // succeeds

	std::vector<Card> unusedCards; // make a new vector for unused cards
	
	for (int count = 0; count < mDeck.size() - 1; count++) {
		if (!currentCards.size() > 0) { // check if currentCards actually has cards
			// If it doesn't, then just generate a card from the original deck
			return unusedCards[count];
		}

		if (!currentCards[count].used) { // If the current card isn't used...
			std::cout << "Count: " << count << std::endl; // echo Count
			unusedCards.push_back(currentCards[count]); // Add current card at count to unusedCards
		}
	}

	for (int count = 0; count < unusedCards.size() - 1; count++) { // For each card...
		if (cardIndex == count) { // if the current card index is equal to the random number above...
			return unusedCards[count]; // return the new card
		}
	}
}

bool operator== (const Card &n1, const Card &n2)
{
	return n1.suit == n2.suit && n1.value == n2.value;
}
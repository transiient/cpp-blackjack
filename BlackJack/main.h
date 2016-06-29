#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

/*
 * AI Blackjack
*/

#include "cards.h" // Include our deck!

struct PlayerGS {
	int cash; // Starts with £260
	int whiteChips; // Worth £1
	int redChips; // Worth £5
	int greenChips; // Worth £25
	int blackChips; // Worth £100

	std::vector<Card> currentCards;
};
struct AiGS {
	int cash; // Starts with £260
	int whiteChips; // Worth £1
	int redChips; // Worth £5
	int greenChips; // Worth £25
	int blackChips; // Worth £100

	std::vector<Card> currentCards;
};
struct GameState { // Current state of the game (default is null) - everything is stored in here and saved to memory when it updates.
	PlayerGS PlayerGS;
	AiGS AiGS;
};

class BlackJack {
private:
	// The current game state
	GameState mGameState;
	// The default game state
	GameState mDefaultGameState = {
		{ 260,0,0,0,0,{} }, // .PlayerGS
		{ 260,0,0,0,0,{} }  // .AiGS
	};

	void printStr(char* string) { // Prints a string to the console
		std::cout << string << std::endl;
	}
public:
	BlackJack();
	~BlackJack();

	void showMenu(); // Shows the game menu

	// Dealing with current GameState
	const GameState getGameState() { return mGameState; } // Get the currently loaded GameState
	GameState resetCurrentState() { mGameState = mDefaultGameState; }; // Reset the currently loaded state to default values

	// Save and load states
	const bool saveGameStateToFile(); // Save the current GameState to a file
	GameState loadGameStateFromFile(); // Load a GameState from a file
	
	// Dealing with cards
	GameState addCardToPlayerDeck(Card card); // Add a card to the players' current deck
	GameState removeCardFromPlayerDeck(Card card); // Remove a card from the players' current deck
	GameState addCardToAIDeck(Card card); // Add a card to the players' current deck
	GameState removeCardFromAIDeck(Card card); // Remove a card from the players' current deck

	void startGame(); // Prepares and starts a game
};

int main(int argc, char* argv[]) {
	BlackJack();
}
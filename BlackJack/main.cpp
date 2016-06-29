#include "main.h"

// Gameplay stuffs

BlackJack::BlackJack() {
	// Constructs and starts a game

	showMenu();
}

BlackJack::~BlackJack() {
	system("EXIT");
}

// // //

void BlackJack::showMenu() {
	system("CLS");
	BlackJack::printStr("~~ Menu ~~");
	BlackJack::printStr("Press a key, then press enter");
	BlackJack::printStr("");
	BlackJack::printStr("1. Start new game");
	BlackJack::printStr("2. Load a game");
	BlackJack::printStr("3. Exit");

	std::string input; // instantiate input string
	std::getline(std::cin, input); // get line from console

	if (input == "1") { // if player presses 1, startGame, otherwise exit
		startGame();
	} else if (input == "2") {
		// load a game
		startGame();
	} else {
		system("EXIT");
	}
}

// // //

// Save and load states
const bool BlackJack::saveGameStateToFile() {
	return true;
}
GameState BlackJack::loadGameStateFromFile() {
	return mGameState;
}

// Dealing with cards
GameState BlackJack::addCardToPlayerDeck(Card card) {
	mGameState.PlayerGS.currentCards.push_back(card);
	return mGameState;
}
GameState BlackJack::removeCardFromPlayerDeck(Card card) {
	auto it = std::find(mGameState.PlayerGS.currentCards.begin(), mGameState.PlayerGS.currentCards.end(), card);
	if (it != mGameState.PlayerGS.currentCards.end())
		mGameState.PlayerGS.currentCards.erase(it); // from http://stackoverflow.com/questions/39912/how-do-i-remove-an-item-from-a-stl-vector-with-a-certain-value
	return mGameState;
}
GameState BlackJack::addCardToAIDeck(Card card) {
	mGameState.AiGS.currentCards.push_back(card);
	return mGameState;
}
GameState BlackJack::removeCardFromAIDeck(Card card) {
	auto it = std::find(mGameState.AiGS.currentCards.begin(), mGameState.AiGS.currentCards.end(), card);
	if (it != mGameState.AiGS.currentCards.end())
		mGameState.AiGS.currentCards.erase(it); // from http://stackoverflow.com/questions/39912/how-do-i-remove-an-item-from-a-stl-vector-with-a-certain-value
	return mGameState;
}

// Start game
void BlackJack::startGame() {
	int progress = 0;
	std::cout << progress << '%' << '\r' << std::flush;

	// Load a new card deck
	Deck deck;
	addCardToPlayerDeck(deck.getRandomCardNoDuplicate());
	addCardToPlayerDeck(deck.getRandomCardNoDuplicate());

	progress = 50;
	std::cout << progress << '%' << '\r' << std::flush;

	// Load another deck for AI
	addCardToAIDeck(deck.getRandomCardNoDuplicate());
	addCardToAIDeck(deck.getRandomCardNoDuplicate());

	progress = 99;
	std::cout << progress << '%' << '\r' << std::flush;

	system("CLS");

	printf("Welcome! You have two cards - they are the %c of %c and the %c of %c.",
		&mGameState.PlayerGS.currentCards[0].value,
		&mGameState.PlayerGS.currentCards[0].suit,
		&mGameState.PlayerGS.currentCards[1].value,
		&mGameState.PlayerGS.currentCards[1].suit); // access violation here :/

	system("PAUSE");
}
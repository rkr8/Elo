# Elo

## Description

### About

This is a small recreation of the Elo rating system.

### How to

To use this library, simply include `Elo.h` in your program and link `Elo.cpp` to your executable.
Here is an example, that shows the most important functions of this library:

	#include <iostream>
	
	#include "Elo.h"
	
	int main() {
		using namespace std;
		using namespace Elo;
	
		// create player
		Player player1 {"Bobby Fisher", 2785.};
		Player player2 {"Boris Spasski", 2690.};
	
		// print out winning chance of player1
		cout << estimateWinningChance(player1, player2) << endl;
	
		// create new result
		Result result = WIN;
	
		// player1 wins against player2
		changeElo(player1, player2, result);
	
		// print out new Elo numbers
		cout << player1.elo << "\t" << player2.elo << endl;
	
		// exit
		return 0;
	}

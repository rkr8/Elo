# Elo

## Description

### About

This is a small recreation of the Elo rating system.

### How to

To use this library, simply include `Elo.h` in your program.
Here is an example, that shows the most important functions of this library:

```cpp
...
// include namespaces
using namespace Elo::Types;
using namespace Elo::Methods;

// create new player
Player player1 = Player {
                          "Bobby Fisher",   // player name
                          2785              // Elo number
                        };
Player player2 = Player {
                          "Boris Spasski",  // player name
                          2690              // Elo number
                        };

// print out winning chance of player1
std::cout << estimateWinningChange(player, player2) << std::endl;

// create new result
Result result = WIN;

// player1 wins against player2
changeElo(player1, player2, result);

// print out new Elo numbers
std::cout << player1.elo << "\t" << player2.elo << std::endl;
...
```

#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include <cmath>
#include <stdexcept>
#include "Constants.h"
#include "Player.h"
#include "Result.h"

namespace Elo
{

using namespace std;

/*
 * This class represents one game. It holds
 * two player references and automatically
 * updates their Elo if a result is clear.
 */
class Game
{
  /*
   * Attributes of the Game class
   */
public:
  // this constant value specifies the impact of each game
  const double HARDNESS;

private:
  // reference is needed for updating the Elo
  Player &playerA;
  Player &playerB;

  /*
   * Methods of the Game class
   */
public:
  Game(Player &a, Player &b, double h = DEFAULT_HARDNESS);
  const Player &getPlayerA() const;
  const Player &getPlayerB() const;
  void setPlayerA(Player &a);
  void setPlayerB(Player &b);
  // makes two game objects comparable
  bool equals(const Game &g) const;
  // makes the comparison via the == and != operator possible
  bool operator==(const Game &g) const;
  bool operator!=(const Game &g) const;
  // Result for playerA
  void updateElo(const Result &r);

private:
  // returns the probability that playerA wins the game
  double winningChancePlayerA() const;
  // Elo formulas require numeric value
  double convertResultToDouble(const Result &r) const;
};

// makes the output via the << operator possible
ostream &operator<<(ostream &o, const Game &g);

}

#endif

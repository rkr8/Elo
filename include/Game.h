#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include <cmath>
#include <stdexcept>
#include "Constants.h"
#include "Player.h"

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
    Game(Player &a, Player &b, double h = DEFAULT_HARDNESS) : playerA(a),
                                                              playerB(b),
                                                              HARDNESS(h < 0. // throws an invalid argument exception on negative HARDNESS
                                                                           ? throw invalid_argument("HARDNESS can't be negative.")
                                                                           : h)
    {
    }
    const Player &getPlayerA() const
    {
        return playerA;
    }
    const Player &getPlayerB() const
    {
        return playerB;
    }
    void setPlayerA(Player &a)
    {
        playerA = a;
    }
    void setPlayerB(Player &b)
    {
        playerB = b;
    }
    // makes two game objects comparable
    bool equals(const Game &g) const
    {
        return (HARDNESS == g.HARDNESS &&
                getPlayerA() == g.getPlayerA() &&
                getPlayerB() == g.getPlayerB());
    }
    // makes the comparison via the == and != operator possible
    bool operator==(const Game &g) const
    {
        return equals(g);
    }
    bool operator!=(const Game &g) const
    {
        return !equals(g);
    }
    void updateElo(const Result &r) // Result for playerA
    {
        // Elo-specific formulas
        playerA.setElo(playerA.getElo() +
                       HARDNESS *
                           (convertResultToDouble(r) -
                            winningChancePlayerA()));
        playerB.setElo(playerB.getElo() +
                       HARDNESS *
                           (winningChancePlayerA() -
                            convertResultToDouble(r)));
    }

  private:
    // returns the probability that playerA wins the game
    double winningChancePlayerA() const
    {
        return 1. / (1. + pow(10., (playerB.getElo() - playerA.getElo()) / 400.));
    }
    // Elo formulas require numeric value
    double convertResultToDouble(const Result &r) const
    {
        switch (r)
        {
        case WIN:
            return 1.;
            break;
        case DRAW:
            return .5;
            break;
        case LOSE:
            return 0.;
            break;
        default: // propably won't happen
            return DEFAULT_RESULT;
            break;
        }
    }
};

// makes the output via the << operator possible
ostream &operator<<(ostream &o, const Game &g)
{
    o << g.getPlayerA() << ", " << g.getPlayerB();
}

}

#endif

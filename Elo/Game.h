#include <iostream>
#include <cmath>
#include "Player.h"

#ifndef __GAME_H__
#define __GAME_H__

namespace Elo {

    using namespace std;
    
    /*
     * This class represents one game. It holds
     * two player references and automatically
     * updates their Elo if a result is clear.
     */
    class Game {
    public:
        // this constant value specifies the impact of each game
        const double HARDNESS;
    private:
        // reference is needed for updating the Elo
        Player &playerA;
        Player &playerB;
    public:
        Game(double h, Player &a, Player &b) : HARDNESS(h), playerA(a), playerB(b) {}
        // getters
        const Player& getPlayerA() const {
            return playerA;
        }
        const Player& getPlayerB() const {
            return playerB;
        }
        // setters
        void setPlayerA(Player &a) {
            playerA = a;
        }
        void setPlayerB(Player &b) {
            playerB = b;
        }
        // makes two game objects comparable
        bool equals(const Game &g) const {
            return (HARDNESS == g.HARDNESS &&
                getPlayerA() == g.getPlayerA() &&
                getPlayerB() == g.getPlayerB());
        }
        // makes the comparison via the == and != operator possible
        bool operator==(const Game &g) const {
            return equals(g);
        }
        bool operator!=(const Game &g) const {
            return !equals(g);
        }
        // returns the probability that playerA wins the game
        double winningChancePlayerA() {
            return 1. / (1. + pow(10., (playerB.getElo() - playerA.getElo()) / 400.));
        }
        void updateElo(const Result &r) {
            // both formulas are from wikipedia
            playerA.setElo(playerA.getElo() + HARDNESS * (r.getOutcomeAsDouble() - winningChancePlayerA()));
            playerB.setElo(playerB.getElo() + HARDNESS * ((1. - r.getOutcomeAsDouble()) - (1. - winningChancePlayerA())));
        }
    };
    
    // makes the output via the << operator possible
    ostream& operator<<(ostream &o, const Game &g) {
        o << g.getPlayerA() << ", " << g.getPlayerB();
    }
}

#endif

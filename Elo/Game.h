#include <iostream>
#include <cmath>

#ifndef __GAME_H__
#define __GAME_H__

namespace Elo {

    using namespace std;

    // this value specifies the impact of each game
    const double HARDNESS = 10.;
    
    /*
     * This class represents one game. It holds
     * two player references and automatically
     * updates their Elo if a result is clear.
     */
    class Game {
    private:
        // reference is needed for updating the Elo
        Player &playerA;
        Player &playerB;
    public:
        Game(Player &a, Player &b) : playerA(a), playerB(b) {}
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

#include <stdexcept>
#include "../include/Constants.h"
#include "../include/Game.h"
#include "../include/Player.h"
#include "../include/Result.h"

namespace Elo
{

using namespace std;

Game::Game(Player &a, Player &b, double h) : playerA(a),
                                             playerB(b),
                                             HARDNESS(h < 0. // throws an invalid argument exception on negative HARDNESS
                                                          ? throw invalid_argument("HARDNESS can't be negative.")
                                                          : h)
{
}

const Player &Game::getPlayerA() const
{
    return playerA;
}

const Player &Game::getPlayerB() const
{
    return playerB;
}

void Game::setPlayerA(Player &a)
{
    playerA = a;
}

void Game::setPlayerB(Player &b)
{
    playerB = b;
}

bool Game::equals(const Game &g) const
{
    return (HARDNESS == g.HARDNESS &&
            getPlayerA() == g.getPlayerA() &&
            getPlayerB() == g.getPlayerB());
}

bool Game::operator==(const Game &g) const
{
    return equals(g);
}

bool Game::operator!=(const Game &g) const
{
    return !equals(g);
}

void Game::updateElo(const Result &r)
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

double Game::winningChancePlayerA() const
{
    return 1. / (1. + pow(10., (playerB.getElo() - playerA.getElo()) / 400.));
}

double Game::convertResultToDouble(const Result &r) const
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

ostream &operator<<(ostream &o, const Game &g)
{
    o << g.getPlayerA() << ", " << g.getPlayerB();
}

}

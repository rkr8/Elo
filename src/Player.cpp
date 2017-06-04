#include <string>
#include "../include/Constants.h"
#include "../include/Player.h"

namespace Elo
{
using namespace std;

Player::Player(const string &n, double e) : name(n),
                                            elo(e < 0. // throws an invalid argument exception on negative elo
                                                    ? throw invalid_argument("Elo can't be negative.")
                                                    : e)
{
}

const string &Player::getName() const
{
    return name;
}

double Player::getElo() const
{
    return elo;
}

void Player::setName(const string &n)
{
    name = n;
}

void Player::setElo(double e)
{
    elo = e < 0. // throws an invalid argument exception on negative elo
              ? throw invalid_argument("Elo can't be negative.")
              : e;
}

bool Player::equals(const Player &p) const
{
    return (getName() == p.getName() &&
            getElo() == p.getElo());
}

bool Player::operator==(const Player &p) const
{
    return equals(p);
}

bool Player::operator!=(const Player &p) const
{
    return !equals(p);
}

// makes the output via the << operator possible
ostream &operator<<(ostream &o, const Player &p)
{
    o << p.getName() << ", " << p.getElo();
}

}

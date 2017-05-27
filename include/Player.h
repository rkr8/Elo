#include <iostream>
#include <string>
#include <stdexcept>
#include "Constants.h"

#ifndef __PLAYER_H__
#define __PLAYER_H__

namespace Elo
{

using namespace std;

/*
 * This class stores the name and Elo of a player.
 */
class Player
{
  private:
    string name;
    double elo;

  public:
    Player(const string &n = DEFAULT_NAME, double e = DEFAULT_ELO) : name(n),
                                                                     elo(e < 0.
                                                                             ? throw invalid_argument("Elo can't be negative.")
                                                                             : e) {}
    // getters
    const string &getName() const
    {
        return name;
    }
    double getElo() const
    {
        return elo;
    }
    // setters
    void setName(const string &n)
    {
        name = n;
    }
    void setElo(double e)
    {
        elo = e < 0.
                  ? throw invalid_argument("Elo can't be negative.")
                  : e;
    }
    // makes two player objects comparable
    bool equals(const Player &p) const
    {
        return (getName() == p.getName() &&
                getElo() == p.getElo());
    }
    // makes the comparison via the == and != operator possible
    bool operator==(const Player &p) const
    {
        return equals(p);
    }
    bool operator!=(const Player &p) const
    {
        return !equals(p);
    }
};

// makes the output via the << operator possible
ostream &operator<<(ostream &o, const Player &p)
{
    o << p.getName() << ", " << p.getElo();
}

}

#endif

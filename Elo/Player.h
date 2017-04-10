#include <iostream>
#include <string>

#ifndef __PLAYER_H__
#define __PLAYER_H__

namespace Elo
{

using namespace std;

const string DEFAULT_NAME = "";
const double DEFAULT_ELO = 1000.;

/*
 * This class stores the name and Elo of a player.
 */
class Player
{
  private:
    string name;
    double elo;

  public:
    Player(const string &n = DEFAULT_NAME, double e = DEFAULT_ELO) : name(n), elo(e) {}
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
        elo = e;
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

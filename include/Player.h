#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <string>
#include <stdexcept>
#include "Constants.h"

namespace Elo
{

using namespace std;

/*
 * This class stores the name and Elo of a player.
 */
class Player
{
    /*
     * Attributes of the Player class
     */
  private:
    string name;
    double elo;

    /*
     * Methods of the Game class
     */
  public:
    Player(const string &n, double e);
    // getters
    const string &getName() const;
    double getElo() const;
    // setters
    void setName(const string &n);
    void setElo(double e);
    // makes two player objects comparable
    bool equals(const Player &p) const;
    // makes the comparison via the == and != operator possible
    bool operator==(const Player &p) const;
    bool operator!=(const Player &p) const;
};

// makes the output via the << operator possible
ostream &operator<<(ostream &o, const Player &p);

}

#endif

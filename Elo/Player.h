#include <iostream>
#include <string>

#ifndef __PLAYER_H__
#define __PLAYER_H__

namespace Elo {
    
    using namespace std;
    
    const string DEFAULT_NAME = "";
    const double DEFAULT_ELO = 1000.;
    
    class Player {
    private:
        string name;
		double elo;
    public:
        // reference for better performance
        Player(const string &n = DEFAULT_NAME, double e = DEFAULT_ELO) : name(n), elo(e) {}
        // getters
        const string& getName() const {
            return name;
        }
        double getElo() const {
            return elo;
        }
        // setters 
        void setName(const string& n) {
            name = n;
        }
        void setElo(double e) {
            elo = e;
        }
	};
    
    ostream& operator<<(ostream &o, const Player &p) {
        o << p.getName() << ", " << p.getElo();
    }
}

#endif

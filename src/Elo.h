#ifndef ELO_H
#define ELO_H

#include <iostream>
#include <cmath>
#include <string>

namespace Elo {

using namespace std;

namespace Constants {

const double HARDNESS = 10.;

}

namespace Types {

struct Player {
	string name;
	double elo;
};

enum Result {
	WIN, DRAW, LOSE
};

}

namespace Methods {

double getResultAsDouble(const Types::Result&);

double estimateWinningChange(Types::Player&, Types::Player&);

void changeElo(Types::Player&, Types::Player&, const Types::Result&);

}

}

#endif

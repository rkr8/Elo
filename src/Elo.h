#include <string>

#ifndef ELO_H
#define ELO_H

namespace Elo {

	using namespace std;

	struct Player {
		string name;
		double elo;
	};

	enum Result {
		WIN, DRAW, LOSE
	};

	const double HARDNESS = 10.;

	double getResultAsDouble(Result&);

	double estimateWinningChance(Player&, Player&);

	void changeElo(Player&, Player&, Result&);

}

#endif

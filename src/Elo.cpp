#include <cmath>

#include "Elo.h"

namespace Elo {

	double getResultAsDouble(Result& r) {
		switch (r) {
		case WIN:
			return 1.;
		case LOSE:
			return 0.;
		case DRAW:
		default:
			return .5;
		}
	}

	double estimateWinningChance(Player& a, Player& b) {
		return 1. / (1. + pow(10., (b.elo - a.elo) / 400.));
	}

	void changeElo(Player& a, Player& b, Result& r) {
		a.elo += HARDNESS * (getResultAsDouble(r) - estimateWinningChance(a, b));
		b.elo += HARDNESS * (1. - getResultAsDouble(r) - 1. + estimateWinningChance(a, b));
	}

}

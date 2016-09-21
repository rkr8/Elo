#include "Elo.h"

namespace Elo {

double Methods::getResultAsDouble(const Types::Result& r) {
	switch (r) {
	case Types::WIN:
		return 1.;
	case Types::DRAW:
		return .5;
	case Types::LOSE:
		return 0.;
	}
	return .5;
}

double Methods::estimateWinningChange(Types::Player& a, Types::Player& b) {
	return 1. / (1. + pow(10., (b.elo - a.elo) / 400.));
}

void Methods::changeElo(Types::Player& a, Types::Player& b,
		const Types::Result& r) {
	a.elo += Constants::HARDNESS
			* (Methods::getResultAsDouble(r) - estimateWinningChange(a, b));
	b.elo += Constants::HARDNESS
			* (1. - Methods::getResultAsDouble(r) - 1.
					+ estimateWinningChange(a, b));
}

}


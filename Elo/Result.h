#include <iostream>

#ifndef __RESULT_H__
#define __RESULT_H__

namespace Elo {
    
    using namespace std;
    
    /*
     * This class stores information about the
     * outcome of a game and converts them to
     * a numeric value.
     */
    class Result {
    public:
        enum Possibilities {
            WIN,
            DRAW,
            LOSE
        };
    private:
        Possibilities outcome;
    public:
        Result(const Possibilities &o = DRAW) : outcome(o) {}
        // getters
        const Possibilities& getOutcome() const {
            return outcome;
        }
        // setters
        void setOutcome(const Possibilities &o) {
            outcome = o;
        }
        // convert to double
        double getOutcomeAsDouble() const {
            switch(outcome) {
            case WIN:
                return 1.;
                break;
            case DRAW:
                return .5;
                break;
            case LOSE:
                return 0.;
                break;
            }
        }
    };
    
    // makes the output via the << operator possible
    ostream& operator<<(ostream &o, const Result &r) {
        switch(r.getOutcome()) {
        case Result::WIN:
            o << "WIN";
            break;
        case Result::DRAW:
            o << "DRAW";
            break;
        case Result::LOSE:
            o << "LOSE";
            break;
        }
    }
}

#endif

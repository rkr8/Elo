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
        enum Possibility {
            WIN,
            DRAW,
            LOSE
        };
    private:
        Possibility outcome;
    public:
        Result(const Possibility &o = DRAW) : outcome(o) {}
        // getters
        const Possibility& getOutcome() const {
            return outcome;
        }
        // setters
        void setOutcome(const Possibility &o) {
            outcome = o;
        }
        // makes two result objects comparable
        bool equals(const Result &r) const {
            return (getOutcome() == r.getOutcome());
        }
        // makes the comparison via the == and != operator possible
        bool operator==(const Result &r) const {
            return equals(r);
        }
        bool operator!=(const Result &r) const {
            return !equals(r);
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

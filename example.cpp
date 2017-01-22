#include <iostream>
#include "Elo/Elo.h"

using namespace std;

int main() {
    using namespace Elo;
    
    Player p("Magnus Carlsen", 2840.);
    Player q("Viswanathan Anand", 2786.);
    
    Result r(Result::WIN);
    
    Game g(p, q);
    
    cout << r << endl << g << endl;
    
    g.updateElo(r);
    
    cout << p << endl << q << endl;
    
    return 0;
}

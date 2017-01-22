# Elo

## Description

### About

This is a small recreation of the Elo rating system.

### How to

To use this library, simply include `Elo/Elo.h` in your program.
Here is an example, that shows the most important functions of this library:

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

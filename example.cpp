#include <iostream>
#include "include/Elo.h"

using namespace std;

int main()
{
    using namespace Elo;

    Player p("Magnus Carlsen", 2840.);
    Player q("Viswanathan Anand", 2786.);

    cout << (p == q) << endl;

    Game g(p, q);

    cout << g << endl;

    g.updateElo(WIN); // Magnus won!

    cout << p << endl
         << q << endl;

    return 0;
}

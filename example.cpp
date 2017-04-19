#include <iostream>
#include "Elo/Elo.h"

using namespace std;

int main()
{
    using namespace Elo;

    Player p("Magnus Carlsen", 2840.);
    Player q("Viswanathan Anand", 2786.);

    cout << (p == q) << endl;

    Game g(10., p, q);

    Result r(Result::WIN);

    cout << r << endl
         << g << endl;

    g.updateElo(r);

    cout << p << endl
         << q << endl;

    return 0;
}

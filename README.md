# Elo

## Badges

[![Build Status](https://travis-ci.org/rkr8/Elo.svg?branch=master)](https://travis-ci.org/rkr8/Elo)

## Description

### About

This is a small recreation of the Elo rating system.

### How to

To use this library, simply include `Elo/Elo.h` in your program.
Here is an example, that shows the most important features of this library:

```c++
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
```

To build and run this example, clone the repository and run `make && ./example`.
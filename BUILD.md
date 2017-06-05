# Elo

## Building

Thanks to CMake, the build process is pretty straight-forward.
First, make sure you have installed `CMake` and `make` (on Linux).
Then, get the code using `git clone https://github.com/rkr8/Elo.git && cd Elo`.
Next, you have to create a new `build` directory with `mkdir build && cd build`.
In order to build the library, you either have to execute `cmake ..` (that's probably, what you want)
or `cmake -DBUILD_TESTS ..` (if you want to build the tests too).
Finally, you have to invoke your build system. On linux, you can simply type `make`.

## Installation

If you want to use the headers easily (like `#include <Elo/Elo.h>`),
you can call the installation routine of your build system.
On linux, you can do that by typing `sudo make install`.

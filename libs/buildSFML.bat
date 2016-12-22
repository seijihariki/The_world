cd SFML
cmake -G "MinGW Makefiles" -DCMAKE_CXX_FLAGS=-m32 -DSIZEOF_VOID_PTR=4 .
mingw32-make
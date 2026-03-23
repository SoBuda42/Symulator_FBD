#ifndef WYJSCIE_H
#define WYJSCIE_H

#include "Wartosc.h"

class Wyjscie
{
    private:
        int numer;
        Wartosc wartosc;
    public:
        Wartosc pobierz_wartosc();

        void ustaw_wartosc(Wartosc nowa);
};

#endif
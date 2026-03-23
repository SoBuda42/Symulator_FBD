#ifndef WARTOSC_H
#define WARTOSC_H

#include "Definicje.h"
#include "Stempel_czasowy.h"

class Wartosc 
{
    private:
        double wartosc;
        Status_wartosci status;
        Stempel_czasowy stempel_czasowy;
    public:
        double pobierz_liczbe() {return wartosc;}

        void ustaw_liczbe(double nowa_liczba) {wartosc = nowa_liczba;}
};

#endif
#include "Blok_stalej.h"
#include "Wyjscie.h"

Blok_stalej::Blok_stalej(double wartosc) {ukryta_wartosc = wartosc;}

void Blok_stalej::przelicz()
{
    if(wyjscia.size()>0)
    {
        Wartosc stala;
        stala.ustaw_liczbe(ukryta_wartosc);
        wyjscia[0]->ustaw_wartosc(stala);
    }
}
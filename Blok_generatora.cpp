#include "Blok_generatora.h"

Blok_generatora::Blok_generatora(double amp, int okr)
{
    amplituda = amp;
    okres = okr;
    licznik_krokow = 0;

    wyjscia.push_back(new Wyjscie());
}

void Blok_generatora::przelicz()
{
    int ktory_krok = licznik_krokow % okres;
    double status;

    if(ktory_krok<okres/2.0) {status=amplituda;}
    else {status=0.0;}

    Wartosc nowa_wartosc;
    nowa_wartosc.ustaw_liczbe(status);
    wyjscia[0]->ustaw_wartosc(nowa_wartosc);

    licznik_krokow++;
}
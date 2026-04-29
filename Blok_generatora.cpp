#include "Blok_generatora.h"

Blok_generatora::Blok_generatora(double amp, int okr)
{
    licznik_krokow = 0;
    amplituda = amp;
    okres = okr;

    wyjscia.push_back(new Wyjscie());
}

void Blok_generatora::przelicz()
{
    int ktory_krok = licznik_krokow % okres;
    double status = 0.0;

    if(ktory_krok<okres/2.0) {status=amplituda;}
    else {status=0.0;}

    Wartosc nowa_wartosc;
    nowa_wartosc.ustaw_liczbe(status);
    
    Wyjscie* gniazdo = dynamic_cast<Wyjscie*>(wyjscia[0]);
    if(gniazdo!=nullptr) {gniazdo->ustaw_wartosc(nowa_wartosc);}

    licznik_krokow++;
}

void Blok_generatora::inicjalizuj() {}
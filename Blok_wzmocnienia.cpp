#include "Blok_wzmocnienia.h"
#include "Wejscie.h"
#include "Wyjscie.h"
#include "Wartosc.h"

Blok_wzmocnienia::Blok_wzmocnienia(double w) {wspolczynnik = w;}

void Blok_wzmocnienia::przelicz()
{
    if(wejscia.size()>0 && wyjscia.size()>0)
    {
        double sygnal = wejscia[0]->odczytaj_wartosc().pobierz_liczbe();
        double wzmocnienie = sygnal*wspolczynnik;

        Wartosc nowa_wartosc;
        nowa_wartosc.ustaw_liczbe(wzmocnienie);
        wyjscia[0]->ustaw_wartosc(nowa_wartosc);
    }
}
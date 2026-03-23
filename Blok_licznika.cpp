#include "Blok_licznika.h"
#include "Wejscie.h"
#include "Wyjscie.h"
#include "Wartosc.h"

Blok_licznika::Blok_licznika() {stan_licznika=0;}

void Blok_licznika::przelicz()
{
    if(wejscia.size()>0 && wyjscia.size()>0)
    {
        if(wejscia[0]->odczytaj_wartosc().pobierz_liczbe() > 0.0) stan_licznika++;

        Wartosc aktualna_wartosc;
        aktualna_wartosc.ustaw_liczbe(stan_licznika);
        wyjscia[0]->ustaw_wartosc(aktualna_wartosc);
    }
}
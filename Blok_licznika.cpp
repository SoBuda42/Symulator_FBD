#include "Blok_licznika.h"
#include "Wejscie.h"
#include "Wyjscie.h"
#include "Wartosc.h"

Blok_licznika::Blok_licznika() 
{
    stan_licznika=0;
    wyjscia.push_back(new Wyjscie());
}

void Blok_licznika::przelicz()
{
    if(wejscia.size()>0 && wyjscia.size()>0)
    {
        if(wejscia[0]->odczytaj_wartosc().pobierz_liczbe() > 0.0) stan_licznika++;

        Wartosc aktualna_wartosc;
        aktualna_wartosc.ustaw_liczbe(stan_licznika);

        Wyjscie* gniazdo = dynamic_cast<Wyjscie*>(wyjscia[0]);
        if(gniazdo!=nullptr) {gniazdo->ustaw_wartosc(aktualna_wartosc);}
    }
}

void Blok_licznika::inicjalizuj() {}
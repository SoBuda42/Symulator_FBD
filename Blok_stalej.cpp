#include "Blok_stalej.h"
#include "Wyjscie.h"

Blok_stalej::Blok_stalej(double wartosc) 
{
    ukryta_wartosc = wartosc;
    wyjscia.push_back(new Wyjscie());
}

void Blok_stalej::przelicz()
{
    if(wyjscia.size()>0)
    {
        Wartosc stala;
        stala.ustaw_liczbe(ukryta_wartosc);
        
        Wyjscie* gniazdo = dynamic_cast<Wyjscie*>(wyjscia[0]);
        if(gniazdo!=nullptr) {gniazdo->ustaw_wartosc(stala);}
    }
}

void Blok_stalej::inicjalizuj() {}
#include "Blok_wzmocnienia.h"
#include "Wejscie.h"
#include "Wyjscie.h"
#include "Wartosc.h"

Blok_wzmocnienia::Blok_wzmocnienia(double w) 
{
    wspolczynnik = w;
    wejscia.push_back(new Wejscie());
    wyjscia.push_back(new Wyjscie());
}

void Blok_wzmocnienia::przelicz()
{
    if(wejscia.size()>0 && wyjscia.size()>0)
    {
        double sygnal = wejscia[0]->odczytaj_wartosc().pobierz_liczbe();
        double wzmocnienie = sygnal*wspolczynnik;

        Wartosc nowa_wartosc;
        nowa_wartosc.ustaw_liczbe(wzmocnienie);
        
        Wyjscie* gniazdo = dynamic_cast<Wyjscie*>(wyjscia[0]);
        if(gniazdo!=nullptr) {gniazdo->ustaw_wartosc(nowa_wartosc);}
    }
}

void Blok_wzmocnienia::inicjalizuj() {}
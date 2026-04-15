#include "Blok_calkowania.h"
#include "Wejscie.h"
#include "Wyjscie.h"
#include "Wartosc.h"

Blok_calkowania::Blok_calkowania()
{
    suma_calkowita = 0.0;
    wyjscia.push_back(new Wyjscie());
}

void Blok_calkowania::inicjalizuj() {}

void Blok_calkowania::przelicz() 
{
    if(wejscia.size()>0 && wyjscia.size()>0)
    {
        double biezacy_sygnal = wejscia[0]->odczytaj_wartosc().pobierz_liczbe();
        suma_calkowita += biezacy_sygnal;

        Wartosc wynik;
        wynik.ustaw_liczbe(suma_calkowita);

        Wyjscie* gniazdo = dynamic_cast<Wyjscie*>(wyjscia[0]);
        if(gniazdo!=nullptr) {gniazdo->ustaw_wartosc(wynik);}
    }
}
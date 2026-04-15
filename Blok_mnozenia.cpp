#include "Blok_mnozenia.h"
#include "Wejscie.h"
#include "Wyjscie.h"
#include "Wartosc.h"

Blok_mnozenia::Blok_mnozenia() {wyjscia.push_back(new Wyjscie());}

void Blok_mnozenia::przelicz() 
{
    if (wejscia.size()==0) return;

    double iloczyn = wejscia[0]->odczytaj_wartosc().pobierz_liczbe();

    for(int i=1; i < wejscia.size(); i++)
    {
        
        iloczyn *= wejscia[i]->odczytaj_wartosc().pobierz_liczbe(); 
    }

    if(wyjscia.size() > 0)
    {
        Wartosc wynik;
        wynik.ustaw_liczbe(iloczyn);

        Wyjscie* gniazdo = dynamic_cast<Wyjscie*>(wyjscia[0]);
        if(gniazdo!=nullptr) {gniazdo->ustaw_wartosc(wynik);}
    }
}

void Blok_mnozenia::inicjalizuj() {}
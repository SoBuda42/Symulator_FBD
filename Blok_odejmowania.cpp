#include "Blok_odejmowania.h"
#include "Wejscie.h"
#include "Wyjscie.h"
#include "Wartosc.h"

void Blok_odejmowania::przelicz() 
{
    if (wejscia.size()==0) return;

    double roznica = wejscia[0]->odczytaj_wartosc().pobierz_liczbe();

    for(int i=1; i < wejscia.size(); i++)
    {
        
        roznica -= wejscia[i]->odczytaj_wartosc().pobierz_liczbe(); 
    }

    if(wyjscia.size() > 0)
    {
        Wartosc wynik;
        wynik.ustaw_liczbe(roznica);
        
        Wyjscie* gniazdo = dynamic_cast<Wyjscie*>(wyjscia[0]);
        if(gniazdo!=nullptr) {gniazdo->ustaw_wartosc(wynik);}
    }
}
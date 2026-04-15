#include "Blok_dodawania.h"
#include "Wejscie.h"
#include "Wyjscie.h"
#include "Wartosc.h"

void Blok_dodawania::przelicz() 
{
    if (wejscia.size()==0) return;

    double suma = 0.0;
    for(int i=0; i < wejscia.size(); i++)
    {
        
        suma += wejscia[i]->odczytaj_wartosc().pobierz_liczbe(); 
    }

    // if(wyjscia.size() > 0)
    // {
    //     Wartosc wynik;
    //     wynik.ustaw_liczbe(suma);
    //     wyjscia[0]->ustaw_wartosc(wynik);
    // }
}

void Blok_dodawania::inicjalizuj() {}
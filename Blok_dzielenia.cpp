#include "Blok_dzielenia.h"
#include "Wejscie.h"
#include "Wyjscie.h"
#include "Wartosc.h"

void Blok_dzielenia::przelicz() 
{
    if (wejscia.size()==0) return;

    double iloraz = wejscia[0]->odczytaj_wartosc().pobierz_liczbe();

    for(int i=1; i < wejscia.size(); i++)
    {
        double mianownik = wejscia[i]->odczytaj_wartosc().pobierz_liczbe();
        if(mianownik!=0) iloraz /= mianownik;
        else iloraz = 0.0;
    }

    if(wyjscia.size() > 0)
    {
        Wartosc wynik;
        wynik.ustaw_liczbe(iloraz);
        wyjscia[0]->ustaw_wartosc(wynik);
    }
}
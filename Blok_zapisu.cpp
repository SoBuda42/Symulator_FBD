#include "Blok_zapisu.h"
#include "Wejscie.h"
#include "Wyjscie.h"
#include "Wartosc.h"
#include <fstream>

using namespace std;

Blok_zapisu::Blok_zapisu(string nazwa_p) 
{
    nazwa_pliku=nazwa_p;
    plik.open(nazwa_pliku);

    wejscia.push_back(new Wejscie());
    wyjscia.push_back(new Wyjscie());
}

Blok_zapisu::~Blok_zapisu() {if(plik.is_open()) plik.close();}

void Blok_zapisu::inicjalizuj() {}

void Blok_zapisu::przelicz()
{
    double ostatnia_liczba = 0.0;

    if(wejscia.size()>0)
    {
        for(int i=0; i<wejscia.size(); i++)
        {
            double liczba = wejscia[i]->odczytaj_wartosc().pobierz_liczbe();
            if(plik.is_open()) plik<<liczba<<" "<<endl;
            ostatnia_liczba = liczba;
        }
        if(plik.is_open()) plik<<"\n";
    }

    if(wyjscia.size() > 0) 
    {
        Wartosc wynik;
        wynik.ustaw_liczbe(ostatnia_liczba);
            
        Wyjscie* gniazdo = dynamic_cast<Wyjscie*>(wyjscia[0]);
        if(gniazdo != nullptr) {
                gniazdo->ustaw_wartosc(wynik);
        }
    }
    
}
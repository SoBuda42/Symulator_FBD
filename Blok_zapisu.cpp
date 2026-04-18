#include "Blok_zapisu.h"
#include "Wejscie.h"
#include "Wartosc.h"
#include <fstream>

using namespace std;

Blok_zapisu::Blok_zapisu(string nazwa_p) 
{
    nazwa_pliku=nazwa_p;
    plik.open(nazwa_pliku);

    wejscia.push_back(new Wejscie());
}

Blok_zapisu::~Blok_zapisu() {if(plik.is_open()) {plik.close();}}

void Blok_zapisu::inicjalizuj() {}

void Blok_zapisu::przelicz()
{
    if(plik && wejscia.size()>0)
    {
        for(int i=0; i<wejscia.size(); i++)
        {
            double liczba = wejscia[i]->odczytaj_wartosc().pobierz_liczbe();
            plik<<liczba<<" ";
        }
        plik<<"\n";
    }
}
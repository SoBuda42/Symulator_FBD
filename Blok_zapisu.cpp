#include "Blok_zapisu.h"
#include "Wejscie.h"
#include "Wartosc.h"

#include <fstream>

using namespace std;

Blok_zapisu::Blok_zapisu(string nazwa_p) {nazwa_pliku=nazwa_p;}

void Blok_zapisu::przelicz()
{
    ofstream plik(nazwa_pliku, ios::app);
    if(plik)
    {
        for(int i=0; i<wejscia.size(); i++)
        {
            double liczba;
            liczba = wejscia[i]->odczytaj_wartosc().pobierz_liczbe();
            plik<<liczba<<" ";
        }
        plik<<endl;
        plik.close();
    }
}
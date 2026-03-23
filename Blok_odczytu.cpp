#include "Blok_odczytu.h"
#include "Wyjscie.h"

Blok_odczytu::Blok_odczytu(string nazwa_p) {plik.open(nazwa_p);}

void Blok_odczytu::przelicz()
{
    if(plik&&wyjscia.size()>0)
    {
        double odczytana_liczba;
        plik>>odczytana_liczba;

        Wartosc nowa;
        nowa.ustaw_liczbe(odczytana_liczba);
        wyjscia[0]->ustaw_wartosc(nowa);
    }
}
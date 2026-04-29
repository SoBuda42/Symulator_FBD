#include "Blok_odczytu.h"
#include "Wyjscie.h"

using namespace std;

Blok_odczytu::Blok_odczytu(string nazwa_p) 
{
    plik.open(nazwa_p);
    wyjscia.push_back(new Wyjscie());
}

Blok_odczytu::~Blok_odczytu()
{
    if(plik.is_open()) plik.close();
}

void Blok_odczytu::przelicz()
{
    if(wyjscia.size()>0)
    {
        double odczytana_liczba = 0.0;

        if(plik>>odczytana_liczba) {}
        else 
        {
            odczytana_liczba = 0.0;;
            plik.clear();
        }

        Wartosc nowa_wartosc;
        nowa_wartosc.ustaw_liczbe(odczytana_liczba);
        
        Wyjscie* gniazdo = dynamic_cast<Wyjscie*>(wyjscia[0]);
        if(gniazdo!=nullptr) {gniazdo->ustaw_wartosc(nowa_wartosc);}
    }
}

void Blok_odczytu::inicjalizuj() {}
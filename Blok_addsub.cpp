#include "Blok_addsub.h"
#include "Wejscie.h"
#include "Wyjscie.h"
#include "Wartosc.h"

Blok_addsub::Blok_addsub(std::string znaki)
{
    znaki_operacji = znaki;
    wyjscia.push_back(new Wyjscie());
}

void Blok_addsub::inicjalizuj() {}

void Blok_addsub::przelicz()
{
    if(wejscia.size()>0 && wyjscia.size()>0)
    {
        double suma = 0.0;
        for(int i=0; i<wejscia.size(); i++)
        {
            if(i<znaki_operacji.size())
            {
                double prad_z_kabla = wejscia[i]->odczytaj_wartosc().pobierz_liczbe();

                if(znaki_operacji[i] == '+') {suma += prad_z_kabla;}
                else if(znaki_operacji[i] == '-') {suma -= prad_z_kabla;}
            }
        }
        Wartosc wynik;
        wynik.ustaw_liczbe(suma);

        Wyjscie* gniazdo = dynamic_cast<Wyjscie*>(wyjscia[0]);
        if(gniazdo!=nullptr) {gniazdo->ustaw_wartosc(wynik);}
    }
}
#include <iostream>
#include "Konstruktor_FBD.h"
#include "Blok_funkcyjny.h"
#include "Polaczenie.h"
#include "Blok_stalej.h"
#include "Blok_wzmocnienia.h"
#include "Wejscie.h"
#include "Wyjscie.h"

using namespace std;

void test_wzmocnienia()
{
    Blok_funkcyjny *prad = new Blok_stalej(5.0);
    Blok_funkcyjny *wzmocnienie = new Blok_wzmocnienia(2.0);

    Wejscie *do_wzmocnienia = new Wejscie();
    Wyjscie *od_wzmocnienia = new Wyjscie();
    Wyjscie *od_stalej = new Wyjscie();

    prad->dodaj_wyjscie(od_stalej);
    wzmocnienie->dodaj_wyjscie(od_wzmocnienia);
    wzmocnienie->dodaj_wejscie(do_wzmocnienia);

    Polaczenie *kabel = new Polaczenie();
    kabel->polacz_z(prad->wez_wyjscie(0));
    kabel->polacz_do(wzmocnienie->wez_wejscie(0));
    do_wzmocnienia->polacz(kabel);

    prad->przelicz();
    wzmocnienie->przelicz();

    Wartosc out = wzmocnienie->wez_wyjscie(0)->pobierz_wartosc();
    double wynik = out.pobierz_liczbe();

    if (wynik = 10.0)
    {
        cout << "\n[OK] Test wzmocnienia: ZDANY!";
    }
    else
    {
        cout << "\n[BŁĄD] Test wzmocnienia: OBLANY! (Oczekiwano 10)";
    }
    cout << endl;

    delete prad;
    delete wzmocnienie;
    delete kabel;
}

int main()
{
    cout << "Test wzmocnienia:" << endl;
    test_wzmocnienia();

    Konstruktor_FBD konfiguracja;
    konfiguracja.konfiguruj();
    return 0;
}
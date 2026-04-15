#include <iostream>
#include "Testy.h"
#include "Kontener_FBD.h"
#include "Konstruktor_FBD.h"
#include "Podstawowy_blok_funkcyjny.h"
#include "Blok_stalej.h"
#include "Blok_wzmocnienia.h"
#include "Polaczenie.h"
#include "Wejscie.h"
#include "Wyjscie.h"

using namespace std;

void Testy::test_wzmocnienia(Kontener_FBD* kontener) 
{
    Podstawowy_blok_funkcyjny* stala = kontener->stworz_stala(5.0);
    Podstawowy_blok_funkcyjny* wzmocnienie = kontener->stworz_wzmocnienie(2.0);

    wzmocnienie->dodaj_wejscie(kontener->stworz_wejscie());

    Polaczenie* polaczenie = kontener->stworz_polaczenie();
    polaczenie->polacz_z(stala->wez_wyjscie(0));
    polaczenie->polacz_do(wzmocnienie->wez_wejscie(0));
    wzmocnienie->wez_wejscie(0)->polacz(polaczenie);

    stala->przelicz();
    wzmocnienie->przelicz();
    
    double wynik = wzmocnienie->wez_wyjscie(0)->pobierz_wartosc().pobierz_liczbe();

    if (wynik == 10.0) 
    {
        cout << "[OK] Test wzmocnienia ZALICZONY! Wynik: " << wynik << endl;
    } 
    else 
    {
        cout << "[BLAD] Test oblał! Oczekiwano 10.0, otrzymano: " << wynik << endl;
    }
}

void Testy::test_dodawania(Kontener_FBD* kontener) {}
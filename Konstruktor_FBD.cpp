#include <iostream>
#include "Konstruktor_FBD.h"
#include "Blok_funkcyjny.h"
#include "Silnik_obliczeniowy.h"
#include "Blok_stalej.h"
#include "Blok_wzmocnienia.h"
#include "Blok_odczytu.h"
#include "Blok_dodawania.h"
#include "Polaczenie.h"
#include "Wejscie.h"
#include "Wyjscie.h"

using namespace std;

void Konstruktor_FBD::konfiguruj() 
{
    Blok_funkcyjny* stala = new Blok_stalej(5.0);
    Blok_funkcyjny* wzmocnienie = new Blok_wzmocnienia(2.0);

    Wejscie* do_wzmocnienia = new Wejscie();
    Wyjscie* z_wzmocnienia = new Wyjscie();
    Wyjscie* z_stalej = new Wyjscie();

    stala->dodaj_wyjscie(z_stalej);
    wzmocnienie->dodaj_wejscie(do_wzmocnienia);
    wzmocnienie->dodaj_wyjscie(z_wzmocnienia);

    Polaczenie* polaczenie = new Polaczenie();
    polaczenie->polacz_z(stala->wez_wyjscie(0));
    polaczenie->polacz_do(wzmocnienie->wez_wejscie(0));
    do_wzmocnienia->polacz(polaczenie);

    stala->przelicz();
    wzmocnienie->przelicz();
    
    cout<<"Prad na wyjsciu wzmacniacza: ("<<z_wzmocnienia->pobierz_wartosc().pobierz_liczbe()<<")"<<endl;
}
#include <iostream>
#include "Testy.h"
#include "Kontener_FBD.h"
#include "Konstruktor_FBD.h"
#include "Blok_funkcyjny.h"
#include "Blok_stalej.h"
#include "Blok_wzmocnienia.h"
#include "Polaczenie.h"
#include "Wejscie.h"
#include "Wyjscie.h"

void Testy::test_wzmocnienia(Kontener_FBD* kontener) 
{
    Blok_funkcyjny* stala = kontener->stworz_stala(5.0);
    Blok_funkcyjny* wzmocnienie = kontener->stworz_wzmocnienie(2.0);

    Wejscie* do_wzmocnienia = kontener->stworz_wejscie();
    Wyjscie* z_wzmocnienia = kontener->stworz_wyjscie();
    Wyjscie* z_stalej = kontener->stworz_wyjscie();

    stala->dodaj_wyjscie(z_stalej);
    wzmocnienie->dodaj_wejscie(do_wzmocnienia);
    wzmocnienie->dodaj_wyjscie(z_wzmocnienia);

    Polaczenie* polaczenie = kontener->stworz_polaczenie();
    polaczenie->polacz_z(stala->wez_wyjscie(0));
    polaczenie->polacz_do(wzmocnienie->wez_wejscie(0));
    do_wzmocnienia->polacz(polaczenie);

    stala->przelicz();
    wzmocnienie->przelicz();
    
    cout<<"Prad na wyjsciu wzmacniacza: ("<<z_wzmocnienia->pobierz_wartosc().pobierz_liczbe()<<")"<<endl;
}

void Testy::test_dodawania(Kontener_FBD* kontener)
{
    Blok_funkcyjny* w1 = kontener->stworz_stala(2.0);
    Blok_funkcyjny* w2 = kontener->stworz_stala(3.0);
    Blok_funkcyjny* suma = kontener->stworz_dodawanie();

    Wyjscie* od_w1 = kontener->stworz_wyjscie();
    Wyjscie* od_w2 = kontener->stworz_wyjscie();

    Wejscie* do_sumy_1 = kontener->stworz_wejscie();
    Wejscie* do_sumy_2 = kontener->stworz_wejscie();
    Wyjscie* od_sumy = kontener->stworz_wyjscie();

    w1->dodaj_wyjscie(od_w1);
    w2->dodaj_wyjscie(od_w2);

    suma->dodaj_wejscie(do_sumy_1);
    suma->dodaj_wejscie(do_sumy_2);
    suma->dodaj_wyjscie(od_sumy);

    Polaczenie* kabel_1 = kontener->stworz_polaczenie();
    kabel_1->polacz_z(od_w1);
    kabel_1->polacz_do(do_sumy_1);
    do_sumy_1->polacz(kabel_1);

    Polaczenie* kabel_2 = kontener->stworz_polaczenie();
    kabel_2->polacz_z(od_w2);
    kabel_2->polacz_do(do_sumy_2);
    do_sumy_2->polacz(kabel_2);
    
    w1->przelicz();
    w2->przelicz();
    suma->przelicz();

    Wartosc out = suma->wez_wyjscie(0)->pobierz_wartosc();
    double wynik = out.pobierz_liczbe();

    if(wynik==5.0) {cout<<"Test zdany!"<<endl;}
    else {cout<<"Test niezdany, awaria!"<<endl;}
}
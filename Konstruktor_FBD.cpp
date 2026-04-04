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

Konstruktor_FBD::~Konstruktor_FBD() 
{
    for(int i=0; i<lista_maszyn.size(); i++)
    {
        delete lista_maszyn[i];
    }

    for(int i=0; i<lista_wejsc.size(); i++)
    {
        delete lista_wejsc[i];
    }

    for(int i=0; i<lista_wyjsc.size(); i++)
    {
        delete lista_wyjsc[i];
    }

    for(int i=0; i<lista_polaczen.size(); i++)
    {
        delete lista_polaczen[i];
    }
    lista_maszyn.clear();
}

Wejscie* Konstruktor_FBD::stworz_wejscie()
{
    Wejscie* w = new Wejscie();
    lista_wejsc.push_back(w);
    return w;
}

Wyjscie* Konstruktor_FBD::stworz_wyjscie()
{
    Wyjscie* w = new Wyjscie();
    lista_wyjsc.push_back(w);
    return w;
}

Polaczenie* Konstruktor_FBD::stworz_polaczenie()
{
    Polaczenie* w = new Polaczenie();
    lista_polaczen.push_back(w);
    return w;
}

void Konstruktor_FBD::konfiguruj() 
{
    Blok_funkcyjny* stala = new Blok_stalej(5.0);
    Blok_funkcyjny* wzmocnienie = new Blok_wzmocnienia(2.0);

    lista_maszyn.push_back(stala);
    lista_maszyn.push_back(wzmocnienie);

    Wejscie* do_wzmocnienia = stworz_wejscie();
    Wyjscie* z_wzmocnienia = stworz_wyjscie();
    Wyjscie* z_stalej = stworz_wyjscie();

    stala->dodaj_wyjscie(z_stalej);
    wzmocnienie->dodaj_wejscie(do_wzmocnienia);
    wzmocnienie->dodaj_wyjscie(z_wzmocnienia);

    Polaczenie* polaczenie = stworz_polaczenie();
    polaczenie->polacz_z(stala->wez_wyjscie(0));
    polaczenie->polacz_do(wzmocnienie->wez_wejscie(0));
    do_wzmocnienia->polacz(polaczenie);

    stala->przelicz();
    wzmocnienie->przelicz();
    
    cout<<"Prad na wyjsciu wzmacniacza: ("<<z_wzmocnienia->pobierz_wartosc().pobierz_liczbe()<<")"<<endl;
}
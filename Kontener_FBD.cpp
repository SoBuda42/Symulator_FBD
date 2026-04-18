#include "Kontener_FBD.h"
#include "Podstawowy_blok_funkcyjny.h"
#include "Blok_stalej.h"
#include "Blok_wzmocnienia.h"
#include "Blok_addsub.h"
#include "Blok_calkowania.h"
#include "Blok_mnozenia.h"
#include "Blok_dzielenia.h"
#include "Blok_zapisu.h"
#include "Blok_odczytu.h"
#include "Blok_generatora.h"
#include "Polaczenie.h"
#include "Wejscie.h"
#include "Wyjscie.h"
#include <string>

using namespace std;

Kontener_FBD::~Kontener_FBD()
{
    for(int i=0; i<lista_funkcyjna.size(); i++)
    {
        delete lista_funkcyjna[i];
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
}

Podstawowy_blok_funkcyjny* Kontener_FBD::stworz_stala(double wartosc)
{
    Podstawowy_blok_funkcyjny* nowy_blok = new Blok_stalej(wartosc);
    lista_funkcyjna.push_back(nowy_blok);
    return nowy_blok;
}

Podstawowy_blok_funkcyjny* Kontener_FBD::stworz_wzmocnienie(double wartosc)
{
    Podstawowy_blok_funkcyjny* nowy_blok = new Blok_wzmocnienia(wartosc);
    lista_funkcyjna.push_back(nowy_blok);
    return nowy_blok;
}

Podstawowy_blok_funkcyjny* Kontener_FBD::stworz_addsub(std::string znaki)
{
    Podstawowy_blok_funkcyjny* w = new Blok_addsub(znaki);
    lista_funkcyjna.push_back(w);
    return w;
}

Podstawowy_blok_funkcyjny* Kontener_FBD::stworz_calkowanie()
{
    Podstawowy_blok_funkcyjny* blok = new Blok_calkowania();
    lista_funkcyjna.push_back(blok);
    return blok;
}

Podstawowy_blok_funkcyjny* Kontener_FBD::stworz_mnozenie()
{
    Podstawowy_blok_funkcyjny* blok = new Blok_mnozenia();
    lista_funkcyjna.push_back(blok);
    return blok;
}

Podstawowy_blok_funkcyjny* Kontener_FBD::stworz_dzielenie()
{
    Podstawowy_blok_funkcyjny* blok = new Blok_dzielenia();
    lista_funkcyjna.push_back(blok);
    return blok;
}

Podstawowy_blok_funkcyjny* Kontener_FBD::stworz_zapis(std::string nazwa_pliku)
{
    Podstawowy_blok_funkcyjny* blok = new Blok_zapisu(nazwa_pliku);
    lista_funkcyjna.push_back(blok);
    return blok;
}

Podstawowy_blok_funkcyjny* Kontener_FBD::stworz_odczyt(std::string nazwa_pliku)
{
    Podstawowy_blok_funkcyjny* blok = new Blok_odczytu(nazwa_pliku);
    lista_funkcyjna.push_back(blok);
    return blok;
}

Podstawowy_blok_funkcyjny* Kontener_FBD::stworz_generator(double amp, int okr)
{
    Podstawowy_blok_funkcyjny* blok = new Blok_generatora(amp, okr);
    lista_funkcyjna.push_back(blok);
    return blok;
}

Interfejs_wejscia* Kontener_FBD::stworz_wejscie()
{
    Interfejs_wejscia* w = new Wejscie();
    lista_wejsc.push_back(w);
    return w;
}

Interfejs_wyjscia* Kontener_FBD::stworz_wyjscie()
{
    Interfejs_wyjscia* w = new Wyjscie();
    lista_wyjsc.push_back(w);
    return w;
}

Interfejs_polaczenia* Kontener_FBD::stworz_polaczenie()
{
    Interfejs_polaczenia* w = new Polaczenie();
    lista_polaczen.push_back(w);
    return w;
}
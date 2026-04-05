#include "Kontener_FBD.h"
#include "Blok_funkcyjny.h"
#include "Blok_stalej.h"
#include "Blok_wzmocnienia.h"
#include "Blok_dodawania.h"
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

Blok_funkcyjny* Kontener_FBD::stworz_stala(double wartosc)
{
    Blok_funkcyjny* nowy_blok = new Blok_stalej(wartosc);
    lista_funkcyjna.push_back(nowy_blok);
    return nowy_blok;
}

Blok_funkcyjny* Kontener_FBD::stworz_wzmocnienie(double wartosc)
{
    Blok_funkcyjny* nowy_blok = new Blok_wzmocnienia(wartosc);
    lista_funkcyjna.push_back(nowy_blok);
    return nowy_blok;
}

Blok_funkcyjny* Kontener_FBD::stworz_dodawanie()
{
    Blok_funkcyjny* w = new Blok_dodawania();
    lista_funkcyjna.push_back(w);
    return w;
}

Wejscie* Kontener_FBD::stworz_wejscie()
{
    Wejscie* w = new Wejscie();
    lista_wejsc.push_back(w);
    return w;
}

Wyjscie* Kontener_FBD::stworz_wyjscie()
{
    Wyjscie* w = new Wyjscie();
    lista_wyjsc.push_back(w);
    return w;
}

Polaczenie* Kontener_FBD::stworz_polaczenie()
{
    Polaczenie* w = new Polaczenie();
    lista_polaczen.push_back(w);
    return w;
}
#include "Podstawowy_blok_funkcyjny.h"
#include "Interfejs_wejscia.h"
#include "Interfejs_wyjscia.h"

Podstawowy_blok_funkcyjny::Podstawowy_blok_funkcyjny() {}

Podstawowy_blok_funkcyjny::~Podstawowy_blok_funkcyjny()
{
    for(int i=0; i<wejscia.size(); i++) {delete wejscia[i];}
    for(int i=0; i<wyjscia.size(); i++) {delete wyjscia[i];}
}

Interfejs_wejscia* Podstawowy_blok_funkcyjny::wez_wejscie(int ktore_wejscie) 
{
    if(ktore_wejscie>=0 && ktore_wejscie<wejscia.size()) {return wejscia[ktore_wejscie];}
    return nullptr;
}

Interfejs_wyjscia* Podstawowy_blok_funkcyjny::wez_wyjscie(int ktore_wyjscie) 
{
    if(ktore_wyjscie>=0 && ktore_wyjscie<wyjscia.size()) {return wyjscia[ktore_wyjscie];}
    return nullptr;
}

bool Podstawowy_blok_funkcyjny::czy_polaczyc_wejscie(Interfejs_polaczenia* nowy_kabel) 
{
    if (nowy_kabel==nullptr) return false;

    for(auto gniazdo : wejscia)
    {
        if(gniazdo!=nullptr)
        {
            gniazdo->polacz(nowy_kabel);
            return true;
        }
    }
    return false;
}


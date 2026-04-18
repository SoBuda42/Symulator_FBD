#include "Blok_funkcyjny.h"
#include "Wejscie.h"
#include "Wyjscie.h"

void Blok_funkcyjny::przelicz() {}

void Blok_funkcyjny::dodaj_wejscie(Interfejs_wejscia* w) {wejscia.push_back(w);}
void Blok_funkcyjny::dodaj_wyjscie(Interfejs_wyjscia* w) {wyjscia.push_back(w);}

Interfejs_wejscia* Blok_funkcyjny::wez_wejscie(int numer) 
{
    if(numer >= 0 && numer< wejscia.size()) return wejscia[numer];
    return nullptr;
}

Interfejs_wyjscia* Blok_funkcyjny::wez_wyjscie(int numer) 
{
    if(numer >= 0 && numer< wyjscia.size()) return wyjscia[numer];
    return nullptr;
}
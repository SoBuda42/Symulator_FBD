#include "Blok_funkcyjny.h"
#include "Wejscie.h"
#include "Wyjscie.h"

void Blok_funkcyjny::przelicz() {}

void Blok_funkcyjny::dodaj_wejscie(Wejscie* w) {wejscia.push_back(w);}
void Blok_funkcyjny::dodaj_wyjscie(Wyjscie* w) {wyjscia.push_back(w);}

Wejscie* Blok_funkcyjny::wez_wejscie(int numer) 
{
    if(numer >= 0 && numer< wejscia.size()) return wejscia[numer];
    return nullptr;
}

Wyjscie* Blok_funkcyjny::wez_wyjscie(int numer) 
{
    if(numer >= 0 && numer< wyjscia.size()) return wyjscia[numer];
    return nullptr;
}
#include "Wejscie.h"
#include "Polaczenie.h"

Wartosc Wejscie::odczytaj_wartosc() 
{
    if(podpiety_kabel==nullptr) {return Wartosc(0.0);}
    else {return podpiety_kabel->odczytaj_wartosc();}
}

void Wejscie::polacz(Interfejs_polaczenia* kabel) {podpiety_kabel = kabel;}
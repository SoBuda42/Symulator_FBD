#include "Wejscie.h"
#include "Polaczenie.h"

Wartosc Wejscie::odczytaj_wartosc() 
{
    if(podpiety_kabel==nullptr) {return Wartosc();}
    else {return podpiety_kabel->odczytaj_wartosc();}
}

void Wejscie::polacz(Polaczenie* kabel) {podpiety_kabel = kabel;}
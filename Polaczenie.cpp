#include "Polaczenie.h"
#include "Wejscie.h"
#include "Wyjscie.h"

void Polaczenie::polacz_z(Interfejs_wyjscia* w) {z_wyjscia = w;}
void Polaczenie::polacz_do(Interfejs_wejscia* w) {do_wejscia = w;}

Wartosc Polaczenie::odczytaj_wartosc() 
{
    if(z_wyjscia==nullptr) {return Wartosc(0.0);}
    else {return z_wyjscia->pobierz_wartosc();}
}
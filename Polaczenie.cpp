#include "Polaczenie.h"
#include "Wejscie.h"
#include "Wyjscie.h"

void Polaczenie::polacz_z(Wyjscie* w) {z_wyjscia = w;}
void Polaczenie::polacz_do(Wejscie* w) {do_wejscia = w;}

Wartosc Polaczenie::odczytaj_wartosc() 
{
    if(z_wyjscia==nullptr) {return Wartosc();}
    else {return z_wyjscia->pobierz_wartosc();}
}
#include "Silnik_obliczeniowy.h"

Silnik_obliczeniowy::Silnik_obliczeniowy() {krok_symulacji=0;}
void Silnik_obliczeniowy::dodaj_blok(Blok_funkcyjny* blok) {bloki.push_back(blok);}
void Silnik_obliczeniowy::inicjalizuj_obliczenia() {}
void Silnik_obliczeniowy::uruchom_obliczenia() {}
void Silnik_obliczeniowy::wstrzymaj_obliczenia() {}
void Silnik_obliczeniowy::wykonaj_obliczenia_wsadowe() {}
void Silnik_obliczeniowy::zatrzymaj_obliczenia() {}
void Silnik_obliczeniowy::wykonaj_krok_symulacji() 
{
    for(int i=0; i<bloki.size(); i++)
    {
        bloki[i]->przelicz();
    }
    krok_symulacji++;
}
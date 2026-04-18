#include "Silnik_obliczeniowy.h"

Silnik_obliczeniowy::Silnik_obliczeniowy() 
{ 
    krok_symulacji = 0; 
    koniec = 10;
    status = wstrzymana;
}

void Silnik_obliczeniowy::dodaj_blok(Podstawowy_blok_funkcyjny *blok) { bloki.push_back(blok); }

void Silnik_obliczeniowy::inicjalizuj_obliczenia()
{
    krok_symulacji = 0;
    status = wstrzymana;

    for (int i = 0; i < bloki.size(); i++)
    {
        bloki[i]->inicjalizuj();
    }
}

void Silnik_obliczeniowy::uruchom_obliczenia() {status = uruchomiona;}

void Silnik_obliczeniowy::wstrzymaj_obliczenia() {status = wstrzymana;}

void Silnik_obliczeniowy::wykonaj_obliczenia_wsadowe() 
{
    inicjalizuj_obliczenia();
    uruchom_obliczenia();

    while(status == uruchomiona) {wykonaj_krok_symulacji();}
}

void Silnik_obliczeniowy::zatrzymaj_obliczenia()
{
    status = wstrzymana;
    krok_symulacji = 0;
}

void Silnik_obliczeniowy::wykonaj_krok_symulacji()
{
    if (status == uruchomiona && krok_symulacji < koniec)
    {
        for (int i = 0; i < bloki.size(); i++)
        {
            bloki[i]->przelicz();
        }
        krok_symulacji++;

        if(krok_symulacji >= koniec) {zatrzymaj_obliczenia();}
    }
}
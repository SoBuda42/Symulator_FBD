#ifndef SILNIK_OBLICZENIOWY_H
#define SILNIK_OBLICZENIOWY_H

#include "Definicje.h"

class Silnik_obliczeniowy
{
    private:
        long krok_symulacji;
        Status_symulacji status;
        long koniec;
    public:
        void inicjalizuj_obliczenia();
        void uruchom_obliczenia();
        void wstrzymaj_obliczenia();
        void wykonaj_obliczenia_wsadowe();
        void zatrzymaj_obliczenia();
        void wykonaj_krok_symulacji();
};

#endif
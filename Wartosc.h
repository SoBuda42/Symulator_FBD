#ifndef WARTOSC_H
#define WARTOSC_H

#include "Definicje.h"
#include "Stempel_czasowy.h"

/**
 * @brief Klasa reprezentujaca pojedyncza wartosc sygnalu (pradu) w symulatorze.
 * Przechowuje rzeczywista wartosc liczbowa przekazywana miedzy blokami oraz na kablach.
 */
class Wartosc 
{
    private:
        double wartosc = 0.0;
        Status_wartosci status;
        Stempel_czasowy stempel_czasowy;
    public:
        /**
         * @brief Konstruktor domyslny. Zeruje wartosc na starcie.
         */
        Wartosc();

        /**
         * @brief Konstruktor ustawiajacy od razu konkretna liczbe.
         */
        Wartosc(double startowa_wartosc);
        
        /**
         * @brief Pobiera aktualnie zapisana liczbe.
         * @return Zwraca wartosc liczbowa typu double.
         */
        double pobierz_liczbe();

        /**
         * @brief Ustawia nowa liczbe w obiekcie.
         * @param nowa_liczba Wartosc typu double do zapisania w obiekcie.
         */
        void ustaw_liczbe(double nowa_liczba);
};

#endif
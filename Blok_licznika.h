#ifndef BLOK_LICZNIKA_H
#define BLOK_LICZNIKA_H

#include "Wlasciwy_blok_przetwarzania.h"

/**
 * @brief Maszyna pelniaca role akumulatora/licznika z nasyceniem.
 * * Dodaje wartosci z wejscia do wewnetrznej pamieci (licznika). 
 * Posiada wbudowany bezpiecznik - nie pozwala, aby zsumowana wartosc 
 * przekroczyla zadeklarowany limit.
 */
class Blok_licznika : public Wlasciwy_blok_przetwarzania
{
    private:
        double limit;
        double stan_licznika;
    public:
        /**
         * @brief Konstruktor ustawiajacy gorna granice liczenia.
         * @param lim Wartosc limitu (nasycenia).
         */
        Blok_licznika(double lim);

        /**
         * @brief Pobiera sygnal z wejscia i dodaje go do licznika. 
         * Jesli wynik przekroczy limit, licznik jest blokowany na wartosci limitu.
         * Nastepnie aktualny stan licznika jest wysylany na wyjscie.
         */
        void przelicz() override; 

        /**
         * @brief Resetuje licznik (pamiec wewnetrzna) do zera.
         * Wymagane przed rozpoczeciem nowej symulacji.
         */
        void inicjalizuj() override;      
};

#endif
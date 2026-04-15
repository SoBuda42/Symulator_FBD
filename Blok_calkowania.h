#ifndef BLOK_CALKOWANIA_H
#define BLOK_CALKOWANIA_H

#include "Wlasciwy_blok_przetwarzania.h"

/**
 * @brief Maszyna realizujaca numeryczne calkowanie sygnalu wejsciowego.
 * * Klasa dziedziczaca po kategorii Wlasciwy_blok_przetwarzania. Dziala jak 
 * matematyczny akumulator - w kazdym kroku symulacji pobiera biezaca wartosc 
 * z wejscia i dodaje ja do swojej wewnetrznej, zapamietanej sumy, a nastepnie 
 * wysyla ten zaktualizowany wynik na wyjscie.
 */
class Blok_calkowania : public Wlasciwy_blok_przetwarzania
{
    private:
        double suma_calkowita;
    public:
        /**
         * @brief Konstruktor zerujacy pamiec maszyny i montujacy gniazdo wyjsciowe.
         */
        Blok_calkowania();

        /**
         * @brief Funkcja przygotowujaca maszyne do pracy (obecnie pusta).
         */
        void inicjalizuj() override;

        /**
         * @brief Funkcja robocza maszyny. Odczytuje wejscie, aktualizuje sume calkowita
         * i bezpiecznie wstrzykuje nowy wynik do gniazda wyjsciowego.
         */
        void przelicz() override;
};

#endif
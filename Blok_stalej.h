#ifndef BLOK_STALEJ_H
#define BLOK_STALEJ_H

#include "Generator_sygnalu.h"

/**
 * @brief Maszyna pelniaca role zasilacza (zrodla sygnalu).
 * Generuje zadeklarowana, stala wartosc pradu na swoim wyjsciu.
 */
class Blok_stalej : public Generator_sygnalu
{
    private:
        double ukryta_wartosc = 0;
    public:
        /**
         * @brief Konstruktor ustawiajacy poczatkowa wartosc zasilacza.
         * @param wartosc Liczba, ktora zasilacz bedzie podawal na wyjscie.
         */
        Blok_stalej(double wartosc);

        /**
         * @brief Wysyla zapisana stala wartosc bezposrednio do swojego gniazda wyjsciowego.
         */
        void przelicz() override;

        /**
         * @brief Funkcja przygotowujaca maszyne do pracy (obecnie pusta).
         */
        void inicjalizuj() override;
};

#endif
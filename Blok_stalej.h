#ifndef BLOK_STALEJ_H
#define BLOK_STALEJ_H

#include "Blok_funkcyjny.h"

/**
 * @brief Maszyna pelniaca role zasilacza (zrodla sygnalu).
 * Generuje zadeklarowana, stala wartosc pradu na swoim wyjsciu.
 */
class Blok_stalej : public Blok_funkcyjny
{
    private:
        double ukryta_wartosc;
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
};

#endif
#ifndef WYJSCIE_H
#define WYJSCIE_H

#include "Wartosc.h"

/**
 * @brief Gniazdo wyjsciowe bloku funkcyjnego.
 * Przechowuje wygenerowana wartosc sygnalu i pozwala innym elementom (kablom) na jej odczyt.
 */
class Wyjscie
{
    private:
        int numer;
        Wartosc wartosc;
    public:
        /**
         * @brief Odczytuje wartosc aktualnie znajdujaca sie na wyjsciu.
         * @return Obiekt Wartosc zawierajacy liczbe.
         */
        Wartosc pobierz_wartosc();

        /**
         * @brief Ustawia nowa wartosc na wyjsciu bloku.
         * @param nowa Nowa liczba (obiekt Wartosc), ktora ma sie pojawic na wyjsciu.
         */
        void ustaw_wartosc(Wartosc nowa);
};

#endif
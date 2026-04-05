#ifndef WYJSCIE_H
#define WYJSCIE_H

#include "Interfejs_wyjscia.h"
#include "Wartosc.h"

/**
 * @brief Gniazdo wyjsciowe bloku funkcyjnego.
 * Przechowuje wygenerowana wartosc sygnalu i pozwala innym elementom (kablom) na jej odczyt.
 */
class Wyjscie : public Interfejs_wyjscia
{
    private:
        int numer;
        Wartosc wartosc;
    public:
        /**
        * @brief Kostruktor przypisujacy do wyjscia 0, gdy urzytkownik zapomni podac numeru wyjscia
        */
        Wyjscie(int nr=0) : numer(nr) {}
        
        /**
         * @brief Odczytuje wartosc aktualnie znajdujaca sie na wyjsciu.
         * @return Obiekt Wartosc zawierajacy liczbe.
         */
        Wartosc pobierz_wartosc() override;

        /**
         * @brief Ustawia nowa wartosc na wyjsciu bloku.
         * @param nowa Nowa liczba (obiekt Wartosc), ktora ma sie pojawic na wyjsciu.
         */
        void ustaw_wartosc(Wartosc nowa);
};

#endif
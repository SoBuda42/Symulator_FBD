#ifndef INTERFEJS_POLACZENIA_H
#define INTERFEJS_POLACZENIA_H

#include "Wartosc.h"

class Interfejs_wyjscia;
class Interfejs_wejscia;


/**
 * @brief Interfejs (porzadkujacy) reprezentujacy dzialanie polaczen.
 * * Odpowiada za transfer sygnalu pomiedzy gniazdem wyjsciowym a wejsciowym.
 */
class Interfejs_polaczenia
{
    public:
        /** @brief Wirtualny destruktor interfejsu polaczenia. */
        virtual ~Interfejs_polaczenia() {}

        /**
         * @brief Podlacza zrodlo sygnalu (początek kabla).
         * * @param z_wyjscia Wskaznik na interfejs gniazda wyjsciowego (nadajacego).
         */
        virtual void polacz_z(Interfejs_wyjscia* z_wyjscia)=0;

        /**
         * @brief Podlacza cel sygnalu (koniec kabla).
         * * @param do_wejscia Wskaznik na interfejs gniazda wejsciowego (odbierajacego).
         */
        virtual void polacz_do(Interfejs_wejscia* do_wejscia)=0;

        /**
         * @brief Przesyla sygnal miedzy koncowkami kabla.
         * * @return Obiekt Wartosc pobrany z podpietego wyjscia.
         */
        virtual Wartosc odczytaj_wartosc()=0;
};

#endif
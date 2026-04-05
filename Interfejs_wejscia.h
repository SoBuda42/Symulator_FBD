#ifndef INTERFEJS_WEJSCIA_H
#define INTERFEJS_WEJSCIA_H

#include "Wartosc.h"

class Interfejs_polaczenia;

/**
 * @brief Interfejs do wejsc bloku funkcyjnego.
 * * Definiuje kontrakt dla gniazd, ktore przyjmuja sygnal z kabla i wprowadzaja go do maszyny.
 */
class Interfejs_wejscia
{
    public:
        /** @brief Wirtualny destruktor interfejsu wejscia. */
        virtual ~Interfejs_wejscia() {}

        /**
         * @brief Odczytuje wartosc sygnału wchodzacego do gniazda.
         * * @return Obiekt Wartosc pobrany z podlaczonego kabla.
         */
        virtual Wartosc odczytaj_wartosc()=0;

        /**
         * @brief Fizycznie wtyka wtyczke kabla do tego gniazda.
         * * @param kabel Wskaznik na interfejs polaczenia, z ktorego bedzie ciagniety prad.
         */
        virtual void polacz(Interfejs_polaczenia* kabel)=0;
};

#endif
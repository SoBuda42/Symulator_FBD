#ifndef INTERFEJS_WYJSCIA_H
#define INTERFEJS_WYJSCIA_H

#include "Wartosc.h"

/**
 * @brief Interfejs dla gniazd wyjsciowych (nadajnikow) w schemacie FBD.
 * * Klasa wylacznie abstrakcyjna. Definiuje kontrakt, ktory musi spelnic 
 * kazda klasa pelniaca role wyjscia sygnalu z bloku.
 */
class Interfejs_wyjscia
{
    public:
        /**
         * @brief Wirtualny destruktor.
         * * Gwarantuje poprawne niszczenie (zwalnianie pamieci) obiektow klas pochodnych,
         * gdy sa one usuwane przez wskaznik na interfejs bazowy.
         */
        virtual ~Interfejs_wyjscia() {}

        /**
         * @brief Pobiera aktualna wartosc z wyjscia.
         * * Jest to czysta funkcja wirtualna (= 0). Kazda klasa dziedziczaca 
         * po tym interfejsie MUSI zaimplementowac wlasna wersje tej funkcji.
         * * @return Obiekt typu Wartosc reprezentujacy aktualny sygnal na wyjsciu.
         */
        virtual Wartosc pobierz_wartosc()=0;    
};

#endif
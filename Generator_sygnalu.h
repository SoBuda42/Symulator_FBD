#ifndef GENERATOR_SYGNALU_H
#define GENERATOR_SYGNALU_H

#include "Podstawowy_blok_funkcyjny.h"

/**
 * @brief Kategoria maszyn pelniacych role zrodel pradu (Nadajnikow).
 * * Klasa posrednia dziedziczaca po uniwersalnym kadlubie. Jej jedynym zadaniem jest
 * narzucenie stalej tozsamosci wszystkim maszynom z niej dziedziczacym (np. Blok_stalej).
 * Definiuje, ze kazdy generator jest zawsze nadajnikiem i nigdy odbiornikiem.
 */
class Generator_sygnalu : public Podstawowy_blok_funkcyjny
{
    public:
        /**
         * @brief Okresla tozsamosc maszyny jako nadajnika.
         * @return Zawsze zwraca true (wszystkie generatory sa zrodlami sygnalu).
         */
        bool czy_to_nadajnik() override;    
        
        /**
         * @brief Okresla tozsamosc maszyny jako odbiornika.
         * @return Zawsze zwraca false (generatory nie pochlaniaja sygnalu z zewnatrz).
         */
        bool czy_to_odbiornik() override;
};

#endif
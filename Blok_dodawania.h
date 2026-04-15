#ifndef BLOK_DODAWANIA_H
#define BLOK_DODAWANIA_H

#include "Wlasciwy_blok_przetwarzania.h"

/**
 * @brief Maszyna pelniaca role sumatora sygnalow.
 * Pobiera wartosci z dwoch podpietych wejsc, dodaje je do siebie i podaje wynik na wyjscie.
 */
class Blok_dodawania : public Wlasciwy_blok_przetwarzania
{
    public:
        /**
         * @brief Pobiera wartosci z wejscia nr 1 oraz nr 2, sumuje je i wyrzuca na wyjscie.
         */
        void przelicz() override;    
        
        void inicjalizuj() override;
};

#endif
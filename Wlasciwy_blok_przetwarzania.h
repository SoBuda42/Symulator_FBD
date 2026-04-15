#ifndef WLASCIWY_BLOK_PRZETWARZANIA_H
#define WLASCIWY_BLOK_PRZETWARZANIA_H

#include "Podstawowy_blok_funkcyjny.h"

class Wlasciwy_blok_przetwarzania : public Podstawowy_blok_funkcyjny
{
    public:
        bool czy_to_nadajnik() override;
        bool czy_to_odbiornik() override;       
};

#endif
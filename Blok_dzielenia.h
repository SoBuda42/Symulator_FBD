#ifndef BLOK_DZIELENIA_H
#define BLOK_DZIELENIA_H

#include "Wlasciwy_blok_przetwarzania.h"

class Blok_dzielenia : public Wlasciwy_blok_przetwarzania
{
    public:
        Blok_dzielenia();
        void przelicz() override;       
        void inicjalizuj() override;
};

#endif
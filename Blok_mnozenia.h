#ifndef BLOK_MNOZENIA_H
#define BLOK_MNOZENIA_H

#include "Wlasciwy_blok_przetwarzania.h"

class Blok_mnozenia : public Wlasciwy_blok_przetwarzania
{
    public:
        Blok_mnozenia();
        void przelicz() override;       
        void inicjalizuj() override;
};

#endif
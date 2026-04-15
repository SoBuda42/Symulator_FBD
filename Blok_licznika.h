#ifndef BLOK_LICZNIKA_H
#define BLOK_LICZNIKA_H

#include "Wlasciwy_blok_przetwarzania.h"

class Blok_licznika : public Wlasciwy_blok_przetwarzania
{
    private:
        double stan_licznika;
    public:
        Blok_licznika();
        void przelicz() override; 
        void inicjalizuj() override;      
};

#endif
#ifndef BLOK_LICZNIKA_H
#define BLOK_LICZNIKA_H

#include "Blok_funkcyjny.h"

class Blok_licznika : public Blok_funkcyjny
{
    private:
        double stan_licznika;
    public:
        Blok_licznika();
        void przelicz() override;        
};

#endif
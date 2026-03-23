#ifndef BLOK_STALEJ_H
#define BLOK_STALEJ_H

#include "Blok_funkcyjny.h"

class Blok_stalej : public Blok_funkcyjny
{
    private:
        double ukryta_wartosc;
    public:
        Blok_stalej(double wartosc);

        void przelicz() override;
};

#endif
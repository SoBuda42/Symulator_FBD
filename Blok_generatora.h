#ifndef BLOK_GENERATORA_H
#define BLOK_GENERATORA_H

#include "Wyjscie.h"
#include "Blok_funkcyjny.h"

class Blok_generatora : public Blok_funkcyjny
{
    private:
        double amplituda;
        int okres;
        int licznik_krokow;
    public:
        Blok_generatora(double amp, int okr);
        void przelicz() override;
};

#endif      
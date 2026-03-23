#ifndef BLOK_WZMOCNIENIA_H
#define BLOK_WZMOCNIENIA_H

#include "Blok_funkcyjny.h"

class Blok_wzmocnienia : public Blok_funkcyjny
{
    private:
        double wspolczynnik;
    public:
    Blok_wzmocnienia(double w);
    
    void przelicz() override;
};

#endif
#ifndef BLOK_ZAPISU_H
#define BLOK_ZAPISU_H

#include <string>
#include "Blok_funkcyjny.h"

class Blok_zapisu : public Blok_funkcyjny
{
    private:
        string nazwa_pliku;
    public:
        Blok_zapisu(string nazwa_p);
        
        void przelicz() override;
};

#endif
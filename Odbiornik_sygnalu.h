#ifndef ODBIORNIK_SYGNALU_H
#define ODBIORNIK_SYGNALU_H

#include "Podstawowy_blok_funkcyjny.h"

class Odbiornik_sygnalu : public Podstawowy_blok_funkcyjny
{
    public:
        bool czy_to_nadajnik() override;
        bool czy_to_odbiornik() override;    
};

#endif
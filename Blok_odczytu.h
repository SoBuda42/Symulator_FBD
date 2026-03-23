#ifndef BLOK_ODCZYTU_H
#define BLOK_ODCZYTU_H

#include <string>
#include <fstream>
#include "Blok_funkcyjny.h"

class Blok_odczytu : public Blok_funkcyjny
{
    private:
        string nazwa_pliku;
        ifstream plik;
    public:
        Blok_odczytu(string nazwa_p);        

        void przelicz() override;
};

#endif
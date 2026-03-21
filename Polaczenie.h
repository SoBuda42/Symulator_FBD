#ifndef POLACZENIE_H
#define POLACZENIE_H

#include "Wartosc.h"
class Wyjscie;
class Wejscie;

class Polaczenie 
{
private:
    Wyjscie* z_wyjscia; 
    Wejscie* do_wejscia;
public:
    void polacz_z(Wyjscie* w);
    void polacz_do(Wejscie* w);
    Wartosc odczytaj_wartosc();
};

#endif
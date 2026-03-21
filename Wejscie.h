#ifndef WEJSCIE_H
#define WEJSCIE_H
#include "Wartosc.h"

class Polaczenie;

class Wejscie
{
private:
    int numer;
public:
    Wartosc odczytaj_wartosc(); 
    void polacz(Polaczenie* kabel); 
};

#endif
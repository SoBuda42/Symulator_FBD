#ifndef WEJSCIE_H
#define WEJSCIE_H
#include "Wartosc.h"

class Polaczenie;

/**
 * @brief INPUT blokow
 */
class Wejscie
{
private:
    int numer;
    Polaczenie* podpiety_kabel = nullptr;
public:

    /**
    * @brief funkcja podaje wartosc
    * @return Zwraca obiekt Wartosc
    */
    Wartosc odczytaj_wartosc(); 

    /**
    * @brief funkcja podlacza fizycznie kabel
    * @param kabel Wskaznik na kabel, ktory chcemy wpiac w gniazdo
    */
    void polacz(Polaczenie* kabel); 
};

#endif
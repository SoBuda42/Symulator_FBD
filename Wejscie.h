#ifndef WEJSCIE_H
#define WEJSCIE_H
#include "Wartosc.h"

#include "Interfejs_wejscia.h"
class Interfejs_polaczenia;

/**
 * @brief INPUT blokow
 */
class Wejscie : public Interfejs_wejscia
{
private:
    int numer;
    Interfejs_polaczenia* podpiety_kabel = nullptr;
public:
    /**
    * @brief Konstruktor przypisujacy wartosc 0 do wejscia gdy urzytkownik nie poda numeru wejscia
    */
    Wejscie(int nr=0) : numer(nr) {}

    /**
    * @brief funkcja podaje wartosc
    * @return Zwraca obiekt Wartosc
    */
    Wartosc odczytaj_wartosc() override; 

    /**
    * @brief funkcja podlacza fizycznie kabel
    * @param kabel Wskaznik na kabel, ktory chcemy wpiac w gniazdo
    */
    void polacz(Interfejs_polaczenia* kabel) override; 
};

#endif
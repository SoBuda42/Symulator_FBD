#ifndef POLACZENIE_H
#define POLACZENIE_H

#include "Wartosc.h"
class Wyjscie;
class Wejscie;

/**
 * @brief Przewod laczacy gniazdo wyjsciowe jednego bloku z gniazdem wejsciowym drugiego.
 * Odpowiada za transfer sygnalu (pradu) pomiedzy maszynami.
 */
class Polaczenie 
{
private:
    Wyjscie* z_wyjscia; 
    Wejscie* do_wejscia;
public:
    /**
     * @brief Podlacza jeden koniec kabla do konkretnego gniazda wyjsciowego.
     * @param w Wskaznik na gniazdo wyjsciowe maszyny nadajacej.
     */
    void polacz_z(Wyjscie* w);

    /**
     * @brief Podlacza drugi koniec kabla do konkretnego gniazda wejsciowego.
     * @param w Wskaznik na gniazdo wejsciowe maszyny odbierajacej.
     */
    void polacz_do(Wejscie* w);

    /**
     * @brief Pobiera sygnal z podpietego gniazda wyjsciowego i przesyla go kablem.
     * @return Odczytana wartosc sygnalu.
     */
    Wartosc odczytaj_wartosc();
};

#endif
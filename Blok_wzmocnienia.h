#ifndef BLOK_WZMOCNIENIA_H
#define BLOK_WZMOCNIENIA_H

#include "Wlasciwy_blok_przetwarzania.h"

/**
 * @brief Maszyna pelniaca role mnoznika sygnalu.
 * Pobiera prad z wejscia, mnozy przez ustalony wspolczynnik i wysyla na wyjscie.
 */
class Blok_wzmocnienia : public Wlasciwy_blok_przetwarzania
{
    private:
        double wspolczynnik = 0;
    public:
    /**
     * @brief Konstruktor ustawiajacy sile wzmocnienia.
     * @param w Mnoznik, przez ktory potegowany bedzie sygnal.
     */
    Blok_wzmocnienia(double w);
    
    /**
     * @brief Pobiera wartosc z wejscia, dokonuje mnozenia i ustawia wynik na wyjsciu.
     */
    void przelicz() override;

    void inicjalizuj() override;
};

#endif
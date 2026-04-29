#ifndef POLACZENIE_H
#define POLACZENIE_H

#include "Wartosc.h"
#include "Interfejs_polaczenia.h"
class Interfejs_wyjscie;
class Interfejs_wejscia;

/**
 * @brief Przewod laczacy gniazdo wyjsciowe jednego bloku z gniazdem wejsciowym drugiego.
 * Odpowiada za transfer sygnalu (pradu) pomiedzy maszynami.
 */
class Polaczenie : public Interfejs_polaczenia
{
private:
    Interfejs_wyjscia* z_wyjscia = nullptr; 
    Interfejs_wejscia* do_wejscia = nullptr;
public:
    /**
    * @brief Poczatkowo przypisuje do kabla wartosc 0 bo kabel nie jest do niczego podlaczony
    */
    Polaczenie() : z_wyjscia(nullptr), do_wejscia(nullptr) {}

    /**
     * @brief Podlacza jeden koniec kabla do konkretnego gniazda wyjsciowego.
     * @param w Wskaznik na gniazdo wyjsciowe maszyny nadajacej.
     */
    void polacz_z(Interfejs_wyjscia* w) override;

    /**
     * @brief Podlacza drugi koniec kabla do konkretnego gniazda wejsciowego.
     * @param w Wskaznik na gniazdo wejsciowe maszyny odbierajacej.
     */
    void polacz_do(Interfejs_wejscia* w) override;

    /**
     * @brief Pobiera sygnal z podpietego gniazda wyjsciowego i przesyla go kablem.
     * @return Odczytana wartosc sygnalu.
     */
    Wartosc odczytaj_wartosc() override;
};

#endif
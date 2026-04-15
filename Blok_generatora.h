#ifndef BLOK_GENERATORA_H
#define BLOK_GENERATORA_H

#include "Wyjscie.h"
#include "Generator_sygnalu.h"

/**
 * @brief Maszyna produkujaca sygnal periodyczny (Nadajnik).
 * * Klasa dziedziczaca po kategorii Generator_sygnalu. Odpowiada za generowanie 
 * sygnalu zmiennego w czasie (np. prostokatnego). Naprzemiennie wysyla 
 * ustalona amplitude oraz wartosc 0.0, bazujac na liczniku krokow i podanym okresie.
 */
class Blok_generatora : public Generator_sygnalu
{
    private:
        double amplituda;
        int okres;
        int licznik_krokow;
    public:
        /**
         * @brief Konstruktor kalibrujacy parametry fali i montujacy gniazdo.
         * @param amp Maksymalna wartosc (amplituda) generowanego sygnalu.
         * @param okr Okres sygnalu (co ile krokow symulacji nastepuje pelen cykl).
         */
        Blok_generatora(double amp, int okr);

        /**
         * @brief Funkcja robocza maszyny. Oblicza biezacy stan fali na podstawie 
         * licznika krokow i wstrzykuje wynik na gniazdo wyjsciowe.
         */
        void przelicz() override;

        /**
         * @brief Funkcja przygotowujaca maszyne do pracy (obecnie pusta).
         */
        void inicjalizuj() override;
};

#endif      
#ifndef BLOK_ADDSUB_H
#define BLOK_ADDSUB_H

#include <string>
#include "Wlasciwy_blok_przetwarzania.h"

/**
 * @brief Uniwersalna maszyna sumujaco-odejmujaca (kombajn matematyczny).
 * * Klasa dziedziczaca po kategorii Wlasciwy_blok_przetwarzania. Jej zachowanie 
 * jest programowalne - na podstawie przekazanego w konstruktorze ciagu znakow 
 * (np. "+-+") maszyna wie, czy prad z konkretnego kabla wejsciowego ma zostac 
 * dodany do ogolnego wyniku, czy od niego odjety.
 */
class Blok_addsub : public Wlasciwy_blok_przetwarzania
{
    private:
        std::string znaki_operacji;
    public:
        /**
         * @brief Konstruktor kalibrujacy dzialanie wejsc i montujacy gniazdo.
         * @param znaki Ciag znakow (tylko '+' lub '-') definiujacy matematyczna 
         * operacje dla kazdego kolejnego wpietego kabla wejsciowego.
         */
        Blok_addsub(std::string znaki);

        /**
         * @brief Funkcja przygotowujaca maszyne do pracy (obecnie pusta).
         */
        void inicjalizuj() override;

        /**
         * @brief Funkcja robocza maszyny. Przechodzi po kolei przez wszystkie 
         * wejscia, odczytuje ich wartosci i modyfikuje wynik zgodnie z instrukcja znakowa.
         */
        void przelicz() override;        
};

#endif
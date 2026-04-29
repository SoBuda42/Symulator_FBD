#ifndef BLOK_ODCZYTU_H
#define BLOK_ODCZYTU_H

#include <string>
#include <fstream>
#include "Generator_sygnalu.h"

/**
 * @brief Maszyna pobierajaca dane z zewnetrznego pliku tekstowego (Nadajnik).
 * * Klasa dziedziczaca po kategorii Generator_sygnalu. Dziala jak tlumacz - w kazdym 
 * kroku symulacji czyta kolejna wartosc z otwartego pliku .txt/.csv i wprowadza 
 * ja do ukladu symulacyjnego jako wygenerowany prad.
 */
class Blok_odczytu : public Generator_sygnalu
{
    private:
        std::string nazwa_pliku;
        std::ifstream plik;
    public:
        /**
         * @brief Konstruktor otwierajacy plik z danymi i montujacy gniazdo wyjsciowe.
         * @param nazwa_p Dokladna sciezka lub nazwa pliku (np. "dane.txt"), z ktorego 
         * maszyna bedzie czerpac wartosci.
         */
        Blok_odczytu(std::string nazwa_p);     
        
        ~Blok_odczytu();

        /**
         * @brief Funkcja robocza maszyny. Odczytuje kolejna liczbe z pliku 
         * i podaje ja na zlacze wyjsciowe. Bezpiecznie ignoruje operacje, gdy plik sie skonczy.
         */
        void przelicz() override;

        /**
         * @brief Funkcja przygotowujaca maszyne do pracy (obecnie pusta).
         */
        void inicjalizuj() override;
};

#endif
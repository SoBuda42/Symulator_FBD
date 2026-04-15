#ifndef BLOK_ZAPISU_H
#define BLOK_ZAPISU_H

#include <string>
#include <fstream>
#include "Odbiornik_sygnalu.h"

/**
 * @brief Maszyna zrzucajaca dane symulacji na twardy dysk (Odbiornik).
 * * Klasa dziedziczaca po kategorii Odbiornik_sygnalu. Stoi na samym koncu 
 * ukladu. W kazdym kroku symulacji pobiera wartosc ze swojego kabla wejsciowego 
 * i zapisuje ja w kolejnej linijce podanego pliku .csv lub .txt.
 */
class Blok_zapisu : public Odbiornik_sygnalu
{
    private:
        std::string nazwa_pliku;
        std::ofstream plik;
    public:
        /**
         * @brief Konstruktor otwierajacy docelowy plik na dysku.
         * @param nazwa_p Dokladna sciezka lub nazwa pliku (np. "wyniki.csv"), 
         * do ktorego wpychane beda dane.
         */
        Blok_zapisu(std::string nazwa_p);

        /**
         * @brief Destruktor. Gwarantuje, ze plik zostanie zamkniety i zapisany 
         * po zakonczeniu dzialania programu.
         */
        ~Blok_zapisu();

        /**
         * @brief Funkcja przygotowujaca maszyne do pracy (obecnie pusta).
         */
        void inicjalizuj() override;
        
        /**
         * @brief Funkcja robocza maszyny. Odczytuje prad z wejscia i dopisuje 
         * go jako nowa linie do otwartego pliku tekstowego.
         */
        void przelicz() override;
};

#endif
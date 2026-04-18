#ifndef BLOK_FUNKCYJNY_H
#define BLOK_FUNKCYJNY_H

#include <vector>

using namespace std;

class Interfejs_wejscia;
class Interfejs_wyjscia;

/**
 * @brief Abstrakcyjna klasa bazowa dla wszystkich maszyn w symulatorze.
 * Definiuje wspolny interfejs (polimorfizm) dla blokow liczących, dodawania, stalych itd.
 */
class Blok_funkcyjny
{
    protected:
        vector<Interfejs_wejscia*> wejscia;
        vector<Interfejs_wyjscia*> wyjscia;
    public:
        /**
         * @brief Glowna funkcja obliczeniowa maszyny. 
         * Wymusza na blokach dziedziczacych implementacje wlasnej logiki przeliczania sygnalow.
         */
        virtual void przelicz();

        /**
         * @brief Podlacza nowe gniazdo wejsciowe do obudowy bloku.
         * @param w Wskaznik na gotowe gniazdo wejsciowe.
         */
        void dodaj_wejscie(Interfejs_wejscia* w);

        /**
         * @brief Podlacza nowe gniazdo wyjsciowe do obudowy bloku.
         * @param w Wskaznik na gotowe gniazdo wyjsciowe.
         */
        void dodaj_wyjscie(Interfejs_wyjscia* w);
        
        /**
         * @brief Zwraca wskaznik do konkretnego gniazda wejsciowego maszyny.
         * @param numer Numer gniazda (najczesciej 0).
         * @return Wskaznik na zadane gniazdo wejsciowe.
         */
        Interfejs_wejscia* wez_wejscie(int numer);

        /**
         * @brief Zwraca wskaznik do konkretnego gniazda wyjsciowego maszyny.
         * @param numer Numer gniazda (najczesciej 0).
         * @return Wskaznik na zadane gniazdo wyjsciowe.
         */
        Interfejs_wyjscia* wez_wyjscie(int numer);
};

#endif
#ifndef BLOK_FUNKCYJNY_H
#define BLOK_FUNKCYJNY_H

#include <vector>

using namespace std;

class Wejscie;
class Wyjscie;

/**
 * @brief Abstrakcyjna klasa bazowa dla wszystkich maszyn w symulatorze.
 * Definiuje wspolny interfejs (polimorfizm) dla blokow liczących, dodawania, stalych itd.
 */
class Blok_funkcyjny
{
    protected:
        vector<Wejscie*> wejscia;
        vector<Wyjscie*> wyjscia;
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
        void dodaj_wejscie(Wejscie* w);

        /**
         * @brief Podlacza nowe gniazdo wyjsciowe do obudowy bloku.
         * @param w Wskaznik na gotowe gniazdo wyjsciowe.
         */
        void dodaj_wyjscie(Wyjscie* w);
        
        /**
         * @brief Zwraca wskaznik do konkretnego gniazda wejsciowego maszyny.
         * @param numer Numer gniazda (najczesciej 0).
         * @return Wskaznik na zadane gniazdo wejsciowe.
         */
        Wejscie* wez_wejscie(int numer);

        /**
         * @brief Zwraca wskaznik do konkretnego gniazda wyjsciowego maszyny.
         * @param numer Numer gniazda (najczesciej 0).
         * @return Wskaznik na zadane gniazdo wyjsciowe.
         */
        Wyjscie* wez_wyjscie(int numer);
};

#endif
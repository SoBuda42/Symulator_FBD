#ifndef PODSTAWOWY_BLOK_FUNKCYJNY_H
#define PODSTAWOWY_BLOK_FUNKCYJNY_H

#include "Interfejs_bloku_funkcyjnego.h"
#include <vector>

class Interfejs_wejscia;
class Interfejs_wyjscia;
class Interfejs_polaczenia;

/**
 * @brief Uniwersalny kadlub maszyny (Klasa bazowa dla blokow funkcyjnych).
 * * Zarzadza wbudowanymi gniazdami wejsciowymi i wyjsciowymi. Posiada gotowa infrastrukture
 * do podpinania kabli, ktora bedzie dziedziczona przez konkretne maszyny liczace.
 */
class Podstawowy_blok_funkcyjny : public Interfejs_bloku_funkcyjnego   
{
    protected:
        /** @brief Magazyn przechowujacy wskazniki na wbudowane gniazda wejsciowe maszyny. */
        std::vector<Interfejs_wejscia*> wejscia;

        /** @brief Magazyn przechowujacy wskazniki na wbudowane gniazda wyjsciowe maszyny. */
        std::vector<Interfejs_wyjscia*> wyjscia;
    public:
        /**
         * @brief Domyslny konstruktor.
         * * Przygotowuje poczatkowy stan pamieci dla maszyny i jej magazynow.
         */
        Podstawowy_blok_funkcyjny();

        void dodaj_wejscie(Interfejs_wejscia* w) { wejscia.push_back(w); }
        void dodaj_wyjscie(Interfejs_wyjscia* w) { wyjscia.push_back(w); }

        /**
         * @brief Wirtualny destruktor.
         * * Gwarantuje poprawne zniszczenie wszystkich fizycznych gniazd, ktore byly
         * wbudowane w ta maszyne (czyszczenie wektorow).
         */
        virtual ~Podstawowy_blok_funkcyjny();

        /**
         * @brief Zwraca pilota (wskaznik) do konkretnego gniazda wejsciowego.
         * * @param ktore_wejscie Numer indeksu gniazda w wektorze.
         * * @return Wskaznik na zadany Interfejs_wejscia lub nullptr, jesli taki indeks nie istnieje.
         */
        Interfejs_wejscia* wez_wejscie(int ktore_wejscie) override;

        /**
         * @brief Zwraca pilota (wskaznik) do konkretnego gniazda wyjsciowego.
         * * @param ktore_wyjscie Numer indeksu gniazda w wektorze.
         * * @return Wskaznik na zadany Interfejs_wyjscia lub nullptr, jesli taki indeks nie istnieje.
         */
        Interfejs_wyjscia* wez_wyjscie(int ktore_wyjscie) override;

        /**
         * @brief Przeszukuje gniazda i automatycznie podpina kabel do pierwszego wolnego.
         * * @param polacz_wejscie Wskaznik na kabel (Interfejs_polaczenia), ktory chcemy wpiac.
         * * @return True, jesli udalo sie fizycznie wpiac kabel. False w przypadku braku wolnych miejsc.
         */
        bool czy_polaczyc_wejscie(Interfejs_polaczenia* nowy_kabel);
};

#endif
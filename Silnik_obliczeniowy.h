#ifndef SILNIK_OBLICZENIOWY_H
#define SILNIK_OBLICZENIOWY_H

#include "Definicje.h"
#include "Podstawowy_blok_funkcyjny.h"
#include <vector>

/**
 * @brief Klasa zarzadzajaca glowna petla czasowa symulacji (Silnik Obliczeniowy).
 * * Odpowiada za cykl zycia symulacji: uruchamianie, wstrzymywanie, zatrzymywanie 
 * oraz iteracyjne przeliczanie pradu we wszystkich podlaczonych maszynach 
 * (blokach funkcyjnych).
 */
class Silnik_obliczeniowy
{
    private:
        long krok_symulacji;
        Status_symulacji status;
        long koniec;
        std::vector<Podstawowy_blok_funkcyjny*> bloki;
    public:
        /**
         * @brief Konstruktor domyslny. Inicjalizuje poczatkowe parametry silnika 
         * (np. krok_symulacji = 0, status = wstrzymana, domyslny koniec symulacji).
         */
        Silnik_obliczeniowy();

        /**
         * @brief Rejestruje nowa maszyne na liscie do przeliczania.
         * @param blok Wskaznik na maszyne dziedziczaca po Podstawowy_blok_funkcyjny.
         */
        void dodaj_blok(Podstawowy_blok_funkcyjny* blok);

        /**
         * @brief Resetuje czas symulacji do zera, ustawia status na pauze 
         * i wywoluje funkcje inicjalizuj() dla wszystkich podpietych blokow.
         */
        void inicjalizuj_obliczenia();

        /**
         * @brief Zmienia flage silnika na tryb dzialania (uruchomiona), 
         * dajac zielone swiatlo dla funkcji wykonaj_krok_symulacji().
         */
        void uruchom_obliczenia();

        /**
         * @brief Zmienia flage silnika na tryb pauzy (wstrzymana). 
         * Maszyny przestaja liczyc, ale zegar symulacji (krok) nie jest resetowany.
         */
        void wstrzymaj_obliczenia();

        /**
         * @brief Wykonuje kompletna symulacje od zera do konca w ulamku sekundy. 
         * Automatycznie inicjalizuje system, uruchamia go i kreci petla while 
         * az do osiagniecia limitu czasowego.
         */
        void wykonaj_obliczenia_wsadowe();

        /**
         * @brief Awaryjny hamulec tasmy. Zmienia status na zatrzymany i z reguly 
         * resetuje licznik kroku symulacji do zera.
         */
        void zatrzymaj_obliczenia();

        /**
         * @brief Mechaniczne serce silnika. Jesli maszyna ma zielone swiatlo 
         * (uruchomiona) i czas nie minal, wymusza przeliczenie pradu na kazdym 
         * z podpietych blokow, a nastepnie inkrementuje zegar o jedno "tykniecie".
         * Samoczynnie zatrzymuje obliczenia po dobiciu do limitu.
         */
        void wykonaj_krok_symulacji();
};

#endif
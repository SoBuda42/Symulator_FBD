#ifndef KONSTRUKTOR_FBD_H
#define KONSTRUKTOR_FBD_H

#include <string>
#include <vector>

class Kontener_FBD;
class Podstawowy_blok_funkcyjny;

/**
 * @brief Klasa pelniaca role Glownego Inzyniera (Wzorzec Budowniczy).
 * Odpowiada za fizyczne utworzenie konkretnych maszyn, wstawienie ich do 
 * Kontenera (hali) oraz zlutowanie ich za pomoca odpowiednich kabli 
 * wedlug zadanego schematu.
 */
class Konstruktor_FBD
{    
    private:
        /**
         * @brief Wskaznik na hale produkcyjna, w ktorej inzynier ustawia maszyny.
         */
        Kontener_FBD* kontener;

        /**
         * @brief Prywatne narzedzie (lutownica) inzyniera. Pozwala na zautomatyzowane 
         * i bezpieczne polaczenie dwoch maszyn za pomoca nowego kabla.
         * * @param odkad Wskaznik na maszyne, z ktorej wyplywa prad (zrodlo).
         * @param wyj Indeks gniazda wyjsciowego w maszynie zrodlowej.
         * @param dokad Wskaznik na maszyne, do ktorej wplywa prad (cel).
         * @param wej Indeks gniazda wejsciowego w maszynie docelowej.
         */
        void polacz_maszyny(Podstawowy_blok_funkcyjny* odkad, int wyj, Podstawowy_blok_funkcyjny* dokad, int wej);

    public:
        /**
         * @brief Tworzy inzyniera i przydziela mu konkretna hale produkcyjna.
         * @param ktory_kontener Wskaznik na istniejacy obiekt Kontener_FBD.
         */
        Konstruktor_FBD(Kontener_FBD* ktory_kontener);

        /**
         * @brief Glowna procedura budowlana. Tworzy i konfiguruje pelen uklad FBD
         * wedlug sztywno zapisanego schematu. Zleca Kontenerowi produkcje maszyn,
         * ustawia ich parametry, a nastepnie spina je kablami.
         * * @param nazwa_pliku_odczyt Sciezka do pliku zrodlowego dla Bloku Odczytu.
         * @param nazwa_pliku_zapis Sciezka docelowa dla wynikowego Bloku Zapisu.
         */
        void konfiguruj(std::string nazwa_pliku_odczyt, std::string nazwa_pliku_zapis, double wartosc_stalej,
             double wartosc_amplitudy, int wartosc_okresu, std::string znaki_addsub, double wartosc_wzmocnienia);
};

#endif
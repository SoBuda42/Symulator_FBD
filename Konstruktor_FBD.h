#ifndef KONSTRUKTOR_FBD_H
#define KONSTRUKTOR_FBD_H

#include <string>
#include <vector>

class Blok_funkcyjny;
class Wejscie;
class Wyjscie;
class Polaczenie;

/**
 * @brief Klasa zarzadzajaca cala fabryka - tworzy, konfiguruje i przechowuje wszystkie maszyny (bloki).
 */
class Konstruktor_FBD
{    
    private:
        /**
         * @brief Kontener przechowujacy adresy wszystkich utworzonych blokow w pamieci sterty.
         * Zapobiega wyciekom pamieci i usunieciu maszyn po zakonczeniu funkcji.
         */
        std::vector<Blok_funkcyjny*> lista_maszyn;

        /**
         * @brief Kontener przechowujacy adresy wszystkich utworzonych blokow w pamieci sterty.
         * Zapobiega wyciekom pamieci i usunieciu maszyn po zakonczeniu funkcji.
         */
        std::vector<Wejscie*> lista_wejsc;

        /**
         * @brief Kontener przechowujacy adresy wszystkich utworzonych blokow w pamieci sterty.
         * Zapobiega wyciekom pamieci i usunieciu maszyn po zakonczeniu funkcji.
         */
        std::vector<Wyjscie*> lista_wyjsc;

        /**
         * @brief Kontener przechowujacy adresy wszystkich utworzonych blokow w pamieci sterty.
         * Zapobiega wyciekom pamieci i usunieciu maszyn po zakonczeniu funkcji.
         */
        std::vector<Polaczenie*> lista_polaczen;

    public:
        /**
         * @brief Destruktor klasy czyszczacy fabryke.
         * Przechodzi przez wektor lista_maszyn i zwalnia pamiec (delete) po kazdym utworzonym bloku.
         */
        ~Konstruktor_FBD();

        /**
         * @brief Glowna funkcja budujaca uklad symulacji. 
         * Tworzy maszyny, gniazda, przewody i zespala je w dzialajacy obwod.
         */
        void konfiguruj();   

        /**
        * @brief Tworzy nowy adres w konterze Wejsc
        */
        Wejscie* stworz_wejscie();

        /**
        * @brief Tworzy nowy adres w konterze Wyjsc
        */
        Wyjscie* stworz_wyjscie();

        /**
        * @brief Tworzy nowy adres w konterze Polaczen
        */
        Polaczenie* stworz_polaczenie();
};

#endif
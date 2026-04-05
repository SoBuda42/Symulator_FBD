#ifndef KONTENER_FBD_H
#define KONTENER_FBD_H

#include <string>
#include <vector>

class Wejscie;
class Wyjscie;
class Polaczenie;
class Blok_funkcyjny;

class Kontener_FBD
{
    private:
        int okres_probkowania;

        /**
         * @brief Kontener przechowujacy adresy wszystkich utworzonych blokow w pamieci sterty.
         * Zapobiega wyciekom pamieci i usunieciu maszyn po zakonczeniu funkcji.
         */
        std::vector<Blok_funkcyjny*> lista_funkcyjna;

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
        ~Kontener_FBD();

        /**
        * @brief Tworzy nowy adres w konterze Funkcyjnym dla stalej
        */
        Blok_funkcyjny* stworz_stala(double wartosc);

        /**
        * @brief Tworzy nowy adres w konterze Funkcyjnym dla wzmocnienia
        */
        Blok_funkcyjny* stworz_wzmocnienie(double wartosc);

        /**
        * @brief Tworzy nowy adres w konterze Funkcyjnym dla dodawania
        */
        Blok_funkcyjny* stworz_dodawanie();

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
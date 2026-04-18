#ifndef KONTENER_FBD_H
#define KONTENER_FBD_H

#include <string>
#include <vector>

class Interfejs_wejscia;
class Interfejs_wyjscia;
class Interfejs_polaczenia;
class Podstawowy_blok_funkcyjny;

class Kontener_FBD
{
    private:
        int okres_probkowania;

        /**
         * @brief Kontener przechowujacy adresy wszystkich utworzonych blokow w pamieci sterty.
         * Zapobiega wyciekom pamieci i usunieciu maszyn po zakonczeniu funkcji.
         */
        std::vector<Podstawowy_blok_funkcyjny*> lista_funkcyjna;

        /**
         * @brief Kontener przechowujacy adresy wszystkich utworzonych blokow w pamieci sterty.
         * Zapobiega wyciekom pamieci i usunieciu maszyn po zakonczeniu funkcji.
         */
        std::vector<Interfejs_wejscia*> lista_wejsc;

        /**
         * @brief Kontener przechowujacy adresy wszystkich utworzonych blokow w pamieci sterty.
         * Zapobiega wyciekom pamieci i usunieciu maszyn po zakonczeniu funkcji.
         */
        std::vector<Interfejs_wyjscia*> lista_wyjsc;

        /**
         * @brief Kontener przechowujacy adresy wszystkich utworzonych blokow w pamieci sterty.
         * Zapobiega wyciekom pamieci i usunieciu maszyn po zakonczeniu funkcji.
         */
        std::vector<Interfejs_polaczenia*> lista_polaczen;
    public:
        /**
         * @brief Destruktor klasy czyszczacy fabryke.
         * Przechodzi przez wektor lista_maszyn i zwalnia pamiec (delete) po kazdym utworzonym bloku.
         */
        ~Kontener_FBD();

        /**
        * @brief Tworzy nowy adres w konterze Funkcyjnym dla stalej
        */
        Podstawowy_blok_funkcyjny* stworz_stala(double wartosc);

        /**
        * @brief Tworzy nowy adres w konterze Funkcyjnym dla wzmocnienia
        */
        Podstawowy_blok_funkcyjny* stworz_wzmocnienie(double wartosc);

        /**
        * @brief Tworzy nowy adres w konterze Funkcyjnym dla dodawania i odejmowania
        */
        Podstawowy_blok_funkcyjny* stworz_addsub(std::string znaki);

        /**
         * @brief Tworzy nowy adres w Kontenerze Funkcyjnym dla maszyny calkujacej.
         * @return Wskaznik na utworzony obiekt.
         */
        Podstawowy_blok_funkcyjny* stworz_calkowanie();

        /**
         * @brief Tworzy nowy adres w Kontenerze Funkcyjnym dla maszyny mnozacej.
         * @return Wskaznik na utworzony obiekt.
         */
        Podstawowy_blok_funkcyjny* stworz_mnozenie();

        /**
         * @brief Tworzy nowy adres w Kontenerze Funkcyjnym dla maszyny dzielacej.
         * @return Wskaznik na utworzony obiekt.
         */
        Podstawowy_blok_funkcyjny* stworz_dzielenie();

        /**
         * @brief Tworzy nowy adres w Kontenerze Funkcyjnym dla maszyny zrzucajacej dane na dysk.
         * @param nazwa_pliku Sciezka lub nazwa pliku docelowego (np. "wynik.csv").
         * @return Wskaznik na utworzony obiekt.
         */
        Podstawowy_blok_funkcyjny* stworz_zapis(std::string nazwa_pliku);

        /**
         * @brief Tworzy nowy adres w Kontenerze Funkcyjnym dla maszyny czytajacej dane z dysku.
         * @param nazwa_pliku Sciezka lub nazwa pliku zrodlowego z danymi.
         * @return Wskaznik na utworzony obiekt.
         */
        Podstawowy_blok_funkcyjny* stworz_odczyt(std::string nazwa_pliku);

        /**
         * @brief Tworzy nowy adres w Kontenerze Funkcyjnym dla generatora sygnalu periodycznego.
         * @param amp Maksymalna wartosc (amplituda) generowanego sygnalu.
         * @param okr Okres sygnalu (liczba krokow na pelen cykl).
         * @return Wskaznik na utworzony obiekt.
         */
        Podstawowy_blok_funkcyjny* stworz_generator(double amp, int okr);

        /**
        * @brief Tworzy nowy adres w konterze Wejsc
        */
        Interfejs_wejscia* stworz_wejscie();

        /**
        * @brief Tworzy nowy adres w konterze Wyjsc
        */
        Interfejs_wyjscia* stworz_wyjscie();

        /**
        * @brief Tworzy nowy adres w konterze Polaczen
        */
        Interfejs_polaczenia* stworz_polaczenie();
};

#endif
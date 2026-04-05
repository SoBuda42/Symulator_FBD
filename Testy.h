#ifndef TESTY_H
#define TESTY_H

class Kontener_FBD;

/**
* @brief Klasa przeprowadzajaca testy jednostkowe
*/
class Testy
{
    public:
        /**
        * @brief Funkcja wykonujaca test wzmocnienia
        * @param kontener Wskaznik na kontener blokow
        */
        void test_wzmocnienia(Kontener_FBD* kontener);

        /**
        * @brief Funkcja wykonujaca test dodawania
        * @param kontener Wskaznik na kontener blokow
        */
        void test_dodawania(Kontener_FBD* kontener);
};

#endif
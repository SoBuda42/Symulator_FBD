#ifndef INTERFEJS_BLOKU_FUNKCYJNEGO_H
#define INTERFEJS_BLOKU_FUNKCYJNEGO_H

class Interfejs_wejscia;
class Interfejs_wyjscia;

/**
 * @brief Glowny interfejs do bloku funkcyjnego pozwalajacy na zarzadzanie obliczeniami.
 * * Udostepnia definicje wszystkich operacji niezbednych do dzialania przez symulator na blokach funkcyjnych.
 */
class Interfejs_bloku_funkcyjnego
{
    public:
        /** @brief Wirtualny destruktor interfejsu bloku. */
        virtual ~Interfejs_bloku_funkcyjnego() {}

        /**
         * @brief Wydaje pilot (wskaznik) do konkretnego gniazda wejsciowego maszyny.
         * * @param ktore_wejscie Numer indeksu wejscia.
         * * @return Wskaznik na Interfejs_wejscia.
         */
        virtual Interfejs_wejscia* wez_wejscie(int ktore_wejscie)=0;

        /**
         * @brief Wydaje pilot (wskaznik) do konkretnego gniazda wyjsciowego maszyny.
         * * @param ktore_wyjscie Numer indeksu wyjscia.
         * * @return Wskaznik na Interfejs_wyjscia.
         */
        virtual Interfejs_wyjscia* wez_wyjscie(int ktore_wyjscie)=0;

        /**
         * @brief Okresla typ bloku - czy jest tylko generatorem sygnalu (np. stala, sin).
         * * @return True jesli to nadajnik (zrodlo), False w przeciwnym razie.
         */
        virtual bool czy_to_nadajnik()=0;

        /**
         * @brief Okresla typ bloku - czy jest tylko biorca sygnalu (np. zapis do pliku).
         * * @return True jesli to odbiornik (ujscie), False w przeciwnym razie.
         */
        virtual bool czy_to_odbiornik()=0;

        /**
         * @brief Przygotowuje maszyne do pracy przed uruchomieniem symulacji (np. resetuje stan).
         */
        virtual void inicjalizuj()=0;

        /**
         * @brief Glowny silnik maszyny. Wykonuje obliczenia matematyczne dla pojedynczego kroku.
         */
        virtual void przelicz()=0;
};

#endif
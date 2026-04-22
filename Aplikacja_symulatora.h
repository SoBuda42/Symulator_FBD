#ifndef APLIKACJA_SYMULATORA_H
#define APLIKACJA_SYMULATORA_H

#include <QObject>
#include <QTimer>
#include <QString>

#include "Kontener_FBD.h"
#include "Konstruktor_FBD.h"

/**
 * @class Aplikacja_symulatora
 * @brief Klasa maszynowni zarządzająca asynchroniczną pętlą symulacji.
 * * Wykorzystuje obiekt QTimer do cyklicznego wywoływania kroków symulacji (obliczeń FBD),
 * co zapobiega zawieszaniu się interfejsu graficznego.
 */
class Aplikacja_symulatora : public QObject
{
    Q_OBJECT

    public:
        /**
         * @brief Konstruktor klasy Aplikacja_symulatora.
         * Inicjalizuje zegar systemowy i łączy jego sygnał tyknięcia z krokiem symulacji.
         * * @param parent Wskaźnik na obiekt nadrzędny (domyślnie nullptr).
         */
        Aplikacja_symulatora(QObject *parent = nullptr);

        /**
         * @brief Uruchamia wewnętrzny zegar taktujący symulację.
         */
        void uruchom(); 

        /**
        * @brief Zatrzymuje zegar systemowy, pauzując symulację.
        */
        void zatrzymaj();
    private:
        QTimer *zegar_systemowy;  ///< Zegar odmierzający interwały czasowe pomiędzy krokami symulacji

        Kontener_FBD *kontener;
        Konstruktor_FBD *robot_montazowy;

        int aktualny_blok = 0;
    public slots:
        void zmien_zasilanie(double nowa_wartosc);
        void zmien_aktualny_blok(int ktory_blok);
        void wartosci_poczatkowe_fabryki(QString plik_wej, QString plik_wyj, double wartosc_stalej,
             double wartosc_amplitudy, int wartosc_okresu, QString znaki_addsub, double wartosc_wzmocnienia);

    private slots:
        /**
         * @brief Wykonuje pojedynczy krok obliczeniowy symulatora.
         * Funkcja wywoływana automatycznie przy każdym "tyknięciu" zegara.
         */
        void wykonaj_krok_symulacji();

    signals:
        /**
         * @brief Sygnał emitowany w celu wysłania tekstu do interfejsu graficznego.
         * * @param wiadomosc Ciąg znaków (log/wynik) do wyświetlenia na konsoli.
        */
        void przeslij_na_ekran(QString wiadomosc);
};

#endif
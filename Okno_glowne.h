#ifndef OKNO_GLOWNE_H
#define OKNO_GLOWNE_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include "Aplikacja_symulatora.h"

/**
 * @class Okno_glowne
 * @brief Klasa reprezentująca główny panel sterowania interfejsu graficznego (GUI).
 * * Odpowiada za wyświetlanie przycisków sterujących, konsoli logów oraz za
 * zarządzanie instancją głównego silnika symulacji (Aplikacja_symulatora).
 * Dziedziczy po QMainWindow.
 */
class Okno_glowne : public QMainWindow
{
    Q_OBJECT

    private:
        QPushButton *przycisk_start;  ///< Przycisk uruchamiający taśmę symulatora
        QPushButton *przycisk_pauza;  ///< Przycisk zatrzymujący symulację
        QPushButton *przycisk_buduj;  
        QTextEdit *konsola_logow;  ///< Ekran tekstowy do wyświetlania logów i wyników
        Aplikacja_symulatora *menadzer_symulacji;  ///< Wskaźnik na obiekt głównego silnika

        QLineEdit *pole_plik_wejsciowy;
        QLineEdit *pole_plik_wyjsciowy;
        QDoubleSpinBox *pole_amp_gen;
        QSpinBox *pole_okres_gen;
        QDoubleSpinBox *pole_wartosci_stalej;
        QLineEdit *pole_znaki_addsub;
        QDoubleSpinBox *pole_wzmocnienie;
        

    public:
        /**
        * @brief Konstruktor klasy Okno_glowne.
        * * Inicjalizuje wszystkie elementy interfejsu (widgety), ustawia główny układ (layout)
        * okna oraz fizycznie łączy sygnały (np. kliknięcia) z odpowiednimi slotami.
        * * @param parent Wskaźnik na obiekt nadrzędny (domyślnie nullptr).
        */
        Okno_glowne(QWidget *parent = nullptr);

        /**
        * @brief Destruktor klasy Okno_glowne.
        */
        ~Okno_glowne();

    private slots:
    /**
         * @brief Slot wywoływany po kliknięciu przycisku START.
         * Uruchamia silnik symulacji.
         */
        void kliknieto_start();

        /**
         * @brief Slot wywoływany po kliknięciu przycisku PAUZA.
         * Zatrzymuje działanie silnika symulacji.
         */
        void kliknieto_pauza();

        void kliknieto_buduj();
};

#endif
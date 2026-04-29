#include "Aplikacja_symulatora.h"
#include "Wlasciwy_blok_przetwarzania.h"
#include "Okno_glowne.h"
#include "Wejscie.h"
#include "Wyjscie.h"
#include <QDebug>
#include <fstream>
#include <string>

using namespace std;

Aplikacja_symulatora::Aplikacja_symulatora(QObject *parent) : QObject(parent)
{
    zegar_systemowy = new QTimer(this);
    connect(zegar_systemowy, &QTimer::timeout, this, &Aplikacja_symulatora::wykonaj_krok_symulacji);

    kontener = nullptr;
    robot_montazowy = nullptr;
}

void Aplikacja_symulatora::wartosci_poczatkowe_fabryki(QString plik_wej, QString plik_wyj, double wartosc_stalej, 
    double wartosc_amplitudy, int wartosc_okresu, QString znaki_addsub, double wartosc_wzmnocnienia)
{
    zegar_systemowy->stop();
    if(robot_montazowy != nullptr) 
    {
        delete robot_montazowy;
        robot_montazowy=nullptr;
    }

    if(kontener != nullptr) 
    {
        delete kontener;
        kontener = nullptr;
    }    

    kontener = new Kontener_FBD();
    robot_montazowy = new Konstruktor_FBD(kontener);

    limit_krokow_odczytu = 0;
    aktualny_krok_odczytu = 0;

    ifstream plik_do_policzenia(plik_wej.toStdString());
    double tymczasowa_liczba;
    while(plik_do_policzenia>>tymczasowa_liczba) {limit_krokow_odczytu++;}
    plik_do_policzenia.close();

    robot_montazowy->konfiguruj(plik_wej.toStdString(), plik_wyj.toStdString(), wartosc_stalej, wartosc_amplitudy, 
    wartosc_okresu, znaki_addsub.toStdString(), wartosc_wzmnocnienia);

    emit przeslij_na_ekran(">>Nadano wartosci poczatkowe fabryki!");
}

void Aplikacja_symulatora::zmien_zasilanie(double nowa_wartosc) {}

void Aplikacja_symulatora::zmien_aktualny_blok(int ktory_blok) {aktualny_blok = ktory_blok;}

void Aplikacja_symulatora::uruchom() {zegar_systemowy->start(500);}

void Aplikacja_symulatora::zatrzymaj() {zegar_systemowy->stop();}

void Aplikacja_symulatora::wykonaj_krok_symulacji() 
{
    if(kontener == nullptr)
    {
        zegar_systemowy->stop();
        emit przeslij_na_ekran(">> BLAD: Hali nie ma! Najpierw kliknij PRZYGOTUJ FABRYKE.");
        return;
    }

    if(aktualny_krok_odczytu >= limit_krokow_odczytu)
    {
        zegar_systemowy->stop();
        emit przeslij_na_ekran("[INFO] Maszyna wciagnela wszystkie dane z pliku! Zatrzymano tasme.");
        return;
    }

    aktualny_krok_odczytu++;

    kontener->przelicz_wszystkie_bloki();
    Interfejs_wyjscia* ostatnie_wyjscie = kontener->pobierz_ostatnie_wyjscie();


    if(ostatnie_wyjscie != nullptr)
    {
        double w = ostatnie_wyjscie->pobierz_wartosc().pobierz_liczbe();
        QString wiadomosc = ">> Sygnal na wyjsciu glownym (Blok Zapisu): " + QString::number(w);
        emit przeslij_na_ekran(wiadomosc);
    }
    else emit przeslij_na_ekran(">>Ostatnie wyjscie jest puste!");
    
}
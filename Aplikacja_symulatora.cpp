#include "Aplikacja_symulatora.h"
#include "Wlasciwy_blok_przetwarzania.h"
#include "Wejscie.h"
#include "Wyjscie.h"
#include <QDebug>

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
    if(kontener != nullptr) delete kontener;
    if(robot_montazowy != nullptr) delete robot_montazowy;

    kontener = new Kontener_FBD();
    robot_montazowy = new Konstruktor_FBD(kontener);
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
    kontener->przelicz_wszystkie_bloki();
    Interfejs_wyjscia* ostatnie_wyjscie = kontener->pobierz_ostatnie_wyjscie();

    if(ostatnie_wyjscie != nullptr)
    {
        double w = ostatnie_wyjscie->pobierz_wartosc().pobierz_liczbe();
        emit przeslij_na_ekran(">>Wynik z ostatniego wyjscia: " + QString::number(w));
    }
    else emit przeslij_na_ekran(">>Ostatnie wyjscie jest puste!");
}
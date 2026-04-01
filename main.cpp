#include <iostream>
#include "Konstruktor_FBD.h"
#include "Blok_funkcyjny.h"
#include "Polaczenie.h"
#include "Blok_stalej.h"
#include "Blok_wzmocnienia.h"
#include "Wejscie.h"
#include "Wyjscie.h"
#include "Blok_dodawania.h"

using namespace std;

void test_wzmocnienia()
{
    Blok_funkcyjny *prad = new Blok_stalej(5.0);
    Blok_funkcyjny *wzmocnienie = new Blok_wzmocnienia(2.0);

    Wejscie *do_wzmocnienia = new Wejscie();
    Wyjscie *od_wzmocnienia = new Wyjscie();
    Wyjscie *od_stalej = new Wyjscie();

    prad->dodaj_wyjscie(od_stalej);
    wzmocnienie->dodaj_wyjscie(od_wzmocnienia);
    wzmocnienie->dodaj_wejscie(do_wzmocnienia);

    Polaczenie *kabel = new Polaczenie();
    kabel->polacz_z(prad->wez_wyjscie(0));
    kabel->polacz_do(wzmocnienie->wez_wejscie(0));
    do_wzmocnienia->polacz(kabel);

    prad->przelicz();
    wzmocnienie->przelicz();

    Wartosc out = wzmocnienie->wez_wyjscie(0)->pobierz_wartosc();
    double wynik = out.pobierz_liczbe();

    if (wynik = 10.0)
    {
        cout << "\n[OK] Test wzmocnienia: ZDANY!";
    }
    else
    {
        cout << "\n[BŁĄD] Test wzmocnienia: OBLANY! (Oczekiwano 10)";
    }
    cout << endl;

    delete prad;
    delete wzmocnienie;
    delete kabel;
}

void test_dodawania()
{
    Blok_funkcyjny* w1 = new Blok_stalej(2.0);
    Blok_funkcyjny* w2 = new Blok_stalej(3.0);
    Blok_funkcyjny* suma = new Blok_dodawania();

    Wyjscie* od_w1 = new Wyjscie();
    Wyjscie* od_w2 = new Wyjscie();

    Wejscie* do_sumy_1 = new Wejscie();
    Wejscie* do_sumy_2 = new Wejscie();
    Wyjscie* od_sumy = new Wyjscie();

    w1->dodaj_wyjscie(od_w1);
    w2->dodaj_wyjscie(od_w2);

    suma->dodaj_wejscie(do_sumy_1);
    suma->dodaj_wejscie(do_sumy_2);
    suma->dodaj_wyjscie(od_sumy);

    Polaczenie* kabel_1 = new Polaczenie();
    kabel_1->polacz_z(od_w1);
    kabel_1->polacz_do(do_sumy_1);
    do_sumy_1->polacz(kabel_1);

    Polaczenie* kabel_2 = new Polaczenie();
    kabel_2->polacz_z(od_w2);
    kabel_2->polacz_do(do_sumy_2);
    do_sumy_2->polacz(kabel_2);
    
    w1->przelicz();
    w2->przelicz();
    suma->przelicz();

    Wartosc out = suma->wez_wyjscie(0)->pobierz_wartosc();
    double wynik = out.pobierz_liczbe();

    if(wynik==5.0) {cout<<"Test zdany!"<<endl;}
    else {cout<<"Test niezdany, awaria!"<<endl;}

    delete w1;
    delete w2;
    delete suma;
    delete kabel_1;
    delete kabel_2;
}

int main()
{
    cout << "\nTest wzmocnienia:" << endl;
    test_wzmocnienia();

    cout<<"\nTest dodawania:"<<endl;
    test_dodawania();
    cout<<endl;

    Konstruktor_FBD konfiguracja;
    konfiguracja.konfiguruj();
    return 0;
}
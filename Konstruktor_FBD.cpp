#include "Konstruktor_FBD.h"
#include "Kontener_FBD.h"
#include "Podstawowy_blok_funkcyjny.h"
#include "Interfejs_polaczenia.h"
#include "Interfejs_wejscia.h"

using namespace std;

void Konstruktor_FBD::polacz_maszyny(Podstawowy_blok_funkcyjny* odkad, int wyj, Podstawowy_blok_funkcyjny* dokad, int wej)
{
    Interfejs_polaczenia* kabel = kontener->stworz_polaczenie();
    kabel->polacz_z(odkad->wez_wyjscie(wyj));
    kabel->polacz_do(dokad->wez_wejscie(wej));
    dokad->wez_wejscie(wej)->polacz(kabel);
}

Konstruktor_FBD::Konstruktor_FBD(Kontener_FBD* ktory_kontener) {kontener = ktory_kontener;}

void Konstruktor_FBD::konfiguruj(string nazwa_pliku_odczyt, string nazwa_pliku_zapis) 
{
    Podstawowy_blok_funkcyjny* odczyt = kontener->stworz_odczyt(nazwa_pliku_odczyt);
    Podstawowy_blok_funkcyjny* generator = kontener->stworz_generator(5.0, 20);
    Podstawowy_blok_funkcyjny* stala = kontener->stworz_stala(1.0);
    Podstawowy_blok_funkcyjny* addsub = kontener->stworz_addsub("-+++");
    Podstawowy_blok_funkcyjny* calkowanie = kontener->stworz_calkowanie();
    Podstawowy_blok_funkcyjny* wzmocnienie = kontener->stworz_wzmocnienie(0.1);
    Podstawowy_blok_funkcyjny* zapis = kontener->stworz_zapis(nazwa_pliku_zapis);

    polacz_maszyny(odczyt, 0, addsub, 0);
    polacz_maszyny(generator, 0, addsub, 1);
    polacz_maszyny(stala, 0, addsub, 2);
    polacz_maszyny(wzmocnienie, 0, addsub, 3);
    polacz_maszyny(addsub, 0, calkowanie, 0);
    polacz_maszyny(calkowanie, 0, wzmocnienie, 0);
    polacz_maszyny(wzmocnienie, 0, zapis, 0);
}
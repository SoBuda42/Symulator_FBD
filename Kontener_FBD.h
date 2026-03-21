#ifndef KONTENER_FBD_H
#define KONTENER_FBD_H

#include <string>
using namespace std;

class Blok_funkcyjny;
class Polaczenie;

class Kontener_FBD
{
    private:
        int okres_probkowania;
    public:
        void dodaj_blok_funkcyjny(Blok_funkcyjny* blok);
        Blok_funkcyjny* blok_funkcyjny(string nazwa);
        void dodaj_polaczenie(Polaczenie* polaczenie);
};

#endif
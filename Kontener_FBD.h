#ifndef KONTENER_FBD_H
#define KONTENER_FBD_H

#include <string>
#include <vector>

class Blok_funkcyjny;
class Polaczenie;

class Kontener_FBD
{
    private:
        int okres_probkowania;
        std::vector<Blok_funkcyjny*> bloki;
        std::vector<Polaczenie*> polaczenia;
    public:
        void dodaj_blok_funkcyjny(Blok_funkcyjny* blok);
        Blok_funkcyjny* blok_funkcyjny(std::string nazwa);
        void dodaj_polaczenie(Polaczenie* polaczenie);
};

#endif
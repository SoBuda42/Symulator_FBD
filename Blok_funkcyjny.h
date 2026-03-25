#ifndef BLOK_FUNKCYJNY_H
#define BLOK_FUNKCYJNY_H

#include <vector>

using namespace std;

class Wejscie;
class Wyjscie;

class Blok_funkcyjny
{
    protected:
        vector<Wejscie*> wejscia;
        vector<Wyjscie*> wyjscia;
    public:
        virtual void przelicz();

        void dodaj_wejscie(Wejscie* w);
        void dodaj_wyjscie(Wyjscie* w);
        
        Wejscie* wez_wejscie(int numer);
        Wyjscie* wez_wyjscie(int numer);
};

#endif
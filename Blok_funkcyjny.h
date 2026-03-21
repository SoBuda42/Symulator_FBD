#ifndef BLOK_FUNKCYJNY_H
#define BLOK_FUNKCYJNY_H

class Wejscie;
class Wyjscie;

class Blok_funkcyjny
{
    public:
        void przelicz();
        Wejscie* wez_wejscie(int numer);
        Wyjscie* wez_wyjscie(int numer);
};

#endif
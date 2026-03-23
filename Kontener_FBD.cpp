#include "Kontener_FBD.h"
#include "Blok_funkcyjny.h"
#include "Polaczenie.h"

using namespace std;

void Kontener_FBD::dodaj_blok_funkcyjny(Blok_funkcyjny* blok) {bloki.push_back(blok);}

Blok_funkcyjny* Kontener_FBD::blok_funkcyjny(string nazwa) {return nullptr;}

void Kontener_FBD::dodaj_polaczenie(Polaczenie* polaczenie) {polaczenia.push_back(polaczenie);}
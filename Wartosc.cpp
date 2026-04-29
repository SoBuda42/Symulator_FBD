#include "Wartosc.h"

Wartosc::Wartosc() {wartosc = 0.0;}

Wartosc::Wartosc(double startowa_wartosc) {wartosc = startowa_wartosc;}

double Wartosc::pobierz_liczbe() {return wartosc;}

void Wartosc::ustaw_liczbe(double nowa_liczba) {wartosc = nowa_liczba;}
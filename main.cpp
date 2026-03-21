#include <iostream>
#include "Silnik_obliczeniowy.h"

using namespace std;

int main() {
    Silnik_obliczeniowy moj_silnik;
    moj_silnik.uruchom_obliczenia();
    
    cout << "Architektura wieloplikowa dziala bezblednie!" << endl;
    
    return 0;
}
#include <iostream>
#include "Kontener_FBD.h"
#include "Testy.h"

using namespace std;

int main()
{
    Kontener_FBD kontener_obiektow;
    Testy tester;

    cout << "\nTest wzmocnienia:" << endl;
    tester.test_wzmocnienia(&kontener_obiektow);

    cout<<"\nTest dodawania:"<<endl;
    tester.test_dodawania(&kontener_obiektow);
    cout<<endl;

    return 0;
}
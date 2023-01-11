#include <iostream>
#include "date.h"
using namespace std;

int main()
{
    // Opettajan esimerkki
    Date pvml;

    cout << "Anna pvm: ";
    char c;
    cin >> pvml.day >> c >> pvml.month >> c >> pvml.year;

    cout << "Annoit: " << pvml.day << c << pvml.month << c << pvml.year << endl;
    if (pvml.isValid() == false){
        cout << "Pvm on virheellinen!" << endl;
    }

    // Oma koodi
    if (pvml.kVuosi() == true){
        cout << "Kyseessa on karkausvuosi" << endl;
    }

    return 0;
}

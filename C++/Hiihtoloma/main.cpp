#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "date.h"

using namespace std;

int main()
{
    Date start(20, 2, 2023);
    Date end(26, 2, 2023);
    Date pvm;
    char c;

    while (!pvm.isValid()) {
    cout << "Kirjoita paivamaara: ";
    cin >> pvm.day >> c >> pvm.month >> c >> pvm.year;
    }

    if(start < pvm && pvm < end) {
        cout << "Kyseessa on hiihtoloma." << endl;
    }
    else
        cout << "Kyseessa ei ole hiihtoloma." << endl;

//    cout << "Annoit: " << pvm.day << c << pvm.month << c << pvm.year << endl;
//    if (pvm.isValid() == true){
//        cout << "Kyseessa on hiihtoloma." << endl;
//    }
//    else
//        cout << "Kyseessa ei ole hiihtoloma." << endl;

    cout << endl;
    return 0;
}

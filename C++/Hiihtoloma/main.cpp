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
    Date pvm; // Vaati default constructorin toimiakseen

    while (!pvm.isValid()) {
        char c;
        cout << "Kirjoita paivamaara: ";
        cin >> pvm.m_day >> c >> pvm.m_month >> c >> pvm.m_year;
    }

    if(start < pvm && pvm < end) {
        cout << "Kyseessa on hiihtoloma." << endl;
    }
    else
        cout << "Kyseessa ei ole hiihtoloma." << endl;

    cout << endl;
    return 0;
}

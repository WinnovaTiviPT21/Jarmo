#include <iostream>

using namespace std;

int main()
{
    int x;
    int y;
    int summa;
    int erotus;

    cout << "Anna luku: ";
    cin >> x;

    cout << "Anna toinen luku: ";
    cin >> y;

    summa = x + y;
    erotus = x - y;

    cout << "Antamiesi lukujen summa on: " << summa << endl;
    cout << "Antamiesi lukujen erotus on: " << erotus << endl;

    return 0;
}

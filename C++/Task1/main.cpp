#include <iostream>

using namespace std;

int kysymys()
{
    int luku;
    cout << "Anna luku: ";
    cin >> luku;
    return luku;
}

void tulostus(int x, int y)
{
    int summa = x + y;
    int erotus = x - y;
    cout << "Antamiesi lukujen summa on: " << summa << endl;
    cout << "Antamiesi lukujen erotus on: " << erotus << endl;
}

int main()
{
    int x = kysymys();
    int y = kysymys();

    tulostus(x, y);
    return 0;
}

#include <iostream>

using namespace std;

int kysymys(string txt)
{
    cout << txt;
    int luku;
    cin >> luku;
    return luku;
}

void tulostus(int x, int y)
{
    cout << "Antamiesi lukujen summa on: " << x + y << endl;
    cout << "Antamiesi lukujen erotus on: " << x - y << endl;
}

int main()
{
    int x = kysymys("Anna luku: ");
    int y = kysymys("Anna toinen luku: ");

    tulostus(x, y);
    return 0;
}

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "The local date and time is: " << dt << endl;
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    /*int pv;
    int kk;
    int vuosi;

    cout << "Anna paivamaara: ";
    cin >> pv;
    if(pv < 1 || pv > 31)
    {
        cout << "Antamasi paivamaara on virheellinen!\n";
    }

    cout << "Anna kuukausi: ";
    cin >> kk;
    if(kk < 1 || kk > 12)
    {
        cout << "Antamasi kuukausi on virheellinen!\n";
    }

    cout << "Anna vuosiluku: ";
    cin >> vuosi;

    cout << "Antamasi paivamara on: " << pv << "." << kk << "." << vuosi << endl;
    if(vuosi % 400 == 0)
    {
        cout << "Kyseessa on karkausvuosi\n";
    }
    else if(vuosi % 100 == 0)
    {
        cout << "Kyseessa ei ole karkausvuosi\n";
    }
    else if(vuosi % 4 == 0)
    {
        cout << "Kyseessa on karkausvuosi\n";
    }
    else
    {
        cout << "Kyseessa ei ole karkausvuosi\n\n";
    }*/
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int vuosi = 0;
    cout << "Anna vuosiluku: ";
    cin >> vuosi;

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
        cout << "Kyseessa ei ole karkausvuosi\n";
    }
    return 0;
}

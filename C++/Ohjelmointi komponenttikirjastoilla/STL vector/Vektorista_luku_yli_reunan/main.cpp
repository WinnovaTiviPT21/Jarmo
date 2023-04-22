#include <iostream>
#include <random>
#include <vector>

using namespace std;

/*
**
** Tehtävänanto
**
** Tee konsolisovellus, joka arpoo satunnaislukuja 10 kappaletta ja tallentaa ne STL vectoriin.
** Alusta Mersenne Twister seuraavasti:
**
**   std::mt19937 generator{ 42 };
**   std::uniform_int_distribution<int> distribution{ std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };
**
** 1. Tulosta vektorista luvut väliltä 0-20. Palauta tänne tulostus.
** 2. Mitä tapahtuu, jos hakasulku-operaattorin sijaan käytät metodia at().
**
*/
int main()
{
    int n = 10;

    mt19937 gen{ 42 };
    uniform_int_distribution<int> distr{ numeric_limits<int>::min(), numeric_limits<int>::max() };

    vector<int> numbers(n);
    numbers.resize(n);
    for (int i = 0; i < n; i++) {
        int randomNumber = distr(gen);
        numbers[i] = randomNumber;
    }

    for (int i = 0; i < 20; i++) {
        //cout << numbers[i] << endl;
        cout << numbers.at(i) << endl;
    }

    cout << "" << endl;
    return 0;
}

#include <iostream>
#include <random>

using namespace std;

/*
**
** Tehtävänanto
**
** Tee konsolisovellus, joka arpoo satunnaislukuja 10 miljoona kappaletta ja tallentaa ne STL vectoriin.
** Alusta Mersenne Twister seuraavasti:
**
** std::mt19937 generator{ 42 };
** std::uniform_real_distribution<float> distribute{ -1e6, 1e6 };
**
** Huomaa – nyt generoidaan liukulukuja ei kokonaislukuja.
** Laske kuinka monen luvun itseisarvo < 1.
**
*/
int main()
{
    int N = 1e7;

    mt19937 gen{ 42 };
    uniform_real_distribution<float> dist{ -1e6, 1e6 };

    vector<float> numbers(N);
    numbers.resize(N);

    for (int i = 0; i < N; i++) {
        float randomNumber = dist(gen);
        numbers[i] = randomNumber;
    }

    /*
    **
    ** Aikaisemmin käyttämäni for loop vektorin lukemiseen:
    **
    ** int counter = 0;
    ** for (int i = 0; i < N; i++) {
    **     float temp = numbers[i];
    **     if (temp < 1 && temp > -1) {
    **         counter++;
    **     }
    ** }
    **
    */
    int counter = 0;
    for (float temp : numbers) {
        if (temp < 1 && temp > -1) {
            counter++;
        }
    }

    cout << "Kuinka monen luvun itseisarvo < 1?" << endl;
    cout << "Vastaus: " << counter << endl;

    cout << "" << endl;
    return 0;
}

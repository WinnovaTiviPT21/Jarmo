/*
 *
 * Tee konsolisovellus, joka arpoo satunnaislukuja 10 miljoona kappaletta ja tallentaa ne STL vectoriin. Alusta Mersenne Twister seuraavasti
 *
 * std::mt19937 generator{ 42 };
 * std::uniform_int_distribution<int> lottery{ std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };
 *
 * Käytä STL:n map-luokkaa histogrammin laskentaa. Tulosta ne luvut, joita on kolme tai enemmän.
 *
*/

#include <iostream>
#include <random>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n = 1e7;

    mt19937 gen{ 42 };
    uniform_int_distribution<int> distr{ numeric_limits<int>::min(), numeric_limits<int>::max() };

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        int randomNumber = distr(gen);
        numbers[i] = randomNumber;
    }

    map<int, int> histogram;
    for (int x : numbers) {
        histogram[x]++;
    }

    cout << "Luvut, joita on kolme tai enemman:\n";
    for (map<int, int>::iterator it = histogram.begin(); it != histogram.end(); it++) {
        if (it->second >= 3) {
            cout << it->first << ": " << it->second << " kpl\n";
        }
    }

    cout << "" << endl;
    return 0;
}

/*
 *
 * Tehtävänanto
 * Tee konsolisovellus, joka arpoo satunnaislukuja 10 miljoona kappaletta ja tallentaa ne STL set:iin.
 *
 * Alusta Mersenne Twister seuraavasti
 *   std::mt19937 generator{ 42 };
 *   std::uniform_int_distribution<int> lottery{ std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };
 *
 * Käytä STL:n set-luokkaa 10 suurimman luvun tulostamiseen. Tulosta elementit.
 *
*/

#include <iostream>
#include <random>
#include <set>

using namespace std;

int main()
{
    const int N = 1e7;

    mt19937 gen{42};
    uniform_int_distribution<int> distr{numeric_limits<int>::min(), numeric_limits<int>::max()};

    set<int> s;

    for (int i = 0; i < N; i++) {
        s.insert(distr(gen));
    }

    set<int>::reverse_iterator rit = s.rbegin();
    for (int i = 0; i < 10; i++) {
        cout << *rit << endl;
        rit++;
    }

    cout << "" << endl;
    return 0;
}

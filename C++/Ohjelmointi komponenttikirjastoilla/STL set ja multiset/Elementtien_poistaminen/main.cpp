/*
 *
 * Tehtävänanto
 *
 * Tee konsolisovellus, joka arpoo satunnaislukuja 10 miljoona kappaletta ja tallentaa ne STL set-luokkaan.
 *
 * Alusta Mersenne Twister seuraavasti
 *   std::mt19937 generator{ 42 };
 *   std::uniform_int_distribution<int> lottery{ std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };
 *
 * Poista luvut, jotka ovat miljardia suuremmat. Tulosta kuinka monta lukua jäi jäljelle.
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

    set<int>::iterator it = s.lower_bound(1000000000);
    s.erase(it, s.end());

    cout << s.size() << endl;

    cout << "" << endl;
    return 0;
}

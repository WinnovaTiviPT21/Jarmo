/*
 *
 * Tehtävänanto
 * Tee konsolisovellus, joka arpoo satunnaislukuja 10 miljoona kappaletta ja tallentaa ne STL vectoriin.
 *
 * Alusta Mersenne Twister seuraavasti:
 *   std::mt19937 generator{ 42 };
 *   std::uniform_int_distribution<int> lottery{ std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };
 *
 * Käytä STL:n set-luokkaa duplikaattien poistoon. Tulosta elementtien lukumäärä duplikaattien poiston jälkeen.
 *
*/

#include <iostream>
#include <random>
#include <vector>
#include <set>

using namespace std;

int main()
{
    const int N = 1e7;

    mt19937 gen{42};
    uniform_int_distribution<int> distr{numeric_limits<int>::min(), numeric_limits<int>::max()};

    vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        int randomNumber = distr(gen);
        numbers[i] = randomNumber;
    }

    set<int> s;
    for (int i = 0; i < N; i++) {
        s.insert(numbers[i]);
    }

    cout << "Set sisaltaa " << s.size() << " elementtia.\n";

    cout << "" << endl;
    return 0;
}

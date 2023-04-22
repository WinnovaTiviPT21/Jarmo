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
 * Hae nollaa lähimpänä olevat luvut ja tulosta ne. Siis nollan ylä- ja alapuolella olevat luvut. Käytä tässä joko upper_bound tai lower_bound -metodia.
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

    auto it = s.lower_bound(0);
    cout << *it << endl;

    //it--;
    cout << *--it << endl;

    cout << "" << endl;
    return 0;
}

/*
 *
 * Joukkojen leikkaus (set intersection)
 *
 * Tehtävänanto
 *
 * Tee konsolisovellus, joka arpoo miljoona satunnaislukua ja lisää ne STL set:iin.
 * Tee näitä kaksi siten, että käytät edelleen samaa satunnaislukugeneraattoria.
 *
 * Alusta Mersenne Twister seuraavasti
 *   std::mt19937 generator{ 42 };
 *   std::uniform_int_distribution<int> lottery{ std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };
 *
 * Hae kokonaisluvut, jotka esiintyvät molemmissa joukoissa (set).
 *
*/

#include <iostream>
#include <algorithm>
#include <random>
#include <set>

using namespace std;

int main()
{
    const int N = 1e6;

    mt19937 gen{42};
    uniform_int_distribution<int> distr{numeric_limits<int>::min(), numeric_limits<int>::max()};

    set<int> s1;
    for (int i = 0; i < N; i++)
    {
        s1.insert(distr(gen));
    }

    set<int> s2;
    for (int i = 0; i < N; i++)
    {
        s2.insert(distr(gen));
    }

    set<int> s_intersection;

    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s_intersection, s_intersection.begin()));

    for (int i : s_intersection)
    {
        cout << i << endl;
    }

    cout << "" << endl;
    return 0;
}

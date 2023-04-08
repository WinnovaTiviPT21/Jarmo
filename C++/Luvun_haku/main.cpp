/*
 *
 * Tee konsolisovellus, joka arpoo satunnaislukuja 10 miljoona kappaletta ja tallentaa ne STL set:iin.
 *
 * Alusta Mersenne Twister seuraavasti
 *   std::mt19937 generator{ 42 };
 *   std::uniform_int_distribution<int> lottery{ std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };
 *
 * Hae seuraavat luvut ja tulosta kaikki kohdat (kuinka mones alusta laskien), joissa luku esiintyy.
 *  -1245214370
 *   122460941
 *  -122460941
 *   1385283091
 *
*/

#include <iostream>
#include <random>
#include <set>

using namespace std;

void position(int x, set<int> &s) {
    set<int>::iterator start, pos;
    start = s.begin();
    pos = s.find(x);
    if (pos != s.end()) {
        cout << "Element found at position: " << distance(start, pos) << endl;
    } else {
        cout << "Element not found\n";
    }
}

int main()
{
    const int N = 1e7;
    const int numA = -1245214370, numB = 122460941, numC = -122460941, numD = 1385283091;

    mt19937 gen{42};
    uniform_int_distribution<int> distr{numeric_limits<int>::min(), numeric_limits<int>::max()};

    set<int> s;

    for (int i = 0; i < N; i++) {
        int randomNumber = distr(gen);
        s.insert(randomNumber);
    }

    position(numA, s);
    position(numB, s);
    position(numC, s);
    position(numD, s);

    cout << "" << endl;
    return 0;
}

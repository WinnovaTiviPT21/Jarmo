/*
 *
 * Tehtävänanto
 * Tee konsolisovellus, joka arpoo satunnaislukuja miljoona kappaleita ja tallentaa ne STL vectoriin.
 *
 * Alusta Mersenne Twister seuraavasti
 *   std::mt19937 generator{ 42 };
 *   std::uniform_int_distribution<int> distribution{ std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };
 *
 * Kopioit elementit väliltä 123450-123458 toiseen STL vektoriin.
 *
 * Tulosta kaikki elementit tästä kopiosta.
 *
 * Palauta polku GitHub:ssa ja ohjelman tulostus.
 *
*/

#include <iostream>
#include <random>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    const int N = 1e6;

    mt19937 gen{42};
    uniform_int_distribution<int> distr{numeric_limits<int>::min(), numeric_limits<int>::max()};

    vector<int> numbersA(N);
    vector<int> numbersB;
    vector<int>::iterator it;

    for (int i = 0; i < N; i++) {
        int randomNumber = distr(gen);
        numbersA[i] = randomNumber;
    }

    for (it = numbersA.begin() + 123450; it != numbersA.begin() + 123458; it++) {
        int temp = 0;
        temp = *it;
        numbersB.push_back(temp);
    }

    for (int i : numbersB) {
        cout << i << endl;
    }

    cout << "" << endl;
    return 0;
}

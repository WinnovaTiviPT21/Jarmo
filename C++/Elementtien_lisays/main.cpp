/*
 *
 * Tehtävänanto
 * Tee konsolisovellus, joka arpoo satunnaislukuja miljoona kappaleita ja tallentaa ne STL vectoriin.
 *
 * Alusta Mersenne Twister seuraavasti
 *   std::mt19937 generator{ 42 };
 *   std::uniform_int_distribution<int> distribution{ std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };
 *
 * Lisää satunnaislukuvektoriin seuraavat luvut alkaen indeksistä 500000.
 *
 * {99, 98, 97, 96, 95}
 *
 * Tulosta luvut väliltä 499990-500010.
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

    vector<int> numbers(N);
    vector<int>::iterator it = numbers.begin();
    advance (it, 500000);

    for (int i = 0; i < N; i++) {
        int randomNumber = distr(gen);
        numbers[i] = randomNumber;
    }

    //int arr [] = {99, 98, 97, 96, 95};
    //numbers.insert (it, arr, arr + 5);
    numbers.insert(it, {99, 98, 97, 96, 95});

    for (int i = 499990; i < 500010; i++) {
        vector<int>::iterator it = numbers.begin();
        advance (it, i);
        cout << *it << endl;
    }

    cout << "" << endl;
    return 0;
}

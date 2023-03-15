/*
 *
 * Tehtävänanto
 * Tee konsolisovellus, joka arpoo satunnaislukuja miljoona kappaleita ja tallentaa ne STL vectoriin.
 *
 * Alusta Mersenne Twister seuraavasti
 *   std::mt19937 generator{ 42 };
 *   std::uniform_int_distribution<int> distribution{ std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };
 *
 * Poista elementit väliltä 123456-123458.
 *
 * Tulosta vectorin koko ja elementit väliltä 123450-123460.
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

    for (int i = 0; i < N; i++) {
        int randomNumber = distr(gen);
        numbers[i] = randomNumber;
    }

    cout << "" << endl;
    return 0;
}

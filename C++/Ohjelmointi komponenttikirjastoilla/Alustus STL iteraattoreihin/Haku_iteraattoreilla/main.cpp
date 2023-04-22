/*
**
** Tehtävänanto
** Tee konsolisovellus, joka arpoo satunnaislukuja miljoona kappaleita ja tallentaa ne STL vectoriin.
**
** Alusta Mersenne Twister seuraavasti
**   std::mt19937 generator{ 42 };
**   std::uniform_int_distribution<int> distribution{ std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };
**
** Tulosta taulukosta elementit väliltä 123456 - 123460 reunat mukaan lukien. Käytä iteraattoreita.
** Palauta polku GitHub:ssa ja ohjelman tulostus
**
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

    vector<int>::iterator it;
    for (it = numbers.begin() + 123456; it <= numbers.begin() + 123460; it++) {
        cout << *it << endl;
    }

    cout << "" << endl;
    return 0;
}

/*
**
** Tehtävänanto
** Tee konsolisovellus, joka arpoo satunnaislukuja miljoona kappaleita ja tallentaa ne STL vectoriin.
**
** Alusta Mersenne Twister seuraavasti
**   std::mt19937 generator{ 42 };
**   std::uniform_int_distribution<int> distribution{ std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };
**
** Hae pienin ja suurin elementti ja tulosta ne.
**
** Palauta polku GitHub:ssa ja ohjelman tulostus.
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
    int min = 0, max = 0;

    mt19937 gen{42};
    uniform_int_distribution<int> distr{numeric_limits<int>::min(), numeric_limits<int>::max()};

    vector<int> numbers(N);

    for (int i = 0; i < N; i++)
    {
        int randomNumber = distr(gen);
        numbers[i] = randomNumber;
    }

    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
    {
        if (*it < min)
        {
            min = *it;
        }
        if (*it > max)
        {
            max = *it;
        }
    }

    cout << "Pienin elementti on: " << min << endl;
    cout << "Suurin elementti on: " << max << endl;
    cout << "" << endl;
    return 0;
}

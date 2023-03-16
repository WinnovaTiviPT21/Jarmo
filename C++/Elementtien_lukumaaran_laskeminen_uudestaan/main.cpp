/*
 *
 * Tehtävänanto
 * Tee konsolisovellus, joka arpoo satunnaislukuja 10 miljoona kappaletta ja tallentaa ne STL vectoriin.
 *
 * Alusta Mersenne Twister seuraavasti
 *   std::mt19937 generator{ 42 };
 *   std::uniform_int_distribution<int> lottery{ std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };
 *
 * Tällä kertaa järjestä vektori (STL sort) alustamisen jälkeen.
 *
 * Laske kuinka monta seuraavia lukuja on. Käytä hyväksesi lukujen järjestystä. Vihje: tutustu STL:n lower_bound ja upper_bound funktioihin.
 *
 * -1245214370, -164242, 164242, 826750389
 *
 * Lisää koodiin myös ajanotto alla olevan mallin mukaan. Kellota vain elementtien laskeminen.
 *
 *       auto start = std::chrono::steady_clock::now();
 *       ...
 *       auto end = std::chrono::steady_clock::now();
 *       std::cout << "Elapsed time in microseconds: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
 *
 * Palauta GitHub:n polku ja ohjelman tulostus tänne.
 *
*/

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iterator>

using namespace std;

void counter(int x, vector<int> &numbers) { // ilman & merkkiä antaa ajaksi huomattavasti suuremman ajan?
    vector<int>::iterator itLow, itUp;
    itLow = lower_bound (numbers.begin(), numbers.end(), x);
    itUp = upper_bound (numbers.begin(), numbers.end(), x);

    cout << "Lukuja " << x << " loytyi: " << itUp - itLow << " kpl" << endl;
}

int main()
{
    const int N = 1e7;
    int numA = -1245214370, numB = -164242, numC = 164242, numD = 826750389;

    mt19937 gen{42};
    uniform_int_distribution<int> distr{numeric_limits<int>::min(), numeric_limits<int>::max()};

    vector<int> numbers(N);

    for (int i = 0; i < N; i++) {
        int randomNumber = distr(gen);
        numbers[i] = randomNumber;
    }

    sort(numbers.begin(), numbers.end());

    auto start = std::chrono::steady_clock::now();

    /*
    vector<int>::iterator itLow, itUp;
    itLow = lower_bound (numbers.begin(), numbers.end(), -1245214370);
    itUp = upper_bound (numbers.begin(), numbers.end(), -1245214370);
    cout << "Lukuja " << -1245214370 << " loytyi: " << itUp - itLow << " kpl" << endl;

    itLow = lower_bound (numbers.begin(), numbers.end(), -164242);
    itUp = upper_bound (numbers.begin(), numbers.end(), -164242);
    cout << "Lukuja " << -164242 << " loytyi: " << itUp - itLow << " kpl" << endl;

    itLow = lower_bound (numbers.begin(), numbers.end(), 164242);
    itUp = upper_bound (numbers.begin(), numbers.end(), 164242);
    cout << "Lukuja " << 164242 << " loytyi: " << itUp - itLow << " kpl" << endl;

    itLow = lower_bound (numbers.begin(), numbers.end(), 826750389);
    itUp = upper_bound (numbers.begin(), numbers.end(), 826750389);
    cout << "Lukuja " << 826750389 << " loytyi: " << itUp - itLow << " kpl" << endl;
    */
    counter(numA, numbers);
    counter(numB, numbers);
    counter(numC, numbers);
    counter(numD, numbers);

    auto end = std::chrono::steady_clock::now();
    cout << "\nElapsed time in microseconds: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;

    cout << "" << endl;
    return 0;
}

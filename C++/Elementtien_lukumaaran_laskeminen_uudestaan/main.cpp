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

    sort(numbers.begin(), numbers.end());

//    auto start = std::chrono::steady_clock::now();

//    auto end = std::chrono::steady_clock::now();
//    cout << "Elapsed time in microseconds: " << chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "" << endl;
    return 0;
}

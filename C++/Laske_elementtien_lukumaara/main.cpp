/*
**
** Tehtävänanto
**
** Tee konsolisovellus, joka arpoo satunnaislukuja 10 miljoona kappaletta ja tallentaa ne STL multiset:iin.
**
** Alusta Mersenne Twister seuraavasti
**   std::mt19937 generator{ 42 };
**   std::uniform_int_distribution<int> lottery{ std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };
**
** Kuinka monta seuraavia lukuja on ja tulosta vastaus.
**
** -1245214370, -164242, 164242, 826750389
**
** Käytä tällä kertaa STL multiset:in jäsenfunktiota.
**
** Lisää koodiin myös ajanotto tyyliin
**
**       auto start = std::chrono::steady_clock::now();
**       ...
**       auto end = std::chrono::steady_clock::now();
**       std::cout << "Elapsed time in microseconds: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
**
*/

#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;

/*
void counter(int x, multiset<int> &s) {
    set<int>::iterator first, last;
    first = s.lower_bound(x);
    last = s.upper_bound(x);

    cout << "Lukuja " << x << " loytyi: " << distance(first,last) << " kpl" << endl;
}
*/

int main()
{
    const int N = 1e7;
    const int numA = -1245214370, numB = -164242, numC = 164242, numD = 826750389;

    mt19937 gen{42};
    uniform_int_distribution<int> distr{numeric_limits<int>::min(), numeric_limits<int>::max()};

    vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        int randomNumber = distr(gen);
        numbers[i] = randomNumber;
    }

    multiset<int> s;
    for (int i = 0; i < N; i++) {
        s.insert(numbers[i]);
    }

    auto start = std::chrono::steady_clock::now();

    cout << "Luku " << numA << " loytyi: " << s.count(numA) << " kpl." << endl;
    cout << "Luku " << numB << " loytyi: " << s.count(numB) << " kpl." << endl;
    cout << "Luku " << numC << " loytyi: " << s.count(numC) << " kpl." << endl;
    cout << "Luku " << numD << " loytyi: " << s.count(numD) << " kpl." << endl;

    auto end = std::chrono::steady_clock::now();
    cout << "\nElapsed time in microseconds: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;


    cout << "" << endl;
    return 0;
}

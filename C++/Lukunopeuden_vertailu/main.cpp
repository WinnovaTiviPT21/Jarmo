#include <iostream>
#include <random>
#include <vector>
#include <chrono>

using namespace std;

/*
**
** Tehtävänanto
**
** Tee konsolisovellus, joka arpoo satunnaislukuja miljardi kappaletta ja tallentaa ne STL vectoriin. Alusta Mersenne Twister seuraavasti
**
**   std::mt19937 generator{ 42 };
**   std::uniform_int_distribution<int> lottery{ std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };
**
** Laske, kuinka monta positiivista (nollaa suurempaa) lukua, vektorissa on. Tee laskenta kahdella tavalla
**
** metodilla at()
** hakasulkuoperaattorilla
** Lisää koodiin myös ajanotto alla olevan mallin mukaan. Kellota haun elementtien laskeminen.
**
**       auto start = std::chrono::steady_clock::now();
**
**       <tähän väliin koodi, joka laskee lukumäärän>
**
**       auto end = std::chrono::steady_clock::now();
**       std::cout << "Elapsed time in microseconds: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
**
** Mitä huomaat suoritusajassa?
**
*/
int main()
{
    int n = 1e9;

    mt19937 gen{42};
    uniform_int_distribution<int> lottery{numeric_limits<int>::min(), numeric_limits<int>::max()};

    vector<int> numbers(n);
    numbers.resize(n);
    for (int i = 0; i < n; i++) {
        int randomNumber = lottery(gen);
        numbers[i] = randomNumber;
    }

    auto start = chrono::steady_clock::now();

    int count = 0;
    for (int i = 0; i < n; i++) {
        //int temp = numbers.at(i); // aika: 11689 ms
        int temp = numbers[i];      // aika: 7919 ms
        if (temp > 0) {
            count++;
        }
    }

    auto end = chrono::steady_clock::now();
    cout << "Elapsed time in microseconds: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
    cout << "Tulos: " << count << endl; // 499994769

    cout << "" << endl;
    return 0;
}

#include <iostream>
#include <random>
#include <chrono>

using namespace std;

/*
**
** Tehtävänanto
**
** Tee konsolisovellus, joka arpoo satunnaislukuja 10 miljoona kappaletta ja tallentaa ne STL vectoriin.
** Alusta Mersenne Twister seuraavasti:
**
** std::mt19937 generator{ 42 };
** std::uniform_int_distribution<int> lottery{ std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };
**
** Laske kuinka monta seuraavia lukuja on:
** -1245214370, -164242, 164242, 826750389
**
** Älä kuitenkaan käytä STL:n count-funktiota vaan tee oma toteutus.
** Lisää koodiin myös ajanotto alla olevan mallin mukaan. Kellota haun elementtien laskeminen.
**
**      auto start = std::chrono::steady_clock::now();
**
**      <tähän väliin koodi, joka laskee annetun luvun lukumäärän>
**
**      auto end = std::chrono::steady_clock::now();
**      std::cout << "Elapsed time in microseconds: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
**
** Palauta GitHub:n polku ja ohjelman tulostus.
**
*/
int main()
{
    int N = 1e7;

    mt19937 gen{ 42 };
    uniform_int_distribution<int> lottery{ numeric_limits<int>::min(), numeric_limits<int>::max() };

    vector<int> numbers(N);
    numbers.resize(N);

    for (int i = 0; i < N; i++) {
        int randomNumber = lottery(gen);
        numbers[i] = randomNumber;
    }

    auto start = chrono::steady_clock::now();

    int counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0;
    for (int temp : numbers) {
        /*
        **
        ** Kumpi on parempi?
        **
        ** if (temp == -1245214370) {
        **     counter1++;
        ** } else if (temp == -164242) {
        **     counter2++;
        ** } else if (temp == 164242) {
        **     counter3++;
        ** } else if (temp == 826750389) {
        **     counter4++;
        ** }
        **
        */
        if (temp == -1245214370) {
            counter1++;
        }
        if (temp == -164242) {
            counter2++;
        }
        if (temp == 164242) {
            counter3++;
        }
        if (temp == 826750389) {
            counter4++;
        }
    }

    auto end = chrono::steady_clock::now();
    cout << "Elapsed time in microseconds: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
    cout << "" << endl;

    cout << "Lukuja -1245214370 loytyi: " << counter1 << endl;
    cout << "Lukuja -164242     loytyi: " << counter2 << endl;
    cout << "Lukuja  164242     loytyi: " << counter3 << endl;
    cout << "Lukuja  826750389  loytyi: " << counter4 << endl;
    cout << "" << endl;

    cout << "Lukuja loytyi yhteensa: " << counter1 + counter2 + counter3 + counter4 << endl;
    cout << "" << endl;
    return 0;
}

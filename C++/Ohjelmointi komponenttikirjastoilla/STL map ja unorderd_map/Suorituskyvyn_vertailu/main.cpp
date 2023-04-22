/*
 *
 * Vertaa kahden edellisen tehtävän histogrammien laskentaan kulunutta aikaa.
 *
*/

#include <iostream>
#include <random>
#include <vector>
#include <map>
#include <unordered_map>
#include <chrono>

using namespace std;

void orderedMap(vector<int> numbers) {
    map<int, int> histogram;
    for (int x : numbers) {
        histogram[x]++;
    }

    cout << "Luvut, joita on kolme tai enemman:\n";
    for (map<int, int>::iterator it = histogram.begin(); it != histogram.end(); it++) {
        if (it->second >= 3) {
            cout << it->first << ": " << it->second << " kpl\n";
        }
    }
}

void unorderedMap(vector<int> numbers) {
    unordered_map<int, int> histogram;
    for (int x : numbers) {
        histogram[x]++;
    }

    cout << "Luvut, joita on kolme tai enemman:\n";
    for (unordered_map<int, int>::iterator it = histogram.begin(); it != histogram.end(); it++) {
        if (it->second >= 3) {
            cout << it->first << ": " << it->second << " kpl\n";
        }
    }
}

int main()
{
    int n = 1e7;

    mt19937 gen{ 42 };
    uniform_int_distribution<int> distr{ numeric_limits<int>::min(), numeric_limits<int>::max() };

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        int randomNumber = distr(gen);
        numbers[i] = randomNumber;
    }

    auto start = chrono::steady_clock::now();

    //orderedMap(numbers); // Elapsed time in microseconds: 16855
    unorderedMap(numbers); // Elapsed time in microseconds: 8387

    auto end = chrono::steady_clock::now();

    cout << "Elapsed time in microseconds: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;

    cout << "" << endl;
    return 0;
}

#include <iostream>
#include <random>
#include <vector>
#include "search.h"

using namespace std;

void Search::myVect(vector<int> &numbers) {
    mt19937 gen{ 42 };
    uniform_int_distribution<int> distr{ numeric_limits<int>::min(), numeric_limits<int>::max() };

    numbers[N];
    numbers.resize(N);
    for (int i = 0; i < N; i++) {
        int randomNumber = distr(gen);
        numbers[i] = randomNumber;
    }
}

void Search::search(int number, vector<int> &numbers) {
    bool found = false;

    cout << "Indeksit joissa luku " << number << " esiintyy: \n";
    for (int i = 0; i < N; i++) {
        int temp = numbers[i];
        if (temp == number) {
            found = true;
            cout << i << endl;
        }
    }
    if (found == false) {
        cout << "Lukua ei loydy!" << endl;
    }

    cout << "" << endl;
}

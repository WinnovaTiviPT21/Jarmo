#include <iostream>
#include <random>
#include "search.h"

using namespace std;

//void Search::vctr() {
//    mt19937 gen{ 42 };
//    uniform_int_distribution<int> distr{ numeric_limits<int>::min(), numeric_limits<int>::max() };

//    vector<int> numbers(N);
//    numbers.resize(N);
//    for (int i = 0; i < N; i++) {
//        int randomNumber = distr(gen);
//        numbers[i] = randomNumber;
//    }
//}

void Search::search(int number) {
    bool found = false;

    mt19937 gen{ 42 };
    uniform_int_distribution<int> distr{ numeric_limits<int>::min(), numeric_limits<int>::max() };

    vector<int> numbers(N);
    numbers.resize(N);
    for (int i = 0; i < N; i++) {
        int randomNumber = distr(gen);
        numbers[i] = randomNumber;
    }

    cout << "Indeksit joista luku " << number << " loytyy on: \n";
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

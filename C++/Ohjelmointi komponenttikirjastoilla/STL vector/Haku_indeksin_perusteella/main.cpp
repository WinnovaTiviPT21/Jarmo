#include <iostream>
#include <random>

using namespace std;

int main()
{
    mt19937 gen{ 42 };
    uniform_int_distribution<int> distr{ numeric_limits<int>::min(), numeric_limits<int>::max() };

    const int N = 1e6;

    vector<int> numbers(N);
    numbers.resize(N);
    for (int i = 0; i < N; i++) {
        int randomNumber = distr(gen);
        numbers[i] = randomNumber;
    }

    for (int i = 123456; i <= 123460; i++) {
        cout << numbers[i] << endl;
    }

    cout << "" << endl;
    return 0;
}

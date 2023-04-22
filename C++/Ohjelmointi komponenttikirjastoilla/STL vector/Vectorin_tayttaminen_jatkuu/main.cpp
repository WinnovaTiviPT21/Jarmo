#include <iostream>
#include <random>

using namespace std;

int main()
{
    mt19937 gen(42);
    uniform_int_distribution<int> distr;

    const int N = 1e9;

    //vector<int> numbers(1e11);
    vector<int> numbers(N); // Varaa N määrän elementtejä arvolla 0.
    //numbers.resize(N);      // Asettaa kooksi N
    for (int i = 0; i < N; i++) {
        int randomNumber = distr(gen);
        numbers[i] = randomNumber;
    }

    cout << "" << endl;
    return 0;
}

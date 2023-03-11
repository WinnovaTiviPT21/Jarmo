#include <iostream>
#include <random>

using namespace std;

int main()
{
    mt19937 gen(42);
    uniform_int_distribution<int> distr;

    const int N = 1e9;

    vector<int> numbers;
    for (int i = 0; i < N; i++) {
        int randomNumber = distr(gen);
        numbers.push_back(randomNumber);
    }
}

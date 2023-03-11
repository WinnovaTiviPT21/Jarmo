#include <iostream>
#include <random>
#include <search.h>

using namespace std;


int main()
{
    Search mySearch;

//    mt19937 gen{ 42 };
//    uniform_int_distribution<int> distr{ numeric_limits<int>::min(), numeric_limits<int>::max() };

//    vector<int> numbers(mySearch.N);
//    numbers.resize(mySearch.N);
//    for (int i = 0; i < mySearch.N; i++) {
//        int randomNumber = distr(gen);
//        numbers[i] = randomNumber;
//    }

//    mySearch.vctr();

    mySearch.search(-1245214370);
    mySearch.search(122460941);
    mySearch.search(-122460941);
    mySearch.search(1385283091);

    return 0;
}

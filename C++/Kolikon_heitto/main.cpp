#include <iostream>
#include <random>

using namespace std;

int main()
{
    const int nrolls = 10000; // number of experiments
    const int nstars = 95;    // maximum number of stars to distribute

    mt19937 generator{ 42 };
    uniform_int_distribution<int> distribution(0, 1);

    int p[1]={};

    for (int i=0; i<nrolls; ++i) {
        int number = distribution(generator);
        ++p[number];
      }

    cout << "uniform_int_distribution (0,9):" << endl;
      for (int i=0; i<10; ++i)
        cout << i << ": " << string(p[i]*nstars/nrolls,'*') << endl;

    return 0;
}

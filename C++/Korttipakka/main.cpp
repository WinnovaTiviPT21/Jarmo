#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>

using namespace std;

string kortti(int i, int j) {
    string maa;
    string arvo = to_string(i);

    if (j == 1){
        maa = "hertta";
    } else if (j == 2){
        maa = "pata";
    } else if (j == 3){
        maa = "risti";
    } else if (j == 4){
        maa = "ruutu";
    }

    if (i == 1){
        arvo = "assa";
    } else if (i == 11) {
        arvo = "jatka";
    } else if (i == 12){
        arvo = "rouva";
    } else if (i == 13) {
        arvo = "kuningas";
    }

    string kortti = maa + " " + arvo;
    return kortti;
}

int main()
{
    vector<string> pakka;

    for (int j = 1; j <= 4; j++) {
        for (int i = 1; i <= 13; i++) {
            pakka.push_back(kortti(i, j));
        }
    }

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle (pakka.begin(), pakka.end(), default_random_engine(seed));

    for (vector<string>::iterator it = pakka.begin(); it != pakka.end(); it++) {
        cout << *it << endl;
    }

    cout << "" << endl;
    return 0;
}

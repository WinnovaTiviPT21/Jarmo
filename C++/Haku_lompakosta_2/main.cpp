#include <iostream>
#include <map>

using namespace std;

int main()
{
    string s1 = "20 cent";
    string s2 = "50 cent";

    map<string, int> lompakko1 {{"1 cent", 5}, {"2 cent", 3}, {"5 cent", 5}, {"10 cent", 3},
                                {"50 cent", 7}, {"1 e", 5}, {"2 e", 3}, {"5 e", 5},
                                {"10 e", 1}, {"20 e", 5}, {"50 e", 8}, {"100 e", 3}};

    cout << "20 cent on: " << lompakko1[s1] << " kpl" << endl;
    cout << "50 cent on: " << lompakko1[s2] << " kpl" << endl;

    cout << "" << endl;
    return 0;
}

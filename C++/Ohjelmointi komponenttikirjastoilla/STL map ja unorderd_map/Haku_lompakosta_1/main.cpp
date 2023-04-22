#include <iostream>
#include <map>

using namespace std;

int main()
{
    string s1 = "20 cent";
    string s2 = "50 cent";

    map<string, int> lompakko {{"1 cent", 5}, {"2 cent", 3}, {"5 cent", 5}, {"10 cent", 3},
                               {"50 cent", 7}, {"1 e", 5}, {"2 e", 3}, {"5 e", 5},
                               {"10 e", 1}, {"20 e", 5}, {"50 e", 8}, {"100 e", 3}};

    cout << "Element " << s1;
    // if the element is found before the end of the map
    if(lompakko.find(s1) != lompakko.end()) {
        // if the element is present then you can access it using the index
        cout << " : found : " << lompakko.find(s1)->second << " kpl" << endl;
    } else {
        cout << " : Not found" << endl;
    }

    cout << "Element " << s2;
    if(lompakko.find(s2) != lompakko.end()) {
        cout << " : found : " << lompakko.find(s2)->second << " kpl" << endl;
    } else {
        cout << " : Not found" << endl;
    }

    cout << "" << endl;
    return 0;
}

/*
 *
 * Mallinna lompakko STL map:ia käyttäen. Lompakossa on
 *
 *       1 cent 5 kpl
 *       2 cent 3 kpl
 *       5 cent 5 kpl
 *       10 cent 3 kpl
 *       50 cent 7 kpl
 *       1 € 5 kpl
 *       2 € 3 kpl
 *       5 € 5 kpl
 *       10 € 1 kpl
 *       20 € 5 kpl
 *       50 € 8 kpl
 *       100 € 3 kpl
 *
 * Hae ja tulosta lompakosta 20 ja 50 centin kolikkojen lukumäärä. Käytä map:in at metodia.
 *
*/

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

    try {
        cout << "The value of key '20 cent' is: " << lompakko.at(s1) << endl;
    } catch (const out_of_range& oor) {
        cerr << "Out of Range error: " << oor.what() << endl;
    }

    try {
        cout << "The value of key '50 cent' is: " << lompakko.at(s2) << endl;
    } catch (const out_of_range& oor) {
        cerr << "Out of Range error: " << oor.what() << endl;
    }

    cout << "" << endl;
    return 0;
}

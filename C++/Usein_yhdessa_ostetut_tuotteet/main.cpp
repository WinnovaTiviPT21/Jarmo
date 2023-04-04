#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream inf{"Market_Basket_Optimisation.csv"};
    if (!inf)
    {
        cerr << "Uh oh, Market_Basket_Optimisation.csv could not be opened for reading!\n\n";
        return 1;
    }

    multiset<string> things;
    multiset<multiset<string>> baskets;

    /*
    // Ei tulosta kaikkia tietoja, miksi?
    // Loopilla
    while(!inf.eof()){
        string strInput;
        getline(inf, strInput);

        string word = "";
        for (auto x : strInput)
        {
            if (x == ',')
            {
                things.insert(word);
                word = "";
            }
            else {
                word = word + x;
            }
        }
    }
    */

    // Setti
    while(!inf.eof()){
        string strInput;
        getline(inf, strInput);

        stringstream sstr(strInput);
        while(sstr.good())
        {
            string substr;
            getline(sstr, substr, ',');
            things.insert(substr);
        }
        baskets.insert(things);
    }

//    // Vectori
//    vector<string> v;
//    while(!inf.eof()){
//        string strInput;
//        getline(inf, strInput);

//        stringstream sstr(strInput);
//        while(sstr.good())
//        {
//            string substr;
//            getline(sstr, substr, ',');
//            v.push_back(substr);
//        }
//    }

    inf.close();

    // Loopin / Setin tulostus
    for (set<string>::iterator it = things.begin(); it != things.end(); it++) {
        cout << *it << endl;
    }

//    // Vectorin järjestely ja tulostus
//    sort(v.begin(), v.end());
//    for (auto x : v) {
//        cout << x << endl;
//    }

    cout << "" << endl;
    return 0;
}

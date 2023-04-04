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

    set<string> itemList;
    multiset<string> things;
    multiset<multiset<string>> baskets;
    vector<int> supCount;

    // Tavarat ja ostoskorit setteihin
    while(!inf.eof()){
        string strInput;
        multiset<string> temp;
        getline(inf, strInput);

        stringstream sstr(strInput);
        while(sstr.good())
        {
            string substr;
            getline(sstr, substr, ',');
            itemList.insert(substr);
            things.insert(substr);
            temp.insert(substr);
        }
        baskets.insert(temp);
        temp.erase(temp.begin(), temp.end());
    }
    inf.close();

    /*
    for (set<string>::iterator it2 = things.begin(); it2 != things.end(); it2++) {
        if (*it1 == *it2) {
            counter++;
        }
        else {
            //cout << *it1 << ": " << counter << endl;
            supCount.push_back(counter);
            counter = 1;
            it1++;
        }
    }
    */
    for (set<string>::iterator it = itemList.begin(); it != things.end(); it++) {
        if (things.count(*it) < 30) {
            cout << *it << " erased" << endl;
            itemList.erase(it);
        }
        else {
            supCount.push_back(things.count(*it));
        }
    }

    cout << "" << endl;
    return 0;
}

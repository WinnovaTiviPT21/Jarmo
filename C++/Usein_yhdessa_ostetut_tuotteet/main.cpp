#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    set<string> itemList;               // Set (lista) yksittäisistä nimikkeistä

    multiset<string> temp;              // apu set / väli muisti
    multiset<string> things;            // sisältää kaikki ostetut tavarat
    multiset<multiset<string>> baskets; // ostoskoreista ja niiden sisällöstä

    vector<int> supCount;               // Vektori support count

    ifstream inf{"Market_Basket_Optimisation.csv"};
    if (!inf)
    {
        cerr << "Uh oh, Market_Basket_Optimisation.csv could not be opened for reading!\n\n";
        return 1;
    }

    // Luetaan tiedostosta ostoskorit ja ostokset setteihin
    while(!inf.eof()){
        string strInput;
        getline(inf, strInput);

        stringstream sstr(strInput);
        while(sstr.good())
        {
            string substr;
            getline(sstr, substr, ',');
            itemList.insert(substr); // Lajitellaan yksittäiset nimikkeet
            things.insert(substr);   // Lajitellaan kaikki ostetut tavarat
            temp.insert(substr);     // Tallennetaa välimuistiin ostoskoria varten
        }
        baskets.insert(temp);        // Lajitellaan ostoskorit
        temp.erase(temp.begin(), temp.end()); // tyhjennetään "välimuisti"
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
//    for (set<string>::iterator it = itemList.begin(); it != things.end(); it++) {
//        if (things.count(*it) < 30) {
//            cout << *it << " erased" << endl;
//            itemList.erase(it);
//        }
//        else {
//            supCount.push_back(things.count(*it));
//        }
//    }

    // Lasketaan tavaroiden määrä ja tallennetaan vectoriin
    for (set<string>::iterator it = itemList.begin(); it != things.end(); it++) {
            supCount.push_back(things.count(*it));
            cout << *it << ": " << things.count(*it) << endl;
    }


    cout << "" << endl;
    return 0;
}

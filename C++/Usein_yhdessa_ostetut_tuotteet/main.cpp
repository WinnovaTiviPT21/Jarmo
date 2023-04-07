/*
 *
 * Tehtävänanto
 *
 * Tee konsolisovellus, joka tutkii, mitä tuotteita on osettu usein yhdessä.
 * Käytä Apriori-algoritmia (https://www.geeksforgeeks.org/apriori-algorithm/),
 * netistä löytyy kuvauksia algoritmin toiminnasta. Tässä tehtävässä riittää,
 * että käyttää support:ia.
 *
 * Kannattaa aloittaa kombinaatioiden generoinnista. Esimerkiksi miten monella
 * tavalla viidestä tuotteesta saa valittua kaksi tuotetta.
 *
 * Selvitä neljän tuotteen kokoiset ryhmät, joiden support on suurempi kuin 30.
 * Suurempia ryhmiä ei tarvitse selvittää.
 *
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    set<string> list;                       // Set (lista) yksittäisistä nimikkeistä

    multiset<string> temp;                  // temp / apu set / väli muisti
    multiset<string> things;                // sisältää kaikki ostetut tavarat
    multiset<multiset<string>> baskets;     // ostoskoreista ja niiden sisällöstä
    multiset<multiset<string>> supBaskets;  // vertailu kori

    vector<int> thingsCount;                // Vektori support count (turha?)

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
            list.insert(substr);   // Lajitellaan yksittäiset nimikkeet
            things.insert(substr); // Lajitellaan kaikki ostetut tavarat
            temp.insert(substr);   // Tallennetaa välimuistiin ostoskoria varten
        }
        baskets.insert(temp);      // Lajitellaan ostoskorit
        temp.erase(temp.begin(), temp.end()); // tyhjennetään "välimuisti"
    }

    inf.close();

    /*
    // Lasketaan tavaroiden määrä ja tallennetaan vectoriin
    for (set<string>::iterator it = list.begin(); it != list.end(); it++) {
        thingsCount.push_back(things.count(*it));
        cout << *it << ": " << things.count(*it) << endl;
    }
    */
    // Lasketaan tavaroiden määrä, tallennetaan vectoriin ja poistaa listalta kaikki < 30.
    //cout << list.size() << endl;
    for (set<string>::iterator it = things.begin(); it != things.end(); it = things.upper_bound(*it)) {
        if (things.count(*it) < 30) {
            //cout << *it << ": " << "erased" << endl;
            list.erase(*it);
        }
        else {
            thingsCount.push_back(things.count(*it)); // Turha?
        }
    }
    //cout << list.size() << endl;

//    set<string>::iterator it = list.begin();
    //string eka = *list.begin();
//    for (*it; it != list.end();) {

//    for (set<string>::iterator it = ++list.begin(); it != list.end(); it++) {
//        string eka = *list.begin();
//        string toka = *it;
//        cout << eka << endl;
//        cout << toka << endl;
//        temp.insert(eka);
//        temp.insert(toka);
//        supBaskets.insert(temp);
//        temp.erase(temp.begin(), temp.end());
//    }

//    set<string>::iterator it1 = list.begin();
//    while (!list.empty()) {
    for (set<string>::iterator it1 = list.begin(); it1 != list.end(); it1++) {
        string eka = *it1;
        set<string>::iterator it2 = it1;
        //cout << *it << endl;
//        set<string>::iterator it = list.begin();
//        for (set<string>::iterator it = ++list.begin(); it != list.end(); it++) {
        for (it2 = ++it2; it2 != list.end(); it2++) {
            string toka = *it2;
            cout << eka << endl;
            cout << toka << endl;
            temp.insert(eka);
            temp.insert(toka);
            supBaskets.insert(temp);
            temp.erase(temp.begin(), temp.end());
        }
//        it1++;
    }
//    // testi vertailusta
//    for (auto it = baskets.begin(); it != baskets.end(); it++) {
//        if (baskets == baskets2) {
//            cout << "Tööt" << endl;
//        }
//    }

    cout << "" << endl;
    return 0;
}

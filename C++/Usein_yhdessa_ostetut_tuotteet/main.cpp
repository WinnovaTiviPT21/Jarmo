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
 * https://www.geeksforgeeks.org/set-of-vectors-in-c-stl-with-examples/
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
    set<string> list;                     // Set (lista) yksittäisistä nimikkeistä
    set<string> temp;                     // temp / apu set / väli muisti

    multiset<string> things;              // sisältää kaikki ostetut tavarat

    multiset<set<string>> ogBaskets;      // ostoskoreista ja niiden sisällöstä
    multiset<set<string>> compBaskets_2i; // vertailu kori (kahdella itemillä)
    multiset<set<string>> compBaskets_3i; // vertailu kori (kolmella itemillä)

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
            list.insert(substr);              // Lajitellaan yksittäiset nimikkeet
            things.insert(substr);            // Lajitellaan kaikki ostetut tavarat
            temp.insert(substr);              // Tallennetaa välimuistiin ostoskoria varten
        }
        ogBaskets.insert(temp);               // Lajitellaan ostoskorit
        temp.erase(temp.begin(), temp.end()); // tyhjennetään "välimuisti"
    }

    inf.close();

    // Lasketaan tavaroiden määrä ja poistaan listalta kaikki < 30.
    for (set<string>::iterator it = things.begin(); it != things.end(); it = things.upper_bound(*it)) {
        if (things.count(*it) < 30) {
            list.erase(*it);
        }
    }

    // Kombinaatioiden generointi 2:lla ostoksella.
    for (set<string>::iterator it1 = list.begin(); it1 != list.end(); it1++) {
        string eka = *it1;
        set<string>::iterator it2 = it1;

        for (it2 = ++it2; it2 != list.end(); it2++) {
            string toka = *it2;
            temp.insert(eka);
            temp.insert(toka);
            compBaskets_2i.insert(temp);
            temp.erase(temp.begin(), temp.end());
        }
    }

//    // Korien vertailua ja poisto
//    for (auto it1 = ogBaskets.begin(); it1 != ogBaskets.end(); it1++) {
//        for (auto it2 = compBaskets_2i.begin(); it2 != compBaskets_2i.end(); it2++) {
//            if (*it1 == *it2) {
//                if (ogBaskets.count(*it1) < 30) {
//                    it2 = compBaskets_2i.erase(it2);
//                }
//            }
//        }
//    }

    int counter = 0;
    for (auto it1 = compBaskets_2i.begin(); it1 != compBaskets_2i.end(); it1++) {
        const set<string>& ogBasket = *it1;

        for (auto it2 = ogBaskets.begin(); it2 != ogBaskets.end(); it2++) {
            const set<string>& compBasket = *it2;
            int foundProducts = 0;
            for(auto it3 = compBasket.begin(); it3 != compBasket.end(); it3++) {
                foundProducts = foundProducts + ogBasket.count(*it3);
            }
            if (foundProducts == 2) {
                counter++;
            }
        }
    }

//    // Kombinaatioiden generointi 3:lla ostoksella.
//    for (multiset<set<string>>::iterator it1 = compBaskets_2i.begin(); it1 != compBaskets_2i.end(); ++it1) {
//        set<string> basket = *it1;
//        auto it2 = it1;

//        for (++it2; it2 != compBaskets_2i.end(); ++it2) {
//            for (auto item : *it2) {
//                //basket = *it1;
//                basket.insert(item);
//            }
//            compBaskets_3i.insert(basket);
//            basket = *it1;
//        }
//    }

    /*
    for (auto it1 = compBaskets_2i.begin(); it1 != prev(compBaskets_2i.end(), 2); ++it1)
    {
        for (auto it2 = next(it1); it2 != prev(compBaskets_2i.end(), 1); ++it2)
        {
            for (auto it3 = next(it2); it3 != compBaskets_2i.end(); ++it3)
            {
                cout << *it1 << " + " << *it2 << " + " << *it3 << endl;
            }
        }
    }
    */


//    for (auto basket : compBaskets_3i) {
//        for (auto fruit : basket) {
//            cout << fruit << " ";
//        }
//            cout << endl;
//        }

    cout << "" << endl;
    return 0;
}

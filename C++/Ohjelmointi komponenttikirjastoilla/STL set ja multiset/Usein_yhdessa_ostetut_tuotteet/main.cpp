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
    multiset<set<string>> compBaskets;    // vertailu kori (kahdella itemillä)
    multiset<set<string>> multiTemp;
    //multiset<set<string>> compBaskets_3i; // vertailu kori (kolmella itemillä)

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

    // Lasketaan tavaroiden määrä ja poistetaan listalta kaikki < 30.
    for (set<string>::iterator it = things.begin(); it != things.end(); it = things.upper_bound(*it)) {
        if (things.count(*it) < 30) {
            list.erase(*it);
        }
    }

    // Kombinaatioiden generointi 2:lla ostoksella.
    for (set<string>::iterator it1 = list.begin(); it1 != list.end(); it1++) {
        const string& firstItem = *it1;

        for (auto it2 = ++list.begin(); it2 != list.end(); it2++) {
            const string& secondItem = *it2;
            temp.insert(firstItem);
            temp.insert(secondItem);
            compBaskets.insert(temp);
            temp.erase(temp.begin(), temp.end());
        }
    }

    //Listan nollaus?
    list.erase(list.begin(), list.end());

    /*
     *
     * Korien vertailua ja poisto
     *
     * Opettajan esimerkissä oli käytetty vectoria (useampaakin vectoria),
     * koska vectorissa on functio contains, joka tekee asiasta yksinkertaisempaa.
     *
     * Set:iin tulee contains jäsenfuntio vasta C++ 20:ssa ja tämä on 17.
     *
     * Tässä halusin kuitenkin käyttää settiä, koska tämä kuului tehtäviin,
     * joissa nimenomaan piti käyttää settiä.
     *
    */
    for (auto it1 = compBaskets.begin(); it1 != compBaskets.end(); it1++) {
        const set<string>& compBasket = *it1;
        int counter = 0;

        for (auto it2 = ogBaskets.begin(); it2 != ogBaskets.end(); it2++) {
            const set<string>& ogBasket = *it2;
            int foundProducts = 0;

            for(auto it3 = compBasket.begin(); it3 != compBasket.end(); it3++) {
                foundProducts = foundProducts + ogBasket.count(*it3);
            }

            if (foundProducts == 2) {
                counter++;
            }

            if (counter == 30) {
                for (auto it4 = compBasket.begin(); it4 != compBasket.end(); it4++) {
                    list.insert(*it4);
                }

                multiTemp.insert(*it1);
                break;
            }
        }
    }

    compBaskets.erase(compBaskets.begin(), compBaskets.end());

    for (auto it1 = multiTemp.begin(); it1 != multiTemp.end(); it1++) {
        const set<string>& firstBasket = *it1;

        for (auto it2 = ++multiTemp.begin(); it2 != multiTemp.end(); it2++) {
            const set<string>& secondBasket = *it2;
            set<string>::iterator it3 = firstBasket.begin();
            set<string>::iterator it4 = secondBasket.begin();

            if (*it3 == *it4) {
                set<string> compBasket = *it1;
                for (auto it = secondBasket.begin(); it != secondBasket.end(); it++) {
                    compBasket.insert(*it);
                }

                compBaskets.insert(compBasket);
            }
        }


//        if ()
    }

//    // Kombinaatioiden generointi 3:lla ostoksella.
//    for (multiset<set<string>>::iterator it1 = compBaskets.begin(); it1 != compBaskets.end(); ++it1) {
//        set<string> basket = *it1;
//        auto it2 = it1;

//        for (++it2; it2 != compBaskets.end(); ++it2) {
//            for (auto item : *it2) {
//                //basket = *it1;
//                basket.insert(item);
//            }
//            compBaskets_3i.insert(basket);
//            basket = *it1;
//        }
//    }

    /*
    for (auto it1 = compBaskets.begin(); it1 != prev(compBaskets.end(), 2); ++it1)
    {
        for (auto it2 = next(it1); it2 != prev(compBaskets.end(), 1); ++it2)
        {
            for (auto it3 = next(it2); it3 != compBaskets.end(); ++it3)
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

/*
 *
 * Ratkaise oheinen ongelma.
 *
 * Sijoita luvut 1-9 ruudukkoon siten, kolmen luvun summa on 17. Yhteenlaskettavat luvut merkitty punaisella.
 * Kuvassa esimerkki, joka ei ole ongelman ratkaisu.
 *
 * Käy läpi kaikki mahdolliset permutaatiot (brute force) ja tulosta ratkaisuksi kelpaavat järjestykset.
 * Vihje: STL:ssä on funktio next_permutation.
 *
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> luvut = {1,2,3,4,5,6,7,8,9};

    while (next_permutation(luvut.begin(), luvut.end())) {
        if (luvut[0] + luvut[1] + luvut[2] == 17 &&
                luvut[6] + luvut[7] + luvut[8] == 17 &&
                luvut[0] + luvut[3] + luvut[6] == 17 &&
                luvut[2] + luvut[5] + luvut[8] == 17 &&
                luvut[2] + luvut[4] + luvut[6] == 17) {
            cout << luvut[0]<< luvut[1]<< luvut[2] << endl;
            cout << luvut[3]<< luvut[4]<< luvut[5] << endl;
            cout << luvut[6]<< luvut[7]<< luvut[8] << endl;
            cout << "" << endl;
        }
    }

    cout << "" << endl;
    return 0;
}

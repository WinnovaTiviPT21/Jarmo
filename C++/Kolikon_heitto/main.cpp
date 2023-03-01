/*****************
** Kolikon heitto
** Jarmo Vuorinen
** 03.01.2023
*****************/

#include <iostream>
#include <random>

using namespace std;


int main()
{
    // Simuloi satunnaisluvuilla kolikon heittoa (Monte Carlo simulation).
    // Mikä on todennäköisyys saada kymmenen klaavaa peräjälkeen?
    // Tuloksen tarkka arvo on 0.5^10 = 0,0009765625. Kaksi merkitsevää numero oikein riittää.

    const int heitot = 1000000;     // heittojen määrä
    const int tavoite = 10;         // tavoite kuinka monta kertaa peräkkäin
    double perakkaiset_klaavat = 0; // laskee peräkkäiset klaavat
    double tavoite_saavutettu = 0;  // laskee kuinka monta kertaa tavoite saavutettu

    mt19937 generator{ 42 }; // näennäisrandom generaattori jonka seed on 42
    uniform_int_distribution<int> distribution(0, 1); // rajaa luvut 0:n ja 1:n (kruuna ja klaava)

    for (int i = 0; i <= heitot; i++) {
        int tulos = distribution(generator);      // apumuuttuja johon tallennetaan heiton tulos
        if (tulos == 1) {                         // jos tulos on klaava
            perakkaiset_klaavat++;                // lisätään perättäistä klaavojen laskuriin 1
            if (perakkaiset_klaavat == tavoite) { // jos on saatu 10 peräkkäistä klaavaa
                tavoite_saavutettu++;             // lisätään tavoitelaskuriin 1
                perakkaiset_klaavat = 0;          // ja klaavojen laskuri nollataan
            }
        }
        else {                       // jos tulos on kruuna
            perakkaiset_klaavat = 0; // laskuri nollataan
        }
    }

    double todennakoisyys = tavoite_saavutettu / heitot;

    // Antaa tuloksen: 0.000485, se kerrottuna 2:lla on 0,00097
    cout << "Todennakoisyys kymmenen perattaisen klaavan heittamiseksi on: " << todennakoisyys << "\n\n";

    return 0;
}

/*
 *
 * Poista lompakosta 1 ja 2 centin kolikot (map:n erase).
 * Tulosta lompakon arvo ennen poistoa ja poistin jälkeen.
 *
*/

#include <iostream>
#include <map>

using namespace std;

void lompakonArvo(map<string, int> lompakko1, map<double, string> lompakko2) {
    double sum = 0;

    for (map<double, string>::iterator it = lompakko2.begin(); it != lompakko2.end(); it++) {
        try {
            double x = it->first * lompakko1.at(it->second);
            sum = sum + x;
        }
        catch (const out_of_range& oor) {

        }
    }

    cout << sum << " e\n" << endl;
}

void erase(map<string, int> &lompakko, string raha) {
    map<string, int>::iterator it = lompakko.find(raha);
    if (it != lompakko.end()) {
        lompakko.erase(it);
        cout << it->first << " : erased : " << it->second << " pcs\n";
    }
}

int main()
{
    map<string, int> lompakko1 {{"1 cent", 5}, {"2 cent", 3}, {"5 cent", 5}, {"10 cent", 3},
                                {"50 cent", 7}, {"1 e", 5}, {"2 e", 3}, {"5 e", 5},
                                {"10 e", 1}, {"20 e", 5}, {"50 e", 8}, {"100 e", 3}};

    map<double, string> lompakko2 {{0.01, "1 cent"}, {0.02, "2 cent"}, {0.05, "5 cent"}, {0.10, "10 cent"},
                                   {0.50, "50 cent"}, {1.00, "1 e"}, {2.00, "2 e"}, {5.00, "5 e"},
                                   {10.00, "10 e"}, {20.00, "20 e"}, {50.00, "50 e"}, {100.00, "100 e"}};

    cout << "Lompakon arvo ennen poistoa: ";
    lompakonArvo(lompakko1, lompakko2);

    erase(lompakko1, "1 cent");
    erase(lompakko1, "2 cent");

    cout << "\nLompakon arvo poiston jalkeen: ";
    lompakonArvo(lompakko1, lompakko2);

    return 0;
}

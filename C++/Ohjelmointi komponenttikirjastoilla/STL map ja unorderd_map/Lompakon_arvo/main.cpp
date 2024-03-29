#include <iostream>
#include <map>

using namespace std;

int main()
{
    double sum = 0;

    map<string, int> lompakko1 {{"1 cent", 5}, {"2 cent", 3}, {"5 cent", 5}, {"10 cent", 3},
                                {"50 cent", 7}, {"1 e", 5}, {"2 e", 3}, {"5 e", 5},
                                {"10 e", 1}, {"20 e", 5}, {"50 e", 8}, {"100 e", 3}};

    map<double, string> lompakko2 {{0.01, "1 cent"}, {0.02, "2 cent"}, {0.05, "5 cent"}, {0.10, "10 cent"},
                                   {0.50, "50 cent"}, {1.00, "1 e"}, {2.00, "2 e"}, {5.00, "5 e"},
                                   {10.00, "10 e"}, {20.00, "20 e"}, {50.00, "50 e"}, {100.00, "100 e"}};

    for (map<double, string>::iterator it = lompakko2.begin(); it != lompakko2.end(); it++) {
        try {
            double x = it->first * lompakko1.at(it->second);
            sum = sum + x;
        }
        catch (const out_of_range& oor) {
            cerr << "Out of Range error: " << oor.what() << " " << it->second << ": not found" << endl;
        }
    }

    cout << "Lompakon on rahaa: " << sum << " e" << endl;

    cout << "" << endl;
    return 0;
}

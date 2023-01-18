#include <iostream>

using namespace std;

int main()
{
    string line = "";
    int i = 0;

    cout << "Kirjoita koko nimi: ";
    getline(cin, line);
    cout << "Annoit koko nimeksi: ";
    while (i < line.length()){
        cout << line[i] << " ";
        i++;
    }
    cout << "\n";

    return 0;
}

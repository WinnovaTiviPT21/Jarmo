#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    // Tämä vaihe on ok
    ifstream inf{ "test.csv" };

    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        // Print an error and exit
        cerr << "Uh oh, test.csv could not be opened for reading!\n";
        return 1;
    }

    //std::vector<Employee> employees;

    // While there's still stuff left to read
    while (inf)
    {
        // read stuff from the file into a string and print it
        string strInput;
        getline(inf, strInput);
        cout << strInput << '\n';
    }

    return 0;
}

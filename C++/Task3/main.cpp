#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Employee{
public:
    string m_etunimi;
    string m_sukunimi;
    string m_sukupuoli;
};

int main()
{
    ifstream inf{ "test.csv" };

    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        // Print an error and exit
        cerr << "Uh oh, test.csv could not be opened for reading!\n";
        return 1;
    }

    vector<Employee> employees;

    // int counter{0};
    // While there's still stuff left to read
    while (inf)
    {
        // read stuff from the file into a string and print it
        string strInput;
        getline(inf, strInput);
        //cout << strInput << '\n';

        int comma1 = strInput.find(',');
        int comma2 = strInput.find(',', comma1+1);
        int comma4 = strInput.find(',', comma2+3);

        Employee e;
        e.m_etunimi = strInput.substr(0, comma1);
        e.m_sukunimi = strInput.substr(comma1 + 1, comma2 - comma1 - 1);
        e.m_sukupuoli = strInput.substr(comma2 + 1, 1);

        //string sDate;
        //sDate = strInput.substr(comma2 + 3, comma4 - comma2 - 3);
        //e.birthDate() = Date(stoi)

        employees.push_back(e);
    }

    cout << "Tyontekijoiden kokonais maara: " << employees.size() << endl;

    cout << endl;
    return 0;
}

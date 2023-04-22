#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "date.h"
#include "employee.h"

using namespace std;

int main()
{
    int m{0};
    int f{0};

    ifstream inf{"test.csv"}; // .csv = comma-separated values
    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        // Print an error and exit
        cerr << "Uh oh, test.csv could not be opened for reading!\n\n";
        return 1;
    }

    // Dynamic array
    vector<Employee> employees;

    // While there's still stuff left to read
    while (!inf.eof())
    {
        // read stuff from the file into a string and print it
        string strInput;
        getline(inf, strInput);

        int comma1 = strInput.find(',');
        int comma2 = strInput.find(',', comma1+1);
        int comma4 = strInput.find(',', comma2+3);

        Employee e;
        e.etunimi = strInput.substr(0, comma1);
        e.sukunimi = strInput.substr(comma1 + 1, comma2 - comma1 - 1);
        e.sukupuoli = strInput.substr(comma2 + 1, 1);

        // laskee miesten määrän
        if(e.sukupuoli == "M"){
            m = m + 1;
        }
        // laskee naisten määrän
        if(e.sukupuoli == "F"){
            f = f + 1;
        }

        string sDate;
        sDate = strInput.substr(comma2 + 3, comma4 - comma2 - 3);
        e.birthDate = Date(stoi(sDate.substr(8, 2)), stoi(sDate.substr(5, 2)), stoi(sDate.substr(0, 4)));

        sDate = strInput.substr(comma4 + 1, strInput.length() - comma4 - 1);
        e.hiringDate = Date(stoi(sDate.substr(8, 2)), stoi(sDate.substr(5, 2)), stoi(sDate.substr(0, 4)));

        employees.push_back(e);
    }

    Employee oldest = employees[0];
    for(unsigned int i = 0; i < employees.size(); i++){
        Employee e = employees[i];
        if(e.birthDate < oldest.birthDate){
            oldest = e;
        }
    }

    cout << "Tyontekijoita: " << employees.size() << endl;
    cout << "Miehia: " << m << endl;
    cout << "Naisia: " << f << endl;
    cout << "Vanhimman tiedot: " << oldest.etunimi << " " << oldest.sukunimi << ", " << oldest.sukupuoli << ", " << oldest.birthDate.day << "."
         << oldest.birthDate.month << "." << oldest.birthDate.year << ", " << oldest.hiringDate.day << "." << oldest.hiringDate.month << "." << oldest.hiringDate.year << endl;


    cout << "------------------------" << endl;
    return 0;
}

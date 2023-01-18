#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "date.h"

using namespace std;

class Employee{
public:
    string m_etunimi;
    string m_sukunimi;
    string m_sukupuoli;
    string m_birthDate;
};

int main()
{
    int m{0};
    int f{0};

    ifstream inf{"test.csv"};
    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        // Print an error and exit
        cerr << "Uh oh, test.csv could not be opened for reading!\n\n";
        return 1;
    }

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
        e.m_etunimi = strInput.substr(0, comma1);
        e.m_sukunimi = strInput.substr(comma1 + 1, comma2 - comma1 - 1);
        e.m_sukupuoli = strInput.substr(comma2 + 1, 1);
        // laskee miesten määrän
        if(e.m_sukupuoli == "M"){
            m = m + 1;
        }
        // laskee naisten määrän
        if(e.m_sukupuoli == "F"){
            f = f + 1;
        }

//        // ???
//        string bDate;
//        bDate = strInput.substr(comma2 + 3, comma4 - comma2 - 3);
//        e.m_birthDate = Date(stoi(bDate.substr(8, 2), stoi(bDate.substr(5, 6)))); //00.00.0000

//        // ???
//        int minimum = numbers[0];
//        for(unsigned int i = 1; i < numbers.size(); i++){
//            if (numbers[i] < minimum){
//                minimum = numbers[i];
//            }
//        }

//        // ???
//        Date pvm1;
//        Date pvm2;
//        if (pvm1 < pvm2) {}

        employees.push_back(e);
    }

    cout << "Tyontekijoiden kokonais maara: " << employees.size() << endl;
    cout << "Miehia: " << m << endl;
    cout << "Naisia: " << f << endl;

    cout << "------------------------" << endl;
    return 0;
}

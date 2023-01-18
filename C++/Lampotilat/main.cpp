#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream inf{"Pori lentokentta.csv"};
    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        // Print an error and exit
        cerr << "Uh oh, test.csv could not be opened for reading!\n\n";
        return 1;
    }

    // Pitäisi toimia ilman airMin2, mutta koodi menee rikki jos
    // yritän käyttää pelkästään ariMin ja airMin1
    float airMin1, airMin2, airMax1, airMax2;
    int airMinYear, airMinMonth, airMinDay, airMaxYear, airMaxMonth, airMaxDay;
    string firstLine;

    getline(inf, firstLine);
//    int counter{0};
    while(!inf.eof() /*&& inf.good()*/){
        int year, month, day;
        float air, airMin, airMax;

        inf >> year >> month >> day >> air >> airMax >> airMin;

//        counter++;

        // Etsii matalimman lämpätilan ja mittaus pvm
        airMin1 = airMin;
        if(airMin1 < airMin2){
            airMin2 = airMin1;
            airMinYear = year;
            airMinMonth = month;
            airMinDay = day;
        }
        // Etsii korkeimman lämpätilan ja mittaus pvm
        airMax1 = airMax;
        if(airMax1 > airMax2){
            airMax2 = airMax1;
            airMaxYear = year;
            airMaxMonth = month;
            airMaxDay = day;
        }
    }

    cout << "Alin mitattu lampotila: " << airMin2 << endl;
    cout << "Mittaus pvm: " << airMinDay << "." << airMinMonth << "." << airMinYear << endl;
    cout << "----------------------" << endl;
    cout << "Korkein mitattu lampotila: " << airMax2 << endl;
    cout << "Mittaus pvm: " << airMaxDay << "." << airMaxMonth << "." << airMaxYear << endl;

    cout << endl;
    return 0;
}

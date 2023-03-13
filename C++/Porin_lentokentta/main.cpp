#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
**
** Tehtävänanto
**
** Oheisessa tiedostossa on lämpötilamittauksia Porin lentoasemalta. Tällä kertaa talleta mittaukset vector:iin.
** Ohjelman tulee edelleen tulostaa alin ja korkein lämpötila ja päivä, jolloin mittaus on tehty.
**
*/
int main()
{
    ifstream inf{"Pori lentokentta.csv"};
    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        // Print an error and exit
        cerr << "Uh oh, Pori lentokentta.csv could not be opened for reading!\n\n";
        return 1;
    }

    // Pitäisi toimia ilman airMin2, mutta koodi menee rikki jos
    // yritän käyttää pelkästään ariMin ja airMin1
    float airMinDeg, airMaxDeg;
    int airMinYear, airMinMonth, airMinDay, airMaxYear, airMaxMonth, airMaxDay;
    string firstLine;

    getline(inf, firstLine);
    while(!inf.eof()){
        int year, month, day;
        float air, airMin, airMax;

        inf >> year >> month >> day >> air >> airMax >> airMin;

        // Etsii matalimman lämpätilan ja mittaus pvm
        if(airMin < airMinDeg){
            airMinDeg = airMin;
            airMinYear = year;
            airMinMonth = month;
            airMinDay = day;
        }
        // Etsii korkeimman lämpätilan ja mittaus pvm
        if(airMax > airMaxDeg){
            airMaxDeg = airMax;
            airMaxYear = year;
            airMaxMonth = month;
            airMaxDay = day;
        }
    }

    cout << "Alin mitattu lampotila: " << airMinDeg << endl;
    cout << "Mittaus pvm: " << airMinDay << "." << airMinMonth << "." << airMinYear << endl;
    cout << "----------------------" << endl;
    cout << "Korkein mitattu lampotila: " << airMaxDeg << endl;
    cout << "Mittaus pvm: " << airMaxDay << "." << airMaxMonth << "." << airMaxYear << endl;

    cout << "" << endl;
    return 0;
}

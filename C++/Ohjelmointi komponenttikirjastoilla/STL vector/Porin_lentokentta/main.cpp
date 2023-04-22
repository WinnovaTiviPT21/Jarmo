/*
**
** Jarmo Vuorinen
** 13.3.2023
** TiViPT21
**
** Tehtävänanto
**
** Oheisessa tiedostossa on lämpötilamittauksia Porin lentoasemalta. Tällä kertaa talleta mittaukset vector:iin.
** Ohjelman tulee edelleen tulostaa alin ja korkein lämpötila ja päivä, jolloin mittaus on tehty.
**
*/

#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

int main()
{
    int year, month, day, airMinYear, airMinMonth, airMinDay, airMaxYear, airMaxMonth, airMaxDay;
    float air, airMin, airMax, airMinDeg, airMaxDeg;

    vector<tuple<int, int, int, float, float, float>> data;

    ifstream inf{"Pori lentokentta.csv"};
    if (!inf) //if (!inf.is_open())
    {
        cerr << "Uh oh, Pori lentokentta.csv could not be opened for reading!\n\n";
        return 1;
    }

    string firstLine;
    getline(inf, firstLine);
    while(!inf.eof()){

        inf >> year >> month >> day >> air >> airMax >> airMin;

        data.push_back(make_tuple(year, month, day, air, airMax, airMin));
    }

    inf.close();

    for (size_t i = 0; i < data.size(); ++i) {
        year = get<0>(data.at(i));
        month = get<1>(data.at(i));
        day = get<2>(data.at(i));
        airMax = get<4>(data.at(i));
        airMin = get<5>(data.at(i));

        if(airMin < airMinDeg){
            airMinDeg = airMin;
            airMinYear = year;
            airMinMonth = month;
            airMinDay = day;
        }
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

#include <iostream>
#include <random>
#include <vector>
#include "search.h"

using namespace std;

/*
**
** Tehtävänanto
**
** Tee konsolisovellus, joka arpoo satunnaislukuja 10 miljoona kappaleita ja tallentaa ne STL vectoriin.
** Alusta Mersenne Twister seuraavasti:
**
** std::mt19937 generator{ 42 };
** std::uniform_int_distribution<int> distribution{ std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };
**
** Hae seuraavat luvut vektorista ja tulosta kaikki kohdat (indeksi), joissa luku esiintyy.
**
**  -1245214370
**   122460941
**  -122460941
**   1385283091
**
** Jos lukua ei löydy vektorista, tulosta: ei löydy.
**
*/
int main()
{
    Search mySearch;

    vector<int> numbers;

    mySearch.myVect(numbers);

    mySearch.search(-1245214370, numbers);
    mySearch.search(122460941, numbers);
    mySearch.search(-122460941, numbers);
    mySearch.search(1385283091, numbers);

    return 0;
}

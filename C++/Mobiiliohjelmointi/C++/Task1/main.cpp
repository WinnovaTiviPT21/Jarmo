#include <iostream>
#include "io.h"
using namespace std;

int main()
{
    int x = kysymys("Anna luku: ");
    int y = kysymys("Anna toinen luku: ");

    tulostus(x, y);
    return 0;
}

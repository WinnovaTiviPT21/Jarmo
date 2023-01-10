#include <iostream>
using namespace std;

int kysymys(string txt);
void tulostus(int x, int y);

int main()
{
    int x = kysymys("Anna luku: ");
    int y = kysymys("Anna toinen luku: ");

    tulostus(x, y);
    return 0;
}

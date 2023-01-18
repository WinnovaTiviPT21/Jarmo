#include <iostream>
using namespace std;

// Netistä kopioitu
// Function to find string which has
// first character of each word.
string firstLetterWord(string line)
{
    string result = "";

    // Traverse the string.
    bool v = true;
    for (unsigned int i = 0; i < line.length(); i++)
    {
        // If it is space, set v as true.
        if (line[i] == ' '){
            v = true;
        }
        // Else check if v is true or not.
        // If true, copy character in output
        // string and set v as false.
        else if (line[i] != ' ' && v == true)
        {
            result.push_back(line[i]);
            v = false;
        }
    }

    return result;
}

int main()
{
    string line = "";

    cout << "Anna koko nimesi: ";
    getline(cin, line);
    cout << "Nimikirjaimesi ovat: " << firstLetterWord(line) << endl;

    return 0;
}

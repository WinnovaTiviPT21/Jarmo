#ifndef SEARCH_H
#define SEARCH_H

#include <random>
#include <vector>

class Search
{
public:
    int N = 1e7;

    void myVect(std::vector<int> &numbers);
    void search(int number, std::vector<int> &numbers);
};

#endif // SEARCH_H

#ifndef SEARCH_H
#define SEARCH_H

#include <random>
#include <vector>

class Search
{
public:
    int N = 1e7;
    int numA = -1245214370, numB = 122460941, numC = -122460941, numD = 1385283091;

    void myVect(std::vector<int> &numbers);
    void search(int number, std::vector<int> &numbers);
};

#endif // SEARCH_H

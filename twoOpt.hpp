#ifndef TWOOPT_HPP
#define TWOOPT_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>

using std::vector;
using std::string;
using std::cout;
using std::endl;

struct City{
    int id;
    int x;
    int y;
    City(int idIn, int xIn, int yIn){
        id = idIn;
        x = xIn;
        y = yIn;
    }
};

struct Solution{
    int distance;
    vector<City> tour;
    Solution(vector<City>);
    void printSolution();
};

int calcDistance(vector<City>);
int _calcDistanceNode(City*, City*);
void _twoOptSwap(vector<City>&, int, int);
void run(Solution&);
vector<City> readInput(string fileName);

#endif
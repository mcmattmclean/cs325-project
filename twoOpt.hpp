#ifndef TWOOPT_HPP
#define TWOOPT_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <ctime>
#include <climits>

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
    City(){
        id = 0;
        x = 0;
        y = 0;
    }
};

struct Solution{
    int distance;
    vector<City> tour;
    Solution(vector<City>);
    void printSolution();
};

City findClosestNeighbor(City, vector<City>&);
vector<City> nearestNeighbor(vector<City>);
int calcDistance(vector<City>);
int _calcDistanceNode(City, City);
void _twoOptSwap(vector<City>&, int, int);
void twoOpt(Solution&, int);
vector<City> readInput(string fileName);

#endif
#include "twoOpt.hpp"

Solution::Solution(vector<City> tourIn){
    tour = tourIn;
    distance = calcDistance(tour);
}

void Solution::printSolution(){
    cout << "Tour distance: " << distance << endl;
    cout << "Tour path: " << endl;
    for(int i = 0; i < tour.size(); i++){
        cout << tour[i].id << ' ';
    }
    cout << '\n';
}

void printTour(vector<City> cities){
    cout << "Tour path: " << endl;
    for(int i = 0; i < cities.size(); i++){
        cout << cities[i].id << ' ';
    }
    cout << '\n';
}

int _calcDistanceNode(City city1, City city2){
    double x_distance = city1.x - city2.x;
    double y_distance = city1.y - city2.y;
    return int(round(sqrt(x_distance * x_distance + y_distance * y_distance)));
}

int calcDistance(vector<City> tour){
    int dTravelled = 0;
    for(int i = 0; i < tour.size() - 1; i++){
        dTravelled += _calcDistanceNode(tour[i], tour[i+1]);
    }
    dTravelled += _calcDistanceNode(tour[0], tour[tour.size() - 1]);
    return dTravelled;
}


void _twoOptSwap(vector<City>& tour, int i, int k){
    while(k > i){
        City temp = tour[i];
        tour[i] = tour[k];
        tour[k] = temp;
        i++;
        k--;
    }
}

void run(Solution& bestSolution){
    std::cout << "Running 2-Opt...\n";
    bool improve = true;
    while(improve){
        improve = false;
        vector<City> newTour = bestSolution.tour;
        for(int i = 1; i < newTour.size(); i++){
            for(int j = i + 1; j < newTour.size(); j++){
                _twoOptSwap(newTour, i, j);
                int newDistance = calcDistance(newTour);
                if(newDistance < bestSolution.distance){
                    bestSolution.tour = newTour;
                    bestSolution.distance = newDistance;
                    improve = true;
                    i = 0;
                }
                else{
                    newTour = bestSolution.tour;
                }
            }
        }
    }
}

vector<City> readInput(string fileName){
    vector<City> tour;

    std::ifstream inputFile;
    inputFile.open(fileName);
    int id = 0;
    int x = 0;
    int y = 0;
    while(inputFile >> id){
        inputFile >> x >> y;
        // std::cout << id << ' ' << x << ' ' << y << '\n';
        tour.push_back(City(id, x, y));
    }

    inputFile.close();
    return tour;
}


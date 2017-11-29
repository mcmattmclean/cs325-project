#include "twoOpt.hpp"

const int SECONDS_AVAILABLE = 175;

int main(int argc, char* argv[]){
    if(argc != 2){
        cout << "Please enter file name.";
        return -1;
    }

    string fileName = argv[1];

    vector<City> cities = readInput(fileName);

    time_t start = time(0);
    cities = nearestNeighbor(cities);
    time_t used = time(0) - start;
    int timeLeft = SECONDS_AVAILABLE - used;

    Solution mySol = Solution(cities);

    cout << "\nInitial tour:\n";
    mySol.printSolution();

    twoOpt(mySol, timeLeft);

    cout << "\nAfter 2OPT:\n";
    mySol.printSolution();

    cout << "TIME: " << time(0) - start << endl;
    return 0;
}
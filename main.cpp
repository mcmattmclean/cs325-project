#include "twoOpt.hpp"

int main(int argc, char* argv[]){
    if(argc != 2){
        cout << "Please enter file name.";
        return -1;
    }

    string fileName = argv[1];

    vector<City> cities = readInput(fileName);

    Solution mySol = Solution(cities);

    mySol.printSolution();

    run(mySol);

    // _twoOptSwap(mySol.tour, 0, 5);

    mySol.printSolution();


    // TwoOptSolution mySol = TwoOptSolution(cities);

    // mySol.printSolution();

    // mySol.run();

    // mySol.printSolution();

    return 0;
}
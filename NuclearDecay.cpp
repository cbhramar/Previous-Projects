/*
 * File: NuclearDecay.cpp
 * The program simulates nuclear deacy of a given number of atoms and a given decay rate
 */

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// const int INITIAL = 10000;

void initRandomSeed() {
    static bool initialized = false;
    if (!initialized) {
        srand(int(time(NULL)));
        initialized = true;
    }
}

int randomInteger(int low, int high) {
    initRandomSeed();
    double d = rand() / (double(RAND_MAX) + 1);
    double s = d * (double(high) - low + 1);
    return int(floor(low + s));
}

double randomReal(int low, int high) {
    initRandomSeed();
    double d = rand() / (double(RAND_MAX) + 1);
    double s = d * (double(high) - low);
    return low + s;
}

bool randomChance(double p) {
    initRandomSeed();
    return randomReal(0, 1) < p;
}

void setRandomSeed(int seed) {
    initRandomSeed();
    srand(seed);
}

void printDecayPattern(int INITIAL, double decayFraction);
int decayAmount(int n, int year, int INITIAL, double decayFraction);

int main(){
    cout << "How many atoms do you want initially?" << endl;
    int INITIAL;
    cin >> INITIAL;

    double decayFraction;
    cout << "What fraction of atoms remain after a year?" << endl;
    cin >> decayFraction;
    while (decayFraction >= 1 || decayFraction < 0) {
        cout << "The decay fraction must lie between 0 and 1. Please re-enter the fraction: " << endl;
        cin >> decayFraction;
    }

    printDecayPattern(INITIAL, decayFraction);

    return 0;
}

void printDecayPattern(int INITIAL, double decayFraction){
    cout << "There are " << right << setw(5) << INITIAL << " atoms initially \n";
    int n = INITIAL;
    decayAmount(n, 1, INITIAL, decayFraction);
}

int decayAmount(int n, int year, int INITIAL, double decayFraction) {
    int x = 0;
    for (int i = 0; i < n; i++){
        if (randomChance(decayFraction)){
            x++;
        }
    }
    cout << "There are " << right << setw(5) << x << " atoms at the end of year " << setw(2) << year << endl;
    if (x != 0)
        decayAmount(x, year + 1, INITIAL, decayFraction);
    return x;
}

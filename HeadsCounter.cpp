/*
 * File: HeadsCounter.cpp
 * The programs inputs the total number of heads a person would like to appear consecutively; simulates coin flips
 * and returns the number of flips done in order to satisfy the person
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

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

void headsCounter(int n) {
    int hcount = 0;
    int i = 0;
    while (true) {
        if (randomInteger(0, 1) == 1) {
            hcount ++;
            cout << "Heads" << endl;
        }
        else {
            hcount = 0;
            cout << "Tails" << endl;
        }
        i ++;
        if (hcount == n) {
            cout << "It took " << i << " attempts to get " << n  << " consecutive heads. \n";
            break;
        }
    }
}

int main() {
    int n;
    cout << "Enter the total number of heads you would like to appear consecutively: \n";
    cin >> n;
    cout << "Flipping a coin and listing the results: \n";
    headsCounter(n);

    return 0;
}

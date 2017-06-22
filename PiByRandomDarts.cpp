/*
 * File: PiByRandomDarts.cpp
 * Program to find the value of pi by calculating the probability of a dart hitting a circle inside a 
 * square dart board
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// const int TRIALS = 100000;

double piByDarts(int TRIALS);

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

int main() {
    int TRIALS;
    cout << "Enter the amount of trials you want to simulate: " << endl;
    cin >> TRIALS;

    cout << "The estimated value of PI is " << piByDarts(TRIALS) << endl;
    
    return 0;
}

double piByDarts(int TRIALS) {
    int insideCircle = 0;
    double x, y;
    for (int i = 0; i < TRIALS ; ++i) {
        x = randomReal(-1, 1);
        y = randomReal(-1, 1);
        if ((x*x) + (y*y) < 1) {
            insideCircle++;
        }
    }
    double pbf = double(insideCircle)/TRIALS;
    double pi = double(4)*pbf;
    return pi;
}

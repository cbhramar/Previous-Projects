/*
 * File: RandomAlphabetSubstitution.cpp
 * The program takes a file as input and creates another file with all the alphabets substituted by other
 * random alphabets and outputs the result in the terminal
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string alphabet = "abcdefghijklmnopqrstuvwxyz";

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

void randomOutput(ifstream & infile){
    string filename;
    cout << "Enter filename : \n";
    getline(cin, filename);
    infile.open(filename.c_str());
    char ch;
    while (infile.get(ch)) {
        if (isupper(ch)) {
            cout.put(ALPHABET[randomInteger(0, 25)]);
        }
        else if (islower(ch)) {
            cout.put(alphabet[randomInteger(0, 25)]);
        }
        else {
            cout.put(ch);
        }
    }
}

int main() {
    ifstream infile;
    randomOutput(infile);
    return 0;
}




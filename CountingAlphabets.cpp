/*
 * File: CountingAlphabets.cpp
 * The program asks for a file as input and outputs the count of every alphabet that has appeared in the file
 * The code was an exercise in the Stanford CS106B Reader
 */

#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <vector>

using namespace std;

static const int COLUMNS = 7;

string promptUserForFile(ifstream & infile, string prompt );

int main() {
    vector<int> lettercounts(26);

    ifstream infile;
    promptUserForFile(infile, "Input File: ");

    char ch;
    while (infile.get(ch)) {
        if (isalpha(ch)){
            lettercounts[toupper(ch) - 'A']++;
        }
    }
    infile.close();

    for (char ch = 'A'; ch <= 'Z'; ch++){
        cout << setw(COLUMNS) << ch  << " -> " << lettercounts[ch - 'A'] << endl;
    }

    return 0;
}

string promptUserForFile(ifstream & infile, string prompt ) {
    while(true) {
        cout << prompt;
        string filename;
        getline(cin, filename);

        infile.open(filename.c_str());
        if (!infile.fail()) 
            return filename;

        infile.clear();

        cout << "Unable to open that file. Try again :" << endl;

        if (prompt == "") 
            prompt = "Input File : ";
    }
}

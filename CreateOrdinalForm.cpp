/*
 * File: CreateOrdinalForm.cpp
 * Tihs program takes in a number input and outputs the given number in form of a rank.
 * For example: 1 becomes 1st, 1239 becomes 1239th
 */

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>

using namespace std;

string createOrdinalForm(string n);

int main() {
    cout << "Enter the number you want ordinalized : \n";
    string n;
    cin >> n;
    cout << "Ordinal form of the number is : \n" << createOrdinalForm(n) << endl;
    return 0;
}

string createOrdinalForm(string n) {
    string odf = n;
    if (n.length() == 1) {
        if (n == "1") {
            string st = "st";
            odf += st;
        }
        else if (n[0] == '2') {
            odf += "nd";
        }
        else if (n[0] == '3') {
            odf += "rd";
        }
        else {
            odf += "th";
        }
    }
    else if (n.length() > 1) {
        if (n[n.length() - 2] == '1') {
            odf += "th";
        }
        else if (n[n.length() - 1] == '1') {
            odf += "st";
        }
        else if (n[n.length() - 1] == '2') {
            odf += "nd";
        }
        else if (n[n.length() - 1] == '3') {
            odf += "rd";
        }
        else {
            odf += "th";
        }
    }
    return odf;
}

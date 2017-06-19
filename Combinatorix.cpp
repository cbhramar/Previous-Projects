/*
 * File: Combinatorix.cpp
 * The program returns the value C(n, k) given n and k using the Pascal's triangle method 
 */

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int combinatorix(int n, int k);

int main() {
    int n;
    int k;
    cout << "Enter n and k:" << endl;
    cin >> n >> k;
    cout << "C(" << n << ", " << k << ") = " << combinatorix(n, k) << endl;

    return 0;
}

int combinatorix(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    else if (k > n) {
        return -1;
    }
    else {
        return combinatorix(n - 1, k) + combinatorix(n - 1, k - 1);
    }
}

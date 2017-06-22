/*
 * File: IsMeasurable.cpp
 * The code takes an array of weights as input and outputs whether a target weight can be measured by the 
 * given array of weights
 * The program runs on an infinite loop and breaks if you enter -1 as your target weight
 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isMeasurable(int target, vector<int> & weights);

int main() {
    vector<int> weights;
    while (true) {
        int n;
        cout << "How many weights do you have?" << endl;
        cin >> n;
        weights.resize(n);
        cout << "Please enter the value of your " << n << " weights here: " << endl; 
        for (int i = 0; i < n; ++i) {
            cin >> weights[i];
        }
        cout << "How much do you want to measure?" << endl;
        int target;
        cin >> target;
        if (target == -1) break;
        if (isMeasurable(target, weights)) cout << "This weight is indeed measurable" << endl;
        else cout << "This is not measurable, sorry :(" << endl;
    }

    return 0;
}

bool isMeasurable(int target, vector<int> & weights) {
    if (weights.size() == 1) {
        return target == weights[0];
    }
    else {
        vector<int> restweights(weights.size() - 1);
        int singleElement = weights[0];
        for (int i = 1; i < weights.size(); i++) {
            restweights[i - 1] = weights[i];
        }
        return isMeasurable(target, restweights) || isMeasurable(target + singleElement, restweights) || isMeasurable(target - singleElement, restweights) || target == singleElement;
    }
}

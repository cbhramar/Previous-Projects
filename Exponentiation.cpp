#include <iostream>

using namespace std;

long exp(int a, int b);

int main(int argc, char const *argv[]) {
    cout << "Enter base followed by exponent: " << endl;
	int a, b;
	cin >> a >> b;
	cout << a << "^" << b << " = ";
	cout << exp(a, b) << endl;
	return 0;
}

long exp(int a, int b) {
	int y = b;
	long r = 1;

	while (y != 0) {
		if (y%2 != 0) {
			r = r*a;
			--y;
		}
		else {
			a = a*a;
			y = y/2;
		}
	}
	return r;
}

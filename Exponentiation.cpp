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
	long r = a;
	while (!(y < 2 )) {
		if (y%2 == 0) {
			r = r*r;
			y = y/2;
		}
		else {
			r = r*a;
			--y;
		}
	}
	return r;
}

#include <iostream>

using namespace std;

int year;

int main() {

	int e, s, m;
	cin >> e >> s >> m;

	year = 420 * e * s + 285 * e * m + 532 * m * s;

	cout << year % (e * s * m) << endl;

	return 0;

}
#include <iostream>
#include <math.h>

using namespace std;

int min(int x, int y) { return (x < y) ? x : y; }

int main() {

	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int min1 = min(w - x, h - y);
	int min2 = min(x, y);

	cout << min(min1, min2) << endl;

	return 0;

}
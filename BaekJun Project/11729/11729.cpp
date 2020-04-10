#include <iostream>
#include <math.h>

using namespace std;

void hanoi(int n, int a, int b, int c) {

	if (n == 0) return;

	hanoi(n-1, a, c, b);

	cout << a << " " << c << "\n";

	hanoi(n-1, b, a, c);

}

int main() {

	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n;
	cin >> n;

	int count = 1;
	for (int i = 0; i < n; i++) count *= 2;

	cout << count - 1 << "\n";

	hanoi(n, 1, 2, 3);

	return 0;

}
#include <iostream>

using namespace std;

int year;

int main() {

	int e, s, m;
	cin >> e >> s >> m;

	while (++year) if (!((year - e) % 15) && !((year - s) % 28) && !((year - m) % 19)) break;

	cout << year;

	return 0;

}
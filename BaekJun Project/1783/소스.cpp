#include <bits/stdc++.h>

using namespace std;

int main() {

	int y, x; cin >> y >> x;

	if (y == 1) cout << "1";
	else if (y == 2) cout << min(4, (x + 1) / 2);
	else {
		if (x < 5) cout << x;
		else if(x >= 7) cout << (x - 5) + 3;
		else cout << "4";
	}

	return 0;

}
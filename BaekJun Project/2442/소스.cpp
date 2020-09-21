#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; cin >> n;

	string str;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n - i - 1; j++)
			str += " ";

		for (int j = 0; j < 2 * (i + 1) - 1; j++)
			str += "*";

		str += "\n";

	}

	cout << str;

	return 0;

}
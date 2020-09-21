#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; cin >> n;

	string str;

	for (int i = n - 1; i >= 0; i--) {

		for (int j = 0; j < n - i; j++)
			str += "*";

		for (int j = 0; j < 2 * i; j++)
			str += " ";

		for (int j = 0; j < n - i; j++)
			str += "*";

		str += "\n";

	}

	for (int i = 1; i < n; i++) {

		for (int j = 0; j < n - i; j++)
			str += "*";

		for (int j = 0; j < 2 * i; j++)
			str += " ";

		for (int j = 0; j < n - i; j++)
			str += "*";

		str += "\n";

	}

	cout << str;

	return 0;

}
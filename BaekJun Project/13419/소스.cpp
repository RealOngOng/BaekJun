#include <bits/stdc++.h>

using namespace std;

int main() {

	int tc; cin >> tc;

	while (tc--) {

		string str; cin >> str;
		int n = str.length();

		string a, b;

		if (n % 2 == 1) {

			str += str;
			n *= 2;

		}

		for (int i = 0; i < n; i += 2) a += str[i], b += str[i + 1];

		cout << a << "\n" << b << "\n";

	}

	return 0;

}
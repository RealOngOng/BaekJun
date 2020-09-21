#include <bits/stdc++.h>

using namespace std;

int main() {

	int tc; cin >> tc;

	while (tc--) {

		int n; cin >> n;

		string str;
		cin >> str;

		for (int i = 0; i < n - 1; i++) {

			char c; cin >> c;
			
			if (str[0] < c) str += c;
			else str = c + str;

		}

		cout << str << "\n";

	}

	return 0;

}
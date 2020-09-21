#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	while (true) {

		string str; cin >> str;

		if (str == "0") break;

		while (str.length() > 1) {

			int sum = 0;

			for (char c : str)
				sum += c - '0';

			str = to_string(sum);

		}

		cout << str << "\n";

	}

	return 0;

}
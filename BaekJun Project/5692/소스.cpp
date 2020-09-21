#include <bits/stdc++.h>

using namespace std;

int fact[6];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	fact[0] = 1;
	for (int i = 1; i <= 5; i++)
		fact[i] = fact[i - 1] * i;

	while (true) {

		string str; cin >> str;

		if (str == "0") break;

		int sum = 0;

		for (int i = 0; i < str.length(); i++) {

			int f = str.length() - i;
			sum += (str[i] - '0') * fact[f];

		}

		cout << sum << "\n";

	}

	return 0;

}
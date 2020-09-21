#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	while (true) {

		string str; cin >> str;

		if (str == "0") break;

		int len = str.length() + 1;

		for (char c : str) {

			if (c == '0') len += 4;
			else if (c == '1') len += 2;
			else len += 3;

		}

		printf("%d\n", len);

	}

	return 0;

}
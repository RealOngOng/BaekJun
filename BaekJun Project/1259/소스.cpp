#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	while (true) {

		string str; cin >> str;

		if (str == "0") break;

		bool ok = true;

		int len = str.length();

		for (int i = 0; i < len / 2; i++)
			if (str[i] != str[len - i - 1]) ok = false;

		printf("%s\n", (ok) ? "yes" : "no");

	}

	return 0;

}
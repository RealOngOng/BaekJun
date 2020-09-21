#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	long long num = 0;

	int n; cin >> n;

	while (n--) {

		long long arg;
		string cmd; cin >> cmd;

		if (cmd == "add") {

			cin >> arg;
			num |= (1 << arg);

		}
		else if (cmd == "remove") {

			cin >> arg;
			num &= ~(1 << arg);

		}
		else if (cmd == "check") {

			cin >> arg;
			cout << (bool)(num & (1 << arg)) << "\n";

		}
		else if (cmd == "toggle") {

			cin >> arg;
			if ((num & (1 << arg))) num &= ~(1 << arg);
			else num |= (1 << arg);

		}
		else if (cmd == "all") num = (1 << 22) - 1;
		else if (cmd == "empty") num = 0;

	}

	return 0;

}
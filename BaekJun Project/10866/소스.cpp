#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;

	deque<int> d;

	while (n--) {

		string cmd; cin >> cmd;

		if (cmd == "push_front") {

			int arg; cin >> arg;

			d.push_front(arg);

		}
		else if (cmd == "push_back") {

			int arg; cin >> arg;

			d.push_back(arg);

		}
		else if (cmd == "pop_front") {

			if (d.size() > 0) {

				cout << d.front() << "\n";
				d.pop_front();

			}
			else
				cout << "-1\n";

		}
		else if (cmd == "pop_back") {

			if (d.size() > 0) {

				cout << d.back() << "\n";
				d.pop_back();

			}
			else
				cout << "-1\n";

		}
		else if (cmd == "size") cout << d.size() << "\n";
		else if (cmd == "empty") cout << d.empty() << "\n";
		else if (cmd == "front") {

			if (d.size() > 0) cout << d.front() << "\n";
			else cout << "-1\n"; 

		}
		else if (cmd == "back") {

			if (d.size() > 0) cout << d.back() << "\n";
			else cout << "-1\n";

		}

	}

	return 0;

}
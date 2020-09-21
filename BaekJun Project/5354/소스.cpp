#include <bits/stdc++.h>

using namespace std;

int arr[10];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;

	string result;

	while (t--) {

		int n; cin >> n;

		if (n == 1) {

			result += "#\n\n";
			continue;

		}

		for (int i = 0; i < n; i++) result += "#";

		result += "\n";

		for (int i = 0; i < n - 2; i++) {

			for (int j = 0; j < n; j++) {

				if (j == 0 || j == n - 1) result += "#";
				else result += "J";

			}

			result += "\n";

		}

		for (int i = 0; i < n; i++) result += "#";

		result += "\n\n";

	}

	cout << result;

	return 0;

}
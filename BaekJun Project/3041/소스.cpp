#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	string input;

	for (int i = 0; i < 4; i++) {

		string temp; cin >> temp;
		input += temp;

	}

	int ans = 0;

	int o = 0;

	for (int i = 0; i < 16; i++) {

		if (input[i] == '.') continue;

		int idx = find(input.begin(), input.end(), 'A' + o) - input.begin();

		int x = o % 4, y = o / 4,
			nx = idx % 4, ny = idx / 4;

		ans += abs(nx - x) + abs(ny - y);

		o++;

	}

	cout << ans << "\n";

	return 0;

}
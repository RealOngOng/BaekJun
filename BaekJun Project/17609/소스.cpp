#include <bits/stdc++.h>

using namespace std;

string str;

int solve(int lo, int hi, int used) {

	if (used >= 2) return 2;

	if (lo >= hi) return used;

	if (str[lo] == str[hi]) return solve(lo + 1, hi - 1, used);

	return min(solve(lo + 1, hi, used + 1), solve(lo, hi - 1, used + 1));

}

int main() {

	int tc; cin >> tc;

	while (tc--) {

		cin >> str;

		int cnt = 0;

		int lo = 0, hi = str.length() - 1;

		cout << solve(lo, hi, 0) << "\n";

	}

	return 0;

}
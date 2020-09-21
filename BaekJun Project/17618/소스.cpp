#include <bits/stdc++.h>

using namespace std;

int solve(int num) {

	int ans = 0;

	while (num > 0) {

		ans += num % 10;
		num /= 10;

	}

	return ans;

}

int main() {

	int n; cin >> n;

	int ans = 0;

	for (int i = 1; i <= n; i++)
		if (i % solve(i) == 0) ans++;

	cout << ans;

	return 0;

}
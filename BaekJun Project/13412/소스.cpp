#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {

	if (b == 0) return a;
	else return gcd(b, a % b);

}

int solve(int n) {

	int ans = 0;

	for (int i = 1; i * i <= n; i++) {

		if (n % i == 0) {

			int a = i, b = n / i;
			if (gcd(a, b) == 1) ans++;

		}

	}

	return ans;

}

int main() {

	int tc; cin >> tc;

	while (tc--) {

		int n; cin >> n;

		cout << solve(n) << "\n";

	}

	return 0;

}
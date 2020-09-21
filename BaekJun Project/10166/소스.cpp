#include <bits/stdc++.h>

using namespace std;

bool visit[2001][2001];

int gcd(int a, int b) {

	if (b == 0) return a;
	return gcd(b, a % b);

}

int main() {

	int d1, d2; cin >> d1 >> d2;

	int ans = 0;

	for (int i = d1; i <= d2; i++) {

		for (int w = 1; w <= i; w++) {

			int a = i, b = w;

			int g = gcd(a, b);
			a /= g, b /= g;

			if (!visit[a][b])
				visit[a][b] = true, ans++;

		}

	}

	cout << ans;

	return 0;

}
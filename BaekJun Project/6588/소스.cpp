#include <bits/stdc++.h>

using namespace std;

vector<int> GetPrime(int x) {

	vector<bool> visit(x + 1);
	vector<int> ans;

	for (int i = 2; i <= x; i++) {
		if (visit[i]) continue;
		ans.push_back(i);
		for (int j = i; j <= x; j += i)
			visit[j] = true;
	}

	return ans;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	vector<int> prime = GetPrime(1000000);

	function<bool(int)> isPrime = [&](int x) -> bool {
		return (x == *lower_bound(prime.begin(), prime.end(), x));
	};

	while (true) {

		int n; cin >> n;
		if (n == 0) break;

		int a = -1, b = -1;

		for (int w : prime) {
			if (w >= n) break;
			int p = n - w;
			if (isPrime(p)) {

				a = w, b = p;
				break;

			}
		}

		if (a != -1)
			cout << n << " = " << a << " + " << b << "\n";
		else
			cout << "Goldbach's conjecture is wrong.\n";

	}

	return 0;

}
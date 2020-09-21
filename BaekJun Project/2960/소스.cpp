#include <bits/stdc++.h>

using namespace std;

vector<int> GetPrime(int n) {

	vector<int> ans;
	vector<bool> visit(n + 1);

	for (int i = 2; i <= n; i++) {

		if (visit[i]) continue;
		ans.push_back(i);

		for (int j = i; j <= n; j += i)
			visit[j] = true;

	}

	return ans;

}

int main() {

	int n, k; cin >> n >> k;

	int cnt = 1;

	vector<int> prime = GetPrime(n);
	vector<bool> visit(1001);

	for (int w : prime) {

		for (int i = w; i <= n; i += w) {

			if (visit[i]) continue;
			visit[i] = true;

			if (cnt++ == k) {

				cout << i;
				return 0;

			}

		}

	}

	return 0;

}
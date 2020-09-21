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

	int tc; cin >> tc;

	vector<int> prime = GetPrime(1500000);

	while (tc--) {

		int n; cin >> n;
	
		int idx = lower_bound(prime.begin(), prime.end(), n) - prime.begin();

		if (prime[idx] == n) cout << "0\n";
		else cout << prime[idx] - prime[idx - 1] << "\n";

	}

	return 0;

}
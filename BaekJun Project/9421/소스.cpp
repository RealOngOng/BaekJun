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

int f(int x) {

	string str = to_string(x);
	int ans = 0;
	for (char c : str)
		ans += (c - '0') * (c - '0');

	return ans;

}

bool sg(int x) {

	vector<bool> visit(501);

	for (int i = f(x); ; i = f(i)) {
		if (i == 1) return true;
		if (visit[i]) return false;
		visit[i] = true;
	}

	return true;

}

int main() {

	vector<int> prime = GetPrime(1000000);

	int n; cin >> n;
	int idx = lower_bound(prime.begin(), prime.end(), n) - prime.begin();
	if(prime[idx] != n) 
		idx--;

	for (int i = 0; i <= idx; i++)
		if (sg(prime[i]))
			cout << prime[i] << "\n";

	return 0;

}
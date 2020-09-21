#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> vec[21];

int main() {

	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);

	int n, k; cin >> n >> k;

	for (int i = 0; i < n; i++) {

		string name; cin >> name;

		int len = name.length();

		vec[len].push_back(i + 1);

	}

	ll result = 0;

	for (int i = 0; i < 21; i++) {

		sort(vec[i].begin(), vec[i].end());

		for (int j = 0; j < vec[i].size(); j++) {

			ll idx = upper_bound(vec[i].begin() + j, vec[i].end(), vec[i][j] + k) - (vec[i].begin() + j);
			result += (idx - 1);

		}

	}
	
	cout << result << "\n";

	return 0;

}
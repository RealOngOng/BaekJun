#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;

int n, m;
vector<int> arr;

int GetMax(vector<int>& vec) {

	auto p = minmax_element(vec.begin(), vec.end());
	return *p.second - *p.first;

}

int solve(int mid) {

	vector<int> vec;
	int cnt = 1;

	for (int w : arr) {

		vec.push_back(w);
		int v = GetMax(vec);

		if (v > mid) {

			vec.clear();
			cnt++;
			vec.push_back(w);

		}

	}

	return cnt <= m;

}

int main() {

	cin >> n >> m;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int lo = 0, hi = 5000 * 10000;
	int ans = 0x3f3f3f3f;

	while (lo <= hi) {

		int mid = (lo + hi) / 2;

		if (!solve(mid)) lo = mid + 1;
		else {

			ans = min(ans, mid);
			hi = mid - 1;

		}

	}

	cout << ans;

	return 0;

}
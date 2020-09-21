#include <bits/stdc++.h>

using namespace std;

typedef pair<string, int> pi;
map<string, int> order;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k; cin >> k >> n;

	vector<pi> arr;

	for (int i = 0; i < n; i++) {

		string str; cin >> str;

		order[str] = i;

	}

	for (auto itr = order.begin(); itr != order.end(); itr++)
		arr.push_back({itr->first, itr->second});

	sort(arr.begin(), arr.end(), [](const pi& p1, const pi& p2) -> bool {return p1.second < p2.second; });

	int len = min(k, (int)arr.size());

	for (int i = 0; i < len; i++)
		cout << arr[i].first << "\n";

	return 0;

}
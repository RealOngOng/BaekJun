#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, m; cin >> n >> m;

	vector<int> arr(m);

	for (int i = 1; i <= m; i++) {

		string str = to_string(n * i);
		reverse(str.begin(), str.end());

		arr.push_back(atoi(str.c_str()));

	}

	sort(arr.begin(), arr.end(), greater<int>());

	cout << arr[0];

	return 0;

}
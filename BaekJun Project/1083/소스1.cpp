#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, s; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> s;

	for (int i = 0; i < n; i++) {

		if (s == 0) break;

		auto itr = arr.begin() + i;
		int idx = max_element(itr,
			(i + s + 1 <= n) ? (itr + s + 1) : (arr.end())) - arr.begin();

		int v = arr[idx];
		arr.erase(arr.begin() + idx);
		arr.insert(arr.begin() + i, v);

		//cout << v << "\n";
		//for (int w : arr)
		//	cout << w << " ";
		//cout << "\n";

		s -= idx - i;

	}

	for (int w : arr)
		cout << w << " ";

	return 0;

}
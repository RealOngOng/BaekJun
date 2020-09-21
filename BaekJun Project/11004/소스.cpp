#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k; cin >> n >> k;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) cin >> arr[i];

	nth_element(arr.begin(), arr.begin() + k - 1, arr.end());

	cout << arr[k - 1];

	return 0;

}
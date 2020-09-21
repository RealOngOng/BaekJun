#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	vector<int> arr(n * n);
	for (int i = 0; i < n * n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end(), greater<int>());
	cout << arr[n - 1];

	return 0;

}
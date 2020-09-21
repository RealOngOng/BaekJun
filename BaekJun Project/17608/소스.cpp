#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	int ans = 0;
	int top = 0;

	for (int i = n - 1; i >= 0; i--) {

		if (top < arr[i])
			top = arr[i], ans++;

	}

	cout << ans;

	return 0;
	
}
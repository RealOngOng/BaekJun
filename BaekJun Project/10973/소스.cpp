#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; cin >> n;
	vector<int> arr(n);

	bool flag = true;

	for (int i = 0; i < n; i++) cin >> arr[i];

	if (!prev_permutation(arr.begin(), arr.end())) cout << "-1";
	else
		for (int w : arr)
			cout << w << " ";

	return 0;

}
#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) arr[i] = i + 1;

	do {
		for (int w : arr)
			cout << w << " ";
		cout << "\n";
	} while (next_permutation(arr.begin(), arr.end()));

	return 0;

}
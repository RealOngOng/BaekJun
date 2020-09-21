#include <bits/stdc++.h>

using namespace std;

int main() {

	vector<int> arr(3);
	for (int i = 0; i < 3; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	string str; cin >> str;
	for (char c : str)
		cout << arr[c - 'A'] << " ";

	return 0;

}
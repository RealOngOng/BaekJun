#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int main() {

	int n, k; cin >> n >> k;

	for (int i = 1; i <= n; i++) arr.push_back(i);

	vector<int> result;

	k--;

	int idx = 0;

	while (true) {

		idx += k;
		idx %= arr.size();

		result.push_back(arr[idx]);
		arr.erase(arr.begin() + idx);

		if (arr.size() == 0) break;

	}

	string str = "<";

	for (int i = 0; i < result.size(); i++) {

		str += to_string(result[i]);
		if (i != result.size() - 1)str += ", ";

	}

	str += ">";

	cout << str;

	return 0;

}
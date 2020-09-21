#include <bits/stdc++.h>

using namespace std;

int main() {

	string str; cin >> str;
	vector<string> arr;

	for (int i = 0; i < str.length(); i++)
		arr.push_back(str.substr(i, str.length() - i));

	sort(arr.begin(), arr.end());
	for (string str : arr)
		cout << str << "\n";

	return 0;

}
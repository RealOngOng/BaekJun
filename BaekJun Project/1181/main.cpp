#include <bits/stdc++.h>

using namespace std;

vector<string> arr;

bool isFront(string str1, string str2) {

	bool ok = false;

	for (int i = 0; i < str1.length(); i++) {

		if (str1[i] == str2[i]) continue;

		ok = str1[i] < str2[i];
		break;

	}

	return ok;

}

int main() {

	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		string str; cin >> str;
		arr.push_back(str);

	}

	sort(arr.begin(), arr.end(),
		 [](const string& str1, const string& str2) -> bool {

		if (str1.length() != str2.length()) return str1.length() < str2.length();
		return isFront(str1, str2);

	});

	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	for (string s : arr) cout << s << "\n";

	return 0;

}
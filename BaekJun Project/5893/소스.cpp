#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);

	string str; cin >> str;

	long long dec = strtol(str.c_str(), NULL, 2);
	dec *= 17;

	string result;

	while (dec) {

		result += (dec % 2 + '0');
		dec /= 2;

	}

	reverse(result.begin(), result.end());

	cout << result;

	return 0;

}
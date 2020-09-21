#include <bits/stdc++.h>

using namespace std;

string prefix[8] = { "", "1", "10", "11", "100", "101", "110", "111" };
string suffix[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	string str; cin >> str;

	if (str == "0" && str.length() == 1) {

		cout << 0;
		return 0;

	}

	string result;
	result += prefix[str[0] - '0'];

	for (int i = 1; i < str.length(); i++)
		result += suffix[str[i] - '0'];

	cout << result;

	return 0;

}
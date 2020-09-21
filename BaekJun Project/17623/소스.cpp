#include <bits/stdc++.h>

using namespace std;

string dp[1001];

string MinStr(string str1, string str2) {

	if (str1.length() < str2.length()) return str1;
	if (str1.length() > str2.length()) return str2;

	if (str1 < str2) return str1;

	return str2;

}

char dc[7] = { ' ', '(', ')', '{', '}', '[', ']' };

string Tobracket(string str) {

	for (int i = 0; i < str.length(); i++)
		str[i] = dc[str[i] - '0'];

	return str;

}

int main() {

	dp[1] = "12";
	dp[2] = "34";
	dp[3] = "56";

	for (int i = 4; i <= 1000; i++) {

		string &ret = dp[i];

		ret = dp[1] + dp[i - 1];

		for (int j = 2; j < i; j++) 
			ret = MinStr(ret, dp[j] + dp[i - j]);

		if (i % 5 == 0) ret = MinStr(ret, "5" + dp[i / 5] + "6");
		if (i % 3 == 0) ret = MinStr(ret, "3" + dp[i / 3] + "4");
		if (i % 2 == 0) ret = MinStr(ret, "1" + dp[i / 2] + "2");

	}

	int tc; cin >> tc;

	while (tc--) {

		int n; cin >> n;
		cout << Tobracket(dp[n]) << "\n";

	}

	return 0;

}
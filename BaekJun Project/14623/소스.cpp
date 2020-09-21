#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	string str1, str2; cin >> str1 >> str2;

	long long num1 = strtol(str1.c_str(), NULL, 2);
	long long num2 = strtol(str2.c_str(), NULL, 2);

	long long sum = num1 * num2;

	string result;
	while (sum) {

		result += (sum % 2) + '0';
		sum /= 2;

	}

	reverse(result.begin(), result.end());

	cout << result;

	return 0;

}
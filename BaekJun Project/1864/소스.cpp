#include <bits/stdc++.h>

using namespace std;

int pw8[11];

int main() {

	for (int i = 0; i <= 10; i++) pw8[i] = pow(8, i);

	map<char, int> m;

	m.insert({'-', 0});m.insert({'\\', 1});m.insert({'(', 2});
	m.insert({'@', 3});m.insert({'?', 4});m.insert({'>', 5});
	m.insert({'&', 6});m.insert({'%', 7});m.insert({'/', -1});

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	while (true) {

		string str; cin >> str;

		if (str == "#") break;

		int result = 0;

		for (int i = 0; i < str.length(); i++)
			result += m[str[i]] * pw8[str.length() - i - 1];

		printf("%d\n", result);

	}

	return 0;

}
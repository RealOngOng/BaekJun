#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	string str; cin >> str;

	int n = str.length();

	vector<int> ch[26];

	for (int i = 0; i < 26; i++)
		ch[i].resize(n + 1);

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 26; j++)
			ch[j][i] = ch[j][i - 1] + (str[i - 1] == 'a' + j);

	int m; cin >> m;

	while (m--) {

		char a; int b, c; cin >> a >> b >> c;

		b++, c++;

		cout << ch[a - 'a'][c] - ch[a - 'a'][b - 1] << "\n";

	}


	return 0;

}
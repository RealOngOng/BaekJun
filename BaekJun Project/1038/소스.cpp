#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; cin >> n;

	if (n >= 1023) {

		cout << "-1\n";
		return 0;

	}

	int cnt = 0;

	queue<string> q;

	for (int i = 0; i <= 9; i++)
		q.push(to_string(i));

	while (true) {

		string str = q.front(); q.pop();
		int top = str[str.length() - 1] - '0';

		if (cnt == n) {

			cout << str;
			break;

		}

		cnt++;

		for (int i = 0; i < top; i++)
			q.push(str + to_string(i));

	}

	return 0;

}
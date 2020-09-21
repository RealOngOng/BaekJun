#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

	int tc; cin >> tc;

	while (tc--) {

		ll a, b, c;
		char o1, o2;

		cin >> a >> o1 >> b >> o2 >> c;

		ll ans = 0;

		if (o1 == '+') ans = a + b;
		else if (o1 == '-') ans = a - b;
		else if (o1 == '*') ans = a * b;
		else if (o1 == '/') ans = a / b;

		if (ans == c) cout << "correct\n";
		else cout << "wrong answer\n";

	}

	return 0;

}
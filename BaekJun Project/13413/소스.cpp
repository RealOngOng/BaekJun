#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tc; cin >> tc;
	
	while (tc--) {

		int n; cin >> n;
		string a, b; cin >> a >> b;

		int aw = 0, ab = 0;
		int bw = 0, bb = 0;
		int cnt = 0;
		int no = 0;

		for (int i = 0; i < n; i++) {

			if (a[i] == 'W') aw++;
			else ab++;

			if (b[i] == 'W') bw++;
			else bb++;

			if (a[i] != b[i]) no++;

		}

		cnt = (abs(aw - bw) + abs(ab - bb)) / 2;
		no -= cnt;
		cnt += no / 2;

		cout << cnt << '\n';

	}

	return 0;
	
}
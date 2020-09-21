#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, k; cin >> n >> k;

	string input;
	for (int i = 0; i < n; i++) {

		int a; cin >> a;
		input += a + '0';

	}

	string str_ans;
	int ans = 0;

	for (int i = 1; i <= n; i++)
		str_ans += i + '0';

	ans = atoi(str_ans.c_str());

	queue<pi> q; set<int> visit;

	q.push({atoi(input.c_str()), 0});

	int count = -1;

	while (!q.empty()) {

		pi top = q.front(); q.pop();

		if (top.first == ans) {

			count = top.second;
			break;

		}

		for (int i = 0; i <= n - k; i++) {

			string rs = to_string(top.first);
			reverse(rs.begin() + i, rs.begin() + i + k);

			int num = atoi(rs.c_str());

			if (visit.find(num) != visit.end()) continue;

			visit.insert(num);
			q.push({num, top.second + 1});

		}

	}

	cout << count << "\n";

	return 0;

}
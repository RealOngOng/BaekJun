#include <bits/stdc++.h>

using namespace std;

typedef pair<string, int> pi;

int main() {

	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);

	string n; cin >> n;
	int m = n.length(), k; cin >> k;

	queue<pi> q; vector<int> result;

	q.push({n, 0});

	while (!q.empty()) {

		set<int> visit;
		int size = q.size();

		for (int w = 0; w < size; w++) {

			pi top = q.front(); q.pop();

			if (top.second == k) {

				result.push_back(atoi(top.first.c_str()));
				continue;

			}

			for (int i = 0; i < m - 1; i++) {

				for (int j = i+1; j < m; j++) {

					if (i == 0 && top.first[j] == '0') continue;

					string str = string(top.first);
					swap(str[i], str[j]);

					int num = atoi(str.c_str());

					if (visit.find(num) == visit.end()) {

						q.push({ str, top.second + 1 });
						visit.insert(num);

					}

				}

			}

		}

	}

	int cnt = -1e9;

	for (int i : result) cnt = max(cnt, i);

	if (cnt == -1e9) printf("-1\n");
	else printf("%d\n", cnt);

	return 0;

}
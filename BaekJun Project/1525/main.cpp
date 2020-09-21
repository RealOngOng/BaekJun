#include <bits/stdc++.h>

using namespace std;

typedef pair<string, int> pi;

int dx[4] = { -1, 1, -3, 3 };

set<int> visit;

bool isOut(int num) { return (num < 0 || num >= 9); }

int main() {

	string answer = "123456780";
	string str;

	for (int i = 0; i < 9; i++) {

		int d; scanf("%d", &d);
		str += (d + '0');

	}

	queue<pi> q;

	q.push({str, 0});

	int cnt = 1e9;

	while (!q.empty()) {

		pi top = q.front(); q.pop();

		if (!top.first.compare(answer)) {

			cnt = min(cnt, top.second);
			break;

		}

		int zero = 0;
		for (int i = 0; i < 9; i++) if (top.first[i] == '0') { zero = i; break; }

		for (int i = 0; i < 4; i++) {

			int idx = zero + dx[i];

			if (i < 2)
				if (idx / 3 != zero / 3) continue;

			if (isOut(idx)) continue;

			string tempStr = string(top.first);
			swap(tempStr[zero], tempStr[idx]);

			int num = atoi(tempStr.c_str());

			if (visit.find(num) == visit.end()) {

				visit.insert(num);
				q.push({tempStr, top.second + 1});

			}

		}

	}

	if (cnt == 1e9) printf("-1\n");
	else printf("%d\n", cnt);

	return 0;

}
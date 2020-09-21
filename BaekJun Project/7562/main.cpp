#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> pii;

int dx[8] = {2, 2, -2, -2, 1, -1, 1, -1};
int dy[8] = {1, -1, 1, -1, 2, 2, -2, -2};

int n;
pi start, dist;

bool visit[301][301];

bool isOut(pi pos) { return (pos.first < 0 || pos.second < 0 || pos.first >= n || pos.second >= n); }

int main() {

	int t; scanf("%d", &t);

	while (t--) {

		scanf("%d", &n);
		scanf("%d %d %d %d", &start.first, &start.second, &dist.first, &dist.second);

		queue<pii> q;

		q.push({ start, 0 });

		visit[start.first][start.second] = true;

		while (!q.empty()) {

			pii top = q.front(); q.pop();

			if (top.first == dist) {

				printf("%d\n", top.second);
				break;

			}

			for (int i = 0; i < 8; i++) {

				pi dir = { top.first.first + dx[i], top.first.second + dy[i] };

				if (isOut(dir) || visit[dir.first][dir.second]) continue;

				visit[dir.first][dir.second] = true;
				q.push({ dir, top.second + 1 });

			}

		}

		memset(visit, false, sizeof(visit));

	}

	return 0;
	
}
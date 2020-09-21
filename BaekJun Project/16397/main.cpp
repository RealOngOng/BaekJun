#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int n, t, g;

bool visit[100001];

int B(int num) {

	num *= 2;

	string str = to_string(num);

	str[0] = (str[0] - '0') - 1 + '0';

	return atoi(str.c_str());

}

int main() {

	scanf("%d %d %d", &n, &t, &g);

	queue<pi> q;

	q.push({n, 0});
	visit[n] = true;

	int cnt = 1e9;

	while (!q.empty()) {

		pi top = q.front(); q.pop();

		if (top.first == g)
			cnt = min(cnt, top.second);

		if (top.first + 1 < 100000) 
			if (!visit[top.first + 1]) {

				visit[top.first + 1] = true;
				q.push({ top.first + 1, top.second + 1 });

			}

		if (top.first * 2 < 100000) {

			int b = B(top.first);

			if (b < 100000)
				if (!visit[b]) {

					visit[b] = true;
					q.push({ b, top.second + 1 });

				}

		}

	}

	if (cnt > t) printf("ANG\n");
	else printf("%d\n", cnt);

	return 0;

}
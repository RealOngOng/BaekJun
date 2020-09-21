#include <bits/stdc++.h>

using namespace std;

bool visit[100001], finished[100001];

int arr[100001];

int result = 0;

void dfs(int i) {

	visit[i] = true;

	int next = arr[i];

	if (visit[next]) {

		if (!finished[next]) {

			for (int w = next; w != i; w = arr[w]) result++;
			result++;

		}

	}
	else dfs(next);

	finished[i] = true;

}

int main() {

	int t; scanf("%d", &t);

	while (t--) {

		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);

		for (int i = 1; i <= n; i++)if(!visit[i]) dfs(i);

		printf("%d\n", n - result);

		result = 0;
		memset(visit, false, sizeof(visit));
		memset(finished, false, sizeof(finished));

	}

	return 0;

}
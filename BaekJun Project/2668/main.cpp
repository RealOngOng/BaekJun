#include <bits/stdc++.h>

using namespace std;

bool visit[100001], finished[100001];

int arr[100001];
vector<int> order;

int m = 0;

void dfs(int i) {

	visit[i] = true;

	int next = arr[i];

	if (visit[next]) {

		if (!finished[next]) {

			order.push_back(i);

			for (int w = next; w != i; w = arr[w]) order.push_back(w);

		}

	}
	else dfs(next);

	finished[i] = true;

}

int main() {

	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);

	for (int i = 1; i <= n; i++)if (!visit[i]) dfs(i);

	printf("%d\n", order.size());

	sort(order.begin(), order.end());

	for (int i : order) printf("%d\n", i);

	return 0;

}
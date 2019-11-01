#include <iostream>

using namespace std;

#define MAX 1000001

int graph[MAX];

int findParent(int x) {

	int parent = graph[x];

	if (x == parent) return x;

	return graph[x] = findParent(parent);

}

void merge(int x, int y) {

	x = findParent(x); y = findParent(y);

	if (x != y) graph[y] = x;

}

int main() {

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++) graph[i] = i;

	int a, b;
	for (int i = 0; i < m; i++) {

		bool type = false;
		cin >> type >> a >> b;

		if (!type) merge(a, b);
		else cout << ((findParent(a) == findParent(b)) ? "YES" : "NO") << "\n";

	}

	return 0;

}
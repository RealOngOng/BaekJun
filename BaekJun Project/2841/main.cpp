#include <bits/stdc++.h>

using namespace std;

stack<int> pret[7];

int main() {

	ios::sync_with_stdio(false);
	cout.tie(NULL), cin.tie(NULL);

	int n, p; std::cin >> n >> p;

	int result = 0;

	for (int i = 0; i < n; i++) {

		int a, b; std::cin >> a >> b;

		while (!pret[a].empty() && pret[a].top() > b) pret[a].pop(), result++;

		if (pret[a].empty() || pret[a].top() < b) pret[a].push(b), result++;

	}

	cout << result << "\n";

	return 0;

}
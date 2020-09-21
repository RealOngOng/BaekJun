#include <bits/stdc++.h>

using namespace std;

int main() {

	queue<int> q;

	int n; scanf("%d", &n);

	if (n == 1) { printf("1\n"); return 0; }

	for (int i = 1; i <= n; i++) q.push(i); 

	while (true) {

		q.pop();

		if (q.size() == 1) { printf("%d\n", q.front()); break; }

		int temp = q.front();
		q.pop();

		q.push(temp);

	}

	return 0;

}
#include <bits/stdc++.h>

using namespace std;

struct cmp {
	bool operator()(int a, int b) { return a > b; }
};

int main() {

	int n; cin >> n;
	
	priority_queue<int, vector<int>, cmp> pq;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		pq.push(a);
	}

	int ans = 0;

	while (pq.size() > 1) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		pq.push(a + b);
		ans += a + b;
	}

	cout << ans;

	return 0;

}
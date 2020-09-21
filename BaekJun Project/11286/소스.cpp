#include <bits/stdc++.h>

using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) != abs(b))return abs(a) > abs(b);
		return a > b;
 	}
};

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;

	priority_queue<int, vector<int>, cmp> pq;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a == 0) {
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}else
			pq.push(a);
	}

	return 0;

}
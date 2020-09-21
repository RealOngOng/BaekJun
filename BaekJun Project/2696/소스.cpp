#include <bits/stdc++.h>

using namespace std;

struct cmp {
	bool operator()(int a, int b) { return a > b; }
};

int main() {

	int tc; cin >> tc;

	while (tc--) {

		int n; cin >> n;
		vector<int> arr(n + 1);
		for (int i = 1; i <= n; i++) cin >> arr[i];

		vector<int> ans;

		int mid = arr[1];
		priority_queue<int> maxq;
		priority_queue<int, vector<int>, cmp> minq;

		ans.push_back(mid);

		for (int i = 2; i <= n; i++) {

			if (mid > arr[i]) maxq.push(arr[i]);
			else minq.push(arr[i]);

			if (i % 2) {
				if (minq.size() < maxq.size())
					minq.push(mid);
				else 
					maxq.push(mid);

				if (minq.size() >= maxq.size()) {
					mid = minq.top();
					minq.pop();
				}
				else {
					mid = maxq.top();
					maxq.pop();
				}

				ans.push_back(mid);
			}

		}

		cout << ans.size() << "\n";
		for (int w : ans)
			cout << w << " ";
		cout << "\n";

	}

	return 0;

}
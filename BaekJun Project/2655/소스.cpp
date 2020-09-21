#include <bits/stdc++.h>

using namespace std;

int dp[101];

typedef pair<int, int> pi;
struct Block {

	int under, h, weight, idx;

};

int n;
vector<Block> block;
int choice[101];

int ans = 0;

int solve(int pos) {

	int &ret = dp[pos];

	if (ret != -1) return ret;

	ret = block[pos].h;

	for (int i = pos + 1; i < n; i++)
		if (block[i].under < block[pos].under) {

			int v = solve(i) + block[pos].h;
			if (v > ret) {

				ret = v;
				choice[pos] = i;

			}

		}

	return ret;

}

int main() {

	memset(dp, -1, sizeof(dp));
	memset(choice, -1, sizeof(choice));

	cin >> n;

	block.resize(n);
	for (int i = 0; i < n; i++) {

		cin >> block[i].under >> block[i].h >> block[i].weight;
		block[i].idx = i;

	}

	sort(block.begin(), block.end(), 
		 [](const Block& b1, const Block& b2) -> bool {
		return b1.weight > b2.weight;
	});

	for (int i = 0; i < n; i++)
		solve(i);

	int now = 0, m = 0;
	for (int i = 0; i < n; i++) {

		if (dp[i] > m) {

			m = dp[i];
			now = i;

		}

	}

	vector<int> order;

	while (choice[now] != -1) {

		order.push_back(block[now].idx);
		now = choice[now];

	}
	order.push_back(block[now].idx);

	reverse(order.begin(), order.end());

	cout << order.size() << "\n";

	for (int w : order)
		cout << w + 1 << "\n";

	return 0;

}
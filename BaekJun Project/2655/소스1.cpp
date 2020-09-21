//#include <bits/stdc++.h>
//
//using namespace std;
//
//int dp[101];
//
//typedef pair<int, int> pi;
//struct Block {
//
//	int under, h, weight;
//
//};
//
//int n;
//vector<Block> block;
//vector<pi> order;
//
//int ans = 0;
//
//int solve(int pos) {
//
//	if (pos == n) return 0;
//
//	int &ret = dp[pos];
//
//	if (ret != -1) return ret;
//
//	ret = block[pos].h;
//
//	for (int i = pos + 1; i < n; i++)
//		if (block[i].weight < block[pos].weight)
//			ret = max(ret, solve(i) + block[pos].h);
//
//	order.push_back({ ret, pos });
//
//	return ret;
//
//}
//
//int main() {
//
//	memset(dp, -1, sizeof(dp));
//
//	cin >> n;
//
//	block.resize(n);
//	for (int i = 0; i < n; i++)
//		cin >> block[i].under >> block[i].h >> block[i].weight;
//
//	sort(block.begin(), block.end(),
//		 [](const Block& b1, const Block& b2) -> bool {
//		return b1.under > b2.under;
//	});
//
//	for (int i = 0; i < n; i++)
//		solve(i);
//
//	sort(order.begin(), order.end(), greater<pi>());
//
//	int top = order[0].first;
//
//	stack<int> stk;
//
//	for (pi p : order) {
//
//		if (p.first == top) {
//
//			top -= block[p.second].h;
//			stk.push(p.second);
//
//		}
//
//	}
//
//	cout << stk.size() << "\n";
//
//	while (!stk.empty())
//		cout << stk.top() + 1 << "\n", stk.pop();
//
//	return 0;
//
//}
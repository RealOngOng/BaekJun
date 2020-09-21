#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;
vector<bool> visit(13 * 200000 + 2);

void dfs(int pos, int num) {

	if (pos >= n) {

		if (num > 0)
			visit[num] = true;
		return;

	}

	dfs(pos + 1, num);
	dfs(pos + 1, num + arr[pos]);
	dfs(pos + 1, num - arr[pos]);

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	arr.resize(n);

	int cnt = 0;
	for (int i = 0; i < n; i++) cin >> arr[i], cnt += arr[i];

	dfs(0, 0);

	int ans = 0;
	for (int i = 1; i <= cnt; i++)
		if (!visit[i]) ans++;

	cout << ans;

	return 0;

}
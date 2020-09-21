#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	set<int> pos;
	map<int, int> idx;
	vector<pi> query;
	for (int i = 1; i <= n; i++)
	{
		int a, b; cin >> a >> b;
		pos.insert(a);
		pos.insert(b);
		query.push_back({ a, b });
	}

	int num = 0;
	for (int w : pos)
		idx[w] = num++;

	num = 0;
	vector<int> arr(pos.size());
	for (pi p : query)
	{
		int start = idx[p.first], end = idx[p.second];
		for (int i = start; i <= end; i++)
			arr[i] = num;
		num++;
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	cout << arr.size();

	return 0;
}
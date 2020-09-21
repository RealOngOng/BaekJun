#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	map<int, int> map, idx;
	vector<int> query;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		map[a] = i;
		query.push_back(a);
	}

	vector<int> arr;
	int num = 0;
	for (pair<int, int> p : map)
	{
		arr.push_back(p.second);
		idx[p.first] = num++;
	}

	int ans = 0;
	bitset<51> visit;

	for (int w : query)
	{
		int now = idx[w];
		if (visit[now]) continue;
		for (int i = now - 1; i >= 0; i--)
		{
			if (arr[i] > arr[i + 1])
				visit[i] = true;
			else
				break;
		}

		for (int i = now + 1; i < arr.size(); i++)
		{
			if (arr[i - 1] < arr[i])
				visit[i] = true;
			else
				break;
		}
		ans++;
	}
	
	cout << ans;

	return 0;
}
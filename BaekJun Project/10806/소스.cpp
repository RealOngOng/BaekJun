#include <iostream>
#include <utility>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 100000;

int V, E, dfsn[MAX + 1];
vector<int> adj[MAX + 1];
// ������  
set<pii> ans;
int cnt = 1;
int DFS(int curr, int justbefore)
{
	dfsn[curr] = cnt;
	cnt++;
	// �ö� �� �ִ� �ִ� dfsn  
	int ret = dfsn[curr];
	for (auto child : adj[curr])
	{
		// �ٷ� �������� �� ���� ���ƺ��� �ʴ´�. 
		if (child == justbefore) continue;
		if (dfsn[child])
		{
			ret = min(ret, dfsn[child]);
			continue;
		}
		int prev = DFS(child, curr);
		// justbefore �� ���� ���� ���� ���� ������ prev = dfsn[curr] �� ��� cycle �� ����� 
		if (prev > dfsn[curr])
		{
			int a = min(curr, child);
			int b = max(curr, child);
			if (!ans.count(pii(a, b)))
				ans.insert(pii(a, b));
		}
		ret = min(ret, prev);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> V >> E;
	if (V == 1)
	{
		cout << 0 << '\n';
		return 0;
	}
	for (int i = 0; i < E; ++i)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// root �� justbefore �� 0���� ���� 
	for (int i = 1; i <= V; ++i)
		if (dfsn[i] == 0) DFS(i, 0);

	cout << ans.size() << '\n';
	for (auto x : ans)
		cout << x.first << ' ' << x.second << '\n';

	return 0;
}
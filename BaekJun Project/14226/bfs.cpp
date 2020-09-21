#include <bits/stdc++.h>

using namespace std;

struct Data
{
	int num, cnt, copy;
};

struct cmp
{
	bool operator()(const Data& d1, const Data& d2)
	{
		return d1.cnt > d2.cnt;
	}
};

bool visit[2002][2002];

int main()
{
	int n; cin >> n;
	queue<Data> q;

	q.push({1, 0, 0});
	visit[1][0] = true;
	while (!q.empty())
	{
		Data top = q.front(); q.pop();

		if (top.num == n)
		{
			cout << top.cnt;
			break;
		}

		if (top.num > 2000) continue;

		if (top.num != 1)
			if (!visit[top.num - 1][top.copy])
			{
				visit[top.num - 1][top.copy] = true;
				q.push({ top.num - 1, top.cnt + 1, top.copy });
			}

		if (top.copy > 0 && top.num + top.copy <= 2000)
			if (!visit[top.num + top.copy][top.copy])
			{
				visit[top.num + top.copy][top.copy] = true;
				q.push({ top.num + top.copy, top.cnt + 1, top.copy });
			}

		if (!visit[top.num][top.num])
		{
			visit[top.num][top.num] = true;
			q.push({ top.num, top.cnt + 1, top.num });
		}
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef struct Line
{
	int to, cost;
};

typedef struct Q
{
	int pos, cost;
};

//i번째 도시까지 가는데 최소값
int dst[1001];

//간선
vector<Line> V[1001];

struct cmp
{
	bool operator()(const Q& q1, const Q& q2)
	{
		return q1.cost > q2.cost;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dst, 0x3f3f3f3f, sizeof(dst));

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{

		int from, to, cost; cin >> from >> to >> cost;
		V[from].push_back({to, cost});

	}
	int a, b; cin >> a >> b;

	priority_queue<Q, vector<Q>, cmp> pq;
	pq.push({a, 0});
	while (!pq.empty())
	{
		Q top = pq.top(); pq.pop();
		if (top.pos == b)
		{
			cout << top.cost;
			break;
		}
		for (Line w : V[top.pos])
		{
			if (dst[w.to] > top.cost + w.cost)
			{
				dst[w.to] = top.cost + w.cost;
				pq.push({w.to, top.cost + w.cost});
			}
		}
	}

	return 0;

}
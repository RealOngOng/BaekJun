#include <bits/stdc++.h>

using namespace std;

struct Line
{
	int to, cost;
};
struct Q
{
	int pos, cost;
};
struct cmp
{
	bool operator()(const Q& q1, const Q& q2)
	{
		return q1.cost > q2.cost;
	}
};
int dst[1001];
int order[1001];
vector<Line> V[1001];

int main()
{
	memset(dst, 0x3f3f3f3f, sizeof(dst));
	memset(order, -1, sizeof(order));

	int n, m; cin >> n >> m;
	while (m--)
	{
		int a, b, c; cin >> a >> b >> c;
		V[a].push_back({ b, c });
	}
	int s, e; cin >> s >> e;

	priority_queue<Q, vector<Q>, cmp> pq;
	pq.push({s, 0});

	int ans = 0;
	while (!pq.empty())
	{
		Q top = pq.top(); pq.pop();

		if (top.pos == e)
		{
			ans = top.cost;
			break;
		}

		for (Line w : V[top.pos])
		{
			if (dst[w.to] > top.cost + w.cost)
			{
				dst[w.to] = top.cost + w.cost;
				order[w.to] = top.pos;
				pq.push({w.to, top.cost + w.cost});
			}
		}
	}

	order[s] = -1;
	stack<int> stk;
	
	int top = e;
	while (true)
	{
		stk.push(top);
		top = order[top];
		if (top == -1) break;
	}

	cout << ans << "\n";
	cout << stk.size() << "\n";
	while (!stk.empty())
	{
		cout << stk.top() << " ";
		stk.pop();
	}
	return 0;
}
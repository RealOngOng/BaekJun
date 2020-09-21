#include <bits/stdc++.h>

using namespace std;

struct Vector2
{
	double x, y;
	Vector2 operator+(const Vector2 v)
	{
		return { x + v.x, y + v.y };
	}
	Vector2 operator-(const Vector2 v)
	{
		return { x - v.x, y - v.y };
	}
	Vector2 operator*(double v)
	{
		return { x * v, y * v };
	}
};
struct Line
{
	int to;
	double cost;
};
struct Q
{
	int pos;
	double cost;
};
struct cmp
{
	bool operator()(const Q& q1, const Q& q2)
	{
		return q1.cost > q2.cost;
	}
};

double distance(Vector2 v1, Vector2 v2)
{
	double dx = v1.x - v2.x;
	double dy = v1.y - v2.y;
	return sqrt(dx * dx + dy * dy);
}
Vector2 normal(Vector2 from, Vector2 to)
{
	Vector2 dir = to - from;
	double dst = distance({0, 0}, dir);
	return { dir.x / dst, dir.y / dst };
}

double dst[105];

int main()
{
	fill(dst, dst + 105, 2 * 1e9);

	Vector2 start, end;
	cin >> start.x >> start.y;
	cin >> end.x >> end.y;

	int n; cin >> n;
	vector<Vector2> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i].x >> arr[i].y;

	vector<Line> V[105];

	arr.push_back(start);
	arr.push_back(end);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + 2; j++)
		{
			if (i == j) continue;
			
			Vector2 nor = normal(arr[i], arr[j]) * 50.0;

			Vector2 to = arr[i] + nor;
			double time = distance(to, arr[j]) / 5.0;
			
			V[i].push_back({j, 2.0 + time});

		}
	}

	for (int i = n; i < n + 2; i++)
	{
		for (int j = 0; j < n + 2; j++)
		{
			if (i == j) continue;
			V[i].push_back({j, distance(arr[i], arr[j]) / 5.0});
		}
	}

	priority_queue<Q, vector<Q>, cmp> pq;
	pq.push({n, 0});
	while (!pq.empty())
	{
		Q top = pq.top(); pq.pop();
		if (top.pos == n + 1)
		{
			cout << top.cost;
			break;
		}
		for (Line w : V[top.pos])
		{
			if (dst[w.to] > top.cost + w.cost)
			{
				dst[w.to] = top.cost + w.cost;
				pq.push({w.to, top.cost + w.cost });
			}
		}
	}

	return 0;
}
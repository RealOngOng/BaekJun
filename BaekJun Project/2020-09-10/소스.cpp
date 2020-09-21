#include <bits/stdc++.h>

using namespace std;

struct Vector2
{
	int x, y;

	bool operator==(const Vector2& pos)
	{
		return (x == pos.x && y == pos.y);
	}
	bool operator!=(const Vector2& pos)
	{
		return (x != pos.x || y != pos.y);
	}

	string ToString()
	{
		return "(" + to_string(x) + ", " + to_string(y) + ")";
	}
};
struct Q
{
	Vector2 pos;
	int cost;
};
struct cmp
{
	bool operator()(const Q& q1, const Q& q2)
	{
		return q1.cost > q2.cost;
	}
};

int H(Vector2 from, Vector2 to)
{
	return abs(from.x - to.x) + abs(from.y - to.y);
}

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main()
{
	int n; cin >> n;
	Vector2 s, e;
	cin >> s.x >> s.y >> e.x >> e.y;

	vector<vector<bool>> field(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++)
	{
		string str; cin >> str;
		for (int j = 0; j < n; j++)
			field[i][j] = (str[j] == '1');
	}

	function<bool(Vector2)> isOut = [&](Vector2 pos) -> bool
	{
		return (pos.x < 0 || pos.y < 0 || pos.x >= n || pos.y >= n);
	};

	//dst[i][j] = 시작점에서 i, j까지 최단거리
	vector<vector<int>> dst(n, vector<int>(n, 0x3f3f3f3f));
	//order[i][j] = 이 점을 최단 거리로 지나갈 때 이전에 지나갔던 좌표
	vector<vector<Vector2>> order(n, vector<Vector2>(n, {-1, -1}));

	priority_queue<Q, vector<Q>, cmp> pq;
	pq.push({ s, 0 });

	while (!pq.empty())
	{
		Q top = pq.top(); pq.pop();

		if (top.pos == e)
			break;

		for (int i = 0; i < 4; i++)
		{
			Vector2 front = { top.pos.x + dx[i], top.pos.y + dy[i] };
			
			if (isOut(front) || field[front.x][front.y]) continue;
			if (dst[front.x][front.y] > top.cost + H(top.pos, front))
			{
				dst[front.x][front.y] = top.cost + H(top.pos, front);
				order[front.x][front.y] = top.pos;
				pq.push({front, top.cost + H(top.pos, front)});
			}
		}
	}

	stack<Vector2> stk;

	Vector2 no = { -1, -1 };
	stk.push(e);

	order[s.x][s.y] = no;
	while (e != no)
	{
		e = order[e.x][e.y];
		if (e == no) break;
		stk.push(e);
	}

	while (!stk.empty())
	{
		cout << stk.top().ToString() << "->";
		stk.pop();
	}

	return 0;
}
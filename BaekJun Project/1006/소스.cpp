#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//위치
struct Position
{
	//몇번째 플레이어 이지
	int idx;
	//플레이어의 좌표
	int x, y;
	//생성자
	Position(int _idx, int _x, int _y)
	{
		idx = _idx;
		x = _x;
		y = _y;
	}
};
//플레이어의 위치를 담고 있는 vector
vector<Position> Player;

bool compareX(const Position& p1, const Position& p2)
{
	return p1.x < p2.x;
}
bool compareY(const Position& p1, const Position& p2)
{
	return p1.y < p2.y;
}
bool compareIdx(const Position& p1, const Position& p2)
{
	return p1.idx < p2.idx;
}

//sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
double distance(const Position& p1, const Position& p2)
{
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;
	return dx * dx + dy * dy;
}

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y; cin >> x >> y;
		Player.push_back(Position(i, x, y));
	}

	//후보
	vector<vector<Position>> candidate(n, vector<Position>());

	//X축 정렬
	sort(Player.begin(), Player.end(), compareX);
	
	for (int i = 0; i < n; i++)
	{
		int front = min(n-1, i + 1);
		int back = max(0, i - 1);		

		Position now = Player[i];

		if(front != i)
			candidate[now.idx].push_back(Player[front]);

		if(back != i)
			candidate[now.idx].push_back(Player[back]);
	}

	//Y축 정렬
	sort(Player.begin(), Player.end(), compareY);

	for (int i = 0; i < n; i++)
	{
		int front = min(n-1, i + 1);
		int back = max(0, i - 1);

		Position now = Player[i];

		if (front != i)
			candidate[now.idx].push_back(Player[front]);

		if (back != i)
			candidate[now.idx].push_back(Player[back]);
	}

	sort(Player.begin(), Player.end(), compareIdx);

	for (int i = 0; i < n; i++)
	{
		int near = -1;
		double neardst = 0;

		for (Position p : candidate[i])
		{
			if (near == -1)
			{
				near = p.idx;
				neardst = distance(Player[i], p);
			}
			else
			{
				double dst = distance(Player[i], p);

				if (dst < neardst)
				{
					near = p.idx;
					neardst = dst;
				}
			}
		}

		cout << i+1 << "번째 플레이어와 제일 가까운 플레이어의 번호 : " << near+1 << "\n";
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//��ġ
struct Position
{
	//���° �÷��̾� ����
	int idx;
	//�÷��̾��� ��ǥ
	int x, y;
	//������
	Position(int _idx, int _x, int _y)
	{
		idx = _idx;
		x = _x;
		y = _y;
	}
};
//�÷��̾��� ��ġ�� ��� �ִ� vector
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

	//�ĺ�
	vector<vector<Position>> candidate(n, vector<Position>());

	//X�� ����
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

	//Y�� ����
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

		cout << i+1 << "��° �÷��̾�� ���� ����� �÷��̾��� ��ȣ : " << near+1 << "\n";
	}

	return 0;
}
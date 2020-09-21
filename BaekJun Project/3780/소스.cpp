#include <bits/stdc++.h>

using namespace std;

int p[20001], pcnt[20001];

int find(int x)
{
	if (p[x] == 0) return x;
	else
	{
		int top = find(p[x]);
		pcnt[x] += pcnt[p[x]];
		p[x] = top;
		return top;
	}
}
void merge(int a, int b)
{
	pcnt[a] = abs(a - b) % 1000;
	p[a] = b;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tc; cin >> tc;
	while (tc--)
	{
		memset(p, 0, sizeof(p));
		memset(pcnt, 0, sizeof(pcnt));
		int n; cin >> n;
		while (true)
		{
			char cmd; cin >> cmd;
			if (cmd == 'O') break;
			if (cmd == 'E')
			{
				int a; cin >> a;
				find(a);
				cout << pcnt[a] << "\n";
			}
			else
			{
				int a, b; cin >> a >> b;
				merge(a, b);
			}
		}
	}
	return 0;
}
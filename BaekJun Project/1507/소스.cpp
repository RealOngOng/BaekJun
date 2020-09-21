#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int dst[21][21];
bool visit[21][21];
int field[21][21];

int main()
{
	memset(visit, true, sizeof(visit));

	int n; cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> dst[i][j];

	bool flag = false;

	int ans = 0;
	for(int k=1; k <= n; k++)
		for(int i=1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (i == k || j == k || i == j) continue;
				if (dst[i][j] > dst[i][k] + dst[k][j]) flag = true;
				if (dst[i][j] == dst[i][k] + dst[k][j])
					visit[i][j] = false;
			}

	int sum = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (visit[i][j]) sum += dst[i][j];

	sum /= 2;

	if (flag) sum = -1;
	cout << sum; 
	return 0;
}
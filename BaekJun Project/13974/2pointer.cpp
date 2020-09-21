#include <bits/stdc++.h>

#define MAX 5003
#define INF 1e9

using namespace std;

typedef long long ll;

//w°¡ input
int arr[MAX], w[MAX];
int start;
ll ans;

void insert(int c, int e)
{

	int i, d;
	ans = ans + (ll)c;
	start--;

	for (i = e; i <= start; i++)
		arr[i] = arr[i + 1];

	for (i = e - 2; i >= 0; i--)
	{
		if (c <= arr[i])
		{
			arr[i + 1] = c;
			break;
		}
		arr[i + 1] = arr[i];
	}

	while (i > 1 && arr[i - 1] <= c)
	{
		d = start - i;
		insert(arr[i - 1] + arr[i], i);
		i = start - d;
	}

}

int main()
{

	int tc;
	cin >> tc;

	for (int g = 1; g <= tc; g++)
	{

		ans = 0; start = 0;
		int m; cin >> m;

		for (int i = 1; i <= m; i++) cin >> w[i];

		w[0] = INF + 1; w[m + 1] = INF;
		arr[++start] = w[0]; arr[++start] = w[1];

		for (int i = 2; i <= m + 1; i++)
		{

			std::cout << i << ", " << start << "\n";

			while (arr[start - 1] <= w[i])
				insert(arr[start - 1] + arr[start], start);

			arr[++start] = w[i];

		}

		cout << ans << "\n";
	}

	return 0;

}
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

#define MAX 1000001

typedef std::pair<int, int>pi;

char S[12345678];

int ans[MAX];
pi cp[MAX];

int main()
{

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL), std::cout.tie(NULL);

	int n; std::cin >> n;
	fread(S, sizeof(char), n * 12, stdin);

	for (int i = 0, c = 0; S[i] != 0; c++)
	{
		while (S[i] != 0 && S[i] != '-' && (S[i] & 16) == 0)
			i++;
		if (S[i] == 0)
			break;
		int sign = 1;
		int a = 0;
		if (S[i] == '-')
			sign = -1, i++;
		while (S[i] >= '0'&&S[i] <= '9')
			a *= 10, a += S[i] - '0', i++;
		cp[c] = pi(a*sign, c);
	}

	sort(cp, cp + n);

	for (int i = 0, c = 0; i < n; i++)
	{
		if (i != 0 && cp[i].first != cp[i - 1].first)
			c++;
		ans[cp[i].second] = c;
	}

	int j = 0;

	for (int i = 0; i < n; i++)
	{
		int v = ans[i];
		if (v == 0)
		{
			S[j] = '0';
			S[j + 1] = ' ';
			j += 2;
			continue;
		}
		int l = 0;
		int v2 = v;
		while (v2 > 0)
			l++, v2 /= 10;
		S[j + l] = ' ';
		int lb = l;
		while (v > 0)
			l--, S[j + l] = (char)('0' + v % 10), v /= 10;
		j += lb + 1;
	}

	//for (int i = 0; i < n; i++)
	//	std::cout << S[i] << " ";

	fwrite(S, sizeof(char), j, stdout);

	return 0;
}
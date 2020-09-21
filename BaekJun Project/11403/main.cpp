#include <bits/stdc++.h>

using namespace std;

int n;

bool adj[101][101];

int main() {

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &adj[i][j]);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if (adj[j][i] && adj[i][k]) adj[j][k] = true;

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= n; j++)
			printf("%d ", adj[i][j]);

		printf("\n");

	}

	return 0;

}
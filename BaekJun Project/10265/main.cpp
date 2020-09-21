#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

typedef pair<int, int> pi;

int n, k;

int vert[1001]; //유향 그래프
vector<int> V[1001]; // 무향 그래프

bool visit[1001], finished[1001];

//i번 컴포넌트에 j명의 학생이 탔을 때 최댓값 
int dp[1001][1001];

int c = 0;

vector<pi> range;

int GetComponentCount(int i) {

	c++;

	visit[i] = true;

	for (int w : V[i]) {

		if (visit[w]) continue;
		
		visit[w] = true;
		GetComponentCount(w);

	}

	return c;

}

void GetCycle(int i) {

	visit[i] = true;

	int next = vert[i];

	if (visit[next]) {

		if (!finished[next]) {

			c++;
			for (int w = next; w != i; w = vert[w]) c++;

		}

	}
	else
		GetCycle(next);

	finished[i] = true;

}

int solve(int num, int p) {

	if (num >= range.size()) return p;
	if (p > k) return 0;

	if (dp[num][p] != -1) return dp[num][p];

	pi r = range[num];

	int &ret = dp[num][p];

	for (int i = r.first; i <= r.second; i++)
		if(p + i <= k) 
			ret = max(ret, solve(num + 1, p + i));

	ret = max(ret, solve(num + 1, p));

	return ret;

}

int main() {

	memset(dp, -1, sizeof(dp));

	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {

		scanf("%d", &vert[i]);
		V[i].push_back(vert[i]);
		V[vert[i]].push_back(i);

	}

	vector<int> start;
	vector<int> comp, cycle;

	for (int i = 1; i <= n; i++) {

		c = 0;

		if (visit[i]) continue;
		start.push_back(i);
		comp.push_back(GetComponentCount(i));

	}

	memset(visit, false, sizeof(visit));

	for (int i : start) {

		c = 0;

		GetCycle(i);
		cycle.push_back(c);

	}

	for (int i = 0; i < start.size(); i++)
		range.push_back({cycle[i], comp[i]});

	printf("%d\n", solve(0, 0));

	return 0;
	
}
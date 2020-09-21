#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef struct Task
{
	ll m, p, r;
	bool operator<(const Task& t)
	{
		return r * t.p < p * t.r;
	}
};

ll n, t;
//i번째 문제를 보고 있고, 현재 경과된 시간이 j
ll dp[51][100001];
Task task[51];

ll solve(int idx, ll time)
{
	if (idx == n) return 0;

	ll &ret = dp[idx][time];
	if (ret != -1) return ret;

	ret = 0;
	ll cost = task[idx].m - (time + task[idx].r) * task[idx].p;
	ll next_t = time + task[idx].r;

	if (cost <= 0 || next_t > t)
		return ret = 0;
	
	for (int i = idx + 1; i <= n; i++)
		ret = max(ret, solve(i, next_t) + cost);

	return ret;

}

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp, -1, sizeof(dp));

	cin >> n >> t;
	for (int i = 0; i < n; i++) cin >> task[i].m;
	for (int i = 0; i < n; i++) cin >> task[i].p;
	for (int i = 0; i < n; i++) cin >> task[i].r;

	sort(task, task + n);

	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, solve(i, 0));

	cout << ans;

	return 0;

}
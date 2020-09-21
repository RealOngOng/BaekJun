#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef struct T2 {
	int f, s;
};
typedef struct T3 {
	int f, s, t;
};

vector<T2> t2 = {
	{1, 2}, {1, 3}, {1, 4}, {1, 5}, 
	{2, 3}, {2, 4}, {2, 6},
	{3, 5}, {3, 6},
	{4, 5}, {5, 6},
	{4, 6}
};
vector<T3> t3 = {
	{1, 2, 3}, {1, 3, 5}, {1, 4, 5}, {1, 2, 4},
	{2, 4, 6}, {2, 3, 6}, {3, 5, 6}, {4, 5, 6}
};

vector<ll> GetNum(vector<ll>& arr) {

	vector<ll> ans(3, LLONG_MAX);
	ans[0] = *min_element(arr.begin(), arr.end());
	for (T2 t : t2)
		ans[1] = min(ans[1], arr[t.f] + arr[t.s]);
	for (T3 t : t3)
		ans[2] = min(ans[2], arr[t.f] + arr[t.s] + arr[t.t]);

	return ans;

}

int main() {

	ll n; cin >> n;
	
	ll sum = 0;
	vector<ll> arr(7, LLONG_MAX);
	for (int i = 1; i <= 6; i++)
		cin >> arr[i], sum += arr[i];

	if (n == 1) {
		cout << sum - *max_element(arr.begin() + 1, arr.end()) << "\n";
		return 0;
	}

	vector<ll> num = GetNum(arr);
	ll one = num[0], two = num[1], three = num[2];

	ll onecnt = 4 * (n - 1) * (n - 2) + (n - 2) * (n - 2),
		twocnt = 4 * (2 * n - 3),
		threecnt = 4;

	cout << onecnt * one + twocnt * two + three * threecnt << "\n";
	return 0;

}
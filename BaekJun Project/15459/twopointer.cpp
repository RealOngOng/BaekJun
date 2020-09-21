//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//ll n, m;
//ll flavor[100001], spicy[100001];
//ll sum[100001];
//
//ll seg[4 * 100001];
//
//ll GetSum(int s, int e)
//{
//	return sum[e + 1] - sum[s];
//}
//
//ll SetTree(int num, int s, int e)
//{
//	if (s == e)
//		return seg[num] = spicy[s];
//	return seg[num] =
//		max(SetTree(2 * num, s, (s + e) / 2), SetTree(2 * num + 1, (s + e) / 2 + 1, e));
//}
//
//ll query(int num, int s, int e, int l, int r)
//{
//	if (l > e || r < s) return 0;
//	if (l <= s && e <= r) 
//		return seg[num];
//
//	return max(query(2 * num, s, (s + e) / 2, l, r),
//			   query(2 * num + 1, (s + e) / 2 + 1, e, l, r));
//}
//ll query(int l, int r) { return query(1, 0, (int)n-1, l, r); }
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);
//
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> flavor[i] >> spicy[i];
//		sum[i + 1] = sum[i] + flavor[i];
//	}
//	SetTree(1, 0, (int)n - 1);
//
//	int l = 0, r = 0;
//	ll now = GetSum(l ,r);
//	ll ans = LLONG_MAX;
//
//	while (l < n || r < n)
//	{
//		if (l < n && r < n)
//		{
//			if (now >= m)
//			{
//				ans = min(ans, query(l, r));
//				l++;
//			}
//			else
//				r++;
//		}
//		else if (l < n) l++;
//		else if (r < n) r++;
//
//		now = GetSum(l, r);
//	}
//
//	cout << ans;
//	return 0;
//}
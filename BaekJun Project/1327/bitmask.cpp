//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//typedef pair<ll, int> pl;
//
//int n, k;
//
//ll bitswap(ll num, int l, int r) {
//
//	ll lnum = 0, rnum = 0; 
//	for (int i = 0; i < 3; i++)
//		lnum += (1 << (3 * l + i)), rnum += (1 << (3 * r + i));
//
//	lnum = num & lnum, rnum = num & rnum;
//
//	int move = (r - l) * 3;
//
//	lnum <<= move, rnum >>= move;
//
//	for (int i = 0; i < 3; i++)
//		num &= ~(1 << (3 * l + i)), num &= ~(1 << (3 * r + i));
//
//	num |= lnum, num |= rnum;
//
//	return num;
//
//}
//
//ll reverse(ll num, int pos) {
//
//	for (int i = 0; i < k / 2; i++)
//		num = bitswap(num, i, pos + k - i - 1);
//
//	return num;
//
//}
//
//int main() {
//
//	scanf("%d %d", &n, &k);
//
//	ll input = 0, ans = 0;
//
//	for (int i = 0; i < n; i++)
//		ans += i << (i * 3);
//
//	for (int i = 0; i < n; i++) {
//
//		int a; scanf("%d", &a);
//		input += (a - 1) << (i * 3);
//
//	}
//
//	int count = -1;
//
//	queue<pl> q;
//	set<ll> visit;
//
//	q.push({input, 0});
//
//	while (!q.empty()) {
//
//		pl top = q.front(); q.pop();
//
//		if (top.first == ans) {
//
//			count = min(count, top.second);
//			continue;
//
//		}
//
//		for (int i = 0; i < k; i++) {
//
//			ll front = reverse(top.first, i);
//
//			if (visit.find(front) != visit.end()) continue;
//
//			visit.insert(front);
//			q.push({ front, top.second + 1 });
//
//		}
//
//	}
//
//	printf("%d\n", count);
//
//	return 0;
//
//}
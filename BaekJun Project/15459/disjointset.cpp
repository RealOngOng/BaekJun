//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int N, index[100000];
//long long M, P[100000];
//
//pair<int, int> hay[100000];
//bool cmp(int a, int b) { return (hay[a].second < hay[b].second); }
//
//int find(int n)
//{
//	if (P[n] < 0) return n;
//	return P[n] = find(P[n]);
//}
//
//void merge(int a, int b)
//{
//	a = find(a);
//	b = find(b);
//
//	if (a == b) return;
//
//	P[a] += P[b];
//	P[b] = a;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	cin >> N >> M;
//
//	int f, s;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> f >> s;
//
//		hay[i] = { f, s };
//		P[i] = -f;
//		index[i] = i;
//	}
//
//	sort(index, index + N, cmp);
//
//	for (int i = 0; i < N; i++)
//	{
//		int curr = index[i];
//		int prev = curr - 1;
//		int next = curr + 1;
//
//		if (0 <= prev && (hay[prev].second <= hay[curr].second))
//			merge(curr, prev);
//
//		if (next < N && (hay[next].second <= hay[curr].second))
//			merge(curr, next);
//
//		if (M <= -P[find(curr)]) { cout << hay[curr].second << '\n'; break; }
//	}
//
//	return 0;
//}
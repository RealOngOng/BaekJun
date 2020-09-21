//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef struct Square {
//	int w, h;
//
//	bool isZero() { return (w == 0 && h == 0); }
//	string ToString() { return "(" + to_string(w) + ", " + to_string(h) + ")"; }
//};
//
//int dx[3] = { -1, 0, -1 };
//int dy[3] = { 0, -1, -1 };
//int n, m;
////가로
//Square wdp[401][401], hdp[401][401], sdp[401][401];
// 
//bool isOut(int x, int y) { return (x < 0 || y < 0 || x >= n || y >= m); }
//int f(Square s) { return (s.w * 2 + s.h * 2 - 1); }
//
//int main() {
//
//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);
//
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		string str; cin >> str;
//		for (int j = 0; j < m; j++) {
//			if (str[j] == '.')
//				wdp[i][j] = hdp[i][j] = sdp[i][j] = { 1, 1 };
//			else
//				wdp[i][j] = hdp[i][j] = sdp[i][j] = { 0, 0 };
//		}
//	}
//
//	//가로
//	for (int i = 0; i < n; i++) {
//		for (int j = 1; j < m; j++) {
//			if (wdp[i][j].isZero()) continue;
//
//			int nx = i, ny = j - 1;
//			if (wdp[nx][ny].isZero()) continue;
//			wdp[i][j].w = wdp[nx][ny].w + 1;
//		}
//	}
//
//	for (int i = 1; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (wdp[i][j].isZero()) continue;
//
//			int nx = i - 1, ny = j;
//			if (wdp[nx][ny].isZero()) continue;
//			Square sq = { min(wdp[i][j].w, wdp[nx][ny].w), wdp[nx][ny].h + 1 };
//
//			int a = f(wdp[i][j]), b = f(sq);
//			if (a < b) wdp[i][j] = sq;
//		}
//	}
//
//	//세로
//	for (int i = 1; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (hdp[i][j].isZero()) continue;
//
//			int nx = i - 1, ny = j;
//			if (hdp[nx][ny].isZero()) continue;
//			hdp[i][j].h = hdp[nx][ny].h + 1;
//		}
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 1; j < m; j++) {
//			if (hdp[i][j].isZero()) continue;
//
//			int nx = i, ny = j - 1;
//			if (hdp[nx][ny].isZero()) continue;
//			Square sq = { hdp[nx][ny].w + 1, min(hdp[i][j].h, hdp[nx][ny].h),  };
//
//			int a = f(hdp[i][j]), b = f(sq);
//			if (a < b) hdp[i][j] = sq;
//		}
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//
//			if (sdp[i][j].isZero()) continue;
//			
//			bool flag = true;
//			Square sq = { 10000, 10000 };
//			
//			for (int w = 0; w < 3; w++) {
//				int nx = i + dx[w], ny = j + dy[w];
//
//				if (isOut(nx, ny) || sdp[nx][ny].isZero())
//					flag = false;
//				
//				int a = f(sq), b = f(sdp[nx][ny]);
//				if (a > b) sq = sdp[nx][ny];
//			}
//
//			if (!flag) continue;
//
//			int a = f(sdp[i][j]), b = f(sq);
//			if (a < b) sdp[i][j] = sq;
//
//		}
//	}
//
//	int ans = 0;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			ans = max({ans, f(wdp[i][j]), f(hdp[i][j]), f(sdp[i][j])});
//
//	cout << ans;
//
//	return 0;
//
//}
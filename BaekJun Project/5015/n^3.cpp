//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//
//	string pattern; cin >> pattern;
//	int n; cin >> n;
//
//	vector<string> ans;
//	for (int i = 0; i < n; i++) {
//
//		string str; cin >> str;
//		vector<vector<int>> dp(101, vector<int>(101, -1));
//
//		function<bool(int, int)> solve = [&](int l, int r) -> bool {
//			int &ret = dp[l][r];
//			if (ret != -1) return ret;
//
//			while (l < pattern.size() && r < str.size() && pattern[l] == str[r])
//				l++, r++;
//
//			if (l == pattern.size())
//				return ret = (r == str.size());
//
//			if(pattern[l] == '*')
//				for (int i = 0; r + i <= str.size(); i++)
//					if (solve(l + 1, r + i))
//						return ret = 1;
//
//			return ret = 0;
//		};
//
//		if (solve(0, 0))
//			cout << str << "\n";
//
//	}
//
//	return 0;
//
//}
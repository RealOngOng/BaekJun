#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int minfi(vector<int>& vec, int no) {

	int ans = 0x3f3f3f3f;
	for (int i = 0; i < vec.size(); i++) {
		if (no == i) continue;
		ans = min(ans, vec[i]);
	}

	return ans;

}

int main() {

	int n; cin >> n;

	vector<int> front[26], back[26];
	for (int i = 0; i < 26; i++) {
		front[i].resize(n, 21);
		back[i].resize(n, 21);
	}

	for (int i = 0; i < n; i++) {

		string str; cin >> str;

		for (int j = 0; j < str.length(); j++) {

			int idx = str[j] - 'a';
			front[idx][i] = min(front[idx][i], j);
			back[idx][i] = min(back[idx][i], (int)str.length() - j - 1);

		}

	}

	int ans = 0x3f3f3f3f;

	for (int i = 0; i < 26; i++) {

		int u = 0, v = 0;

		int idx = min_element(front[i].begin(), front[i].end()) - front[i].begin();
		u = front[i][idx] + minfi(back[i], idx);

		idx = min_element(back[i].begin(), back[i].end()) - back[i].begin();
		v = back[i][idx] + minfi(front[i], idx);

		int len = min(u, v);

		ans = min(ans, len);

	}

	if (ans >= 20) cout << "-1\n";
	else cout << ans;

	return 0;

}
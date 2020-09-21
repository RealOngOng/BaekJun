#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;

	map<string, int> name;
	vector<string> idx(n + 1);

	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		name[str] = i + 1;
		idx[i + 1] = str;
	}

	while (m--) {

		string str; cin >> str;

		if ('0' <= str[0] && str[0] <= '9')
			cout << idx[atoi(str.c_str())] << "\n";
		else
			cout << name[str] << "\n";
 
	}

	return 0;

}
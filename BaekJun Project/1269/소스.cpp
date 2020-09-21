#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, m; cin >> n >> m;
	set<int> s;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		s.insert(a);
	}
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		auto itr = s.find(a);

		if (itr != s.end())
			s.erase(itr);
		else
			s.insert(a);
	}

	cout << s.size();

	return 0;

}
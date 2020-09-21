#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
typedef pair<string, string> ps;
typedef pair<int, int> pi;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tc; cin >> tc;

	while (tc--) {

		int n; cin >> n;

		vector<ps> squery;
		vector<pi> query;
		unordered_map<string, int> m;
		set<string> s;

		for (int i = 0; i < n; i++) {
			string a, b; cin >> a >> b;
			s.insert(a);
			s.insert(b);
			squery.push_back({ a, b });
		}

		int idx = 1;
		for (auto itr = s.begin(); itr != s.end(); itr++)
			m[*itr] = idx++;

		vector<int> p(2 * 1e5 + 1, 0), pscale(2 * 1e5 + 1, 1);

		for (int i = 0; i < n; i++)
			query.push_back({m[squery[i].first], m[squery[i].second]});

		function<int(int)> find = [&](int x) -> int {
			if (p[x] == 0) return x;
			else
				return p[x] = find(p[x]);
		};
		
		function<void(int, int)> merge = [&](int a, int b) -> void {
			a = find(a), b = find(b);
			if (a == b) return;
			p[b] = a;
			pscale[a] += pscale[b];
		};
 
		for (pi p : query) {
			merge(p.first, p.second);
			cout << pscale[find(p.first)] << "\n";
		}

	}

	return 0;

}
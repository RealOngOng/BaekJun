#include <bits/stdc++.h>

using namespace std;

typedef struct Data {

	int num;
	string route;

};

bool visit[10000];

string intTostring(int num) {

	string str = to_string(num);

	for (int i = str.length(); i < 4; i++) str = "0" + str;

	return str;

}

int D(int num) {return (2 * num) % 10000;}

int S(int num) {return ((--num < 0) ? 9999 : num);}

int L(int num) {return (num % 1000) * 10 + num / 1000;}

int R(int num) {return (num % 10) * 1000 + (num / 10);}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int t; cin >> t;

	while (t--) {

		int a, b; cin >> a >> b;

		queue<Data> q; string route;

		q.push({ a });

		int cnt = 1e9;

		while (!q.empty()) {

			Data top = q.front(); q.pop();

			if (top.num == b) {

				if (cnt > top.route.size())
					route = top.route;

			}

			char route[4] = { 'D', 'S', 'L', 'R' };
			int go[4] = { D(top.num), S(top.num), L(top.num), R(top.num) };

			for (int i = 0; i < 4; i++) {

				if (visit[go[i]]) continue;

				visit[go[i]] = true;

				Data temp = top; 
				temp.route += route[i]; temp.num = go[i];
				q.push(temp);

			}

		}

		cout << route << "\n";

		memset(visit, false, sizeof(visit));

	}

	return 0;

}
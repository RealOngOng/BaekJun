#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

typedef struct bdata {

	pi state;
	int num;

};

//0 : a 를 채웟을 때
//1 : b를 채웟을 때
//2 : a를 비웟을 때
//3 : b를 비웠을 때
bool visit[4][100001];

int a, b, A, B;

void F(queue<bdata>& q, pi p, int num) {

	if (!visit[0][p.second])
		q.push({ { a, p.second }, num + 1 }), visit[0][p.second] = true;

	if (!visit[1][p.first])
		q.push({ { p.first, b }, num + 1 }), visit[1][p.first] = true;

}

void E(queue<bdata>& q, pi p, int num) {

	if (!visit[2][p.second])
		q.push({ { 0, p.second }, num + 1 }), visit[2][p.second] = true;

	if (!visit[3][p.first])
		q.push({ { p.first, 0 }, num + 1 }), visit[3][p.first] = true;

}

void M(queue<bdata>& q, pi p, int num) {

	if (p.first + p.second < a) {

		if (!visit[3][p.first + p.second])
			q.push({ {p.first + p.second, 0}, num + 1 }), visit[3][p.first + p.second] = true;

	}
	else {

		if (!visit[0][p.first + p.second - a])
			q.push({ {a, p.first + p.second - a}, num + 1 }), visit[0][p.first + p.second - a] = true;

	}

	if (p.first + p.second < b) {

		if (!visit[2][p.first + p.second])
			q.push({ {0, p.first + p.second}, num + 1 }), visit[2][p.first + p.second] = true;

	}
	else {

		if (!visit[1][p.first + p.second - b])
			q.push({ {p.first + p.second - b, b}, num + 1 }), visit[1][p.first + p.second - b] = true;

	}

}

pi M(pi p, bool front) {

	if (front) {

		p.second += p.first;
		p.first = 0;
		if (p.second > b)
			p.first = p.second - b, p.second = b;

	} else{

		p.first += p.second;
		p.second = 0;
		if (p.first > a)
			p.second = p.first - a, p.first = a;

	}

	return p;

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> a >> b >> A >> B;

	pi dst = { A, B };

	queue<bdata> q;

	q.push({{ 0, 0 }, 0});

	int ans = -1;

	while (!q.empty()) {

		bdata top = q.front(); q.pop();

		if (top.state == dst) {

			ans = top.num;
			break;

		}

		F(q, top.state, top.num);
		E(q, top.state, top.num);
		M(q, top.state, top.num);

	}

	if (ans == 1e9) ans = -1;

	cout << ans;

	return 0;

}
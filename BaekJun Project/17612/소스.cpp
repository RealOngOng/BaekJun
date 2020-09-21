#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef struct Person {

	int id, wegiht;

};
typedef struct Input {

	Input(int _idx, int _time) {

		idx = _idx;
		time = _time;

	}

	int idx, time;

};
typedef struct Output {

	Output(int _idx, int _total, int _pId) {

		idx = _idx;
		total = _total;
		pId = _pId;

	}

	int idx, total, pId;

};

vector<Person> person;

struct Inputcmp {

	bool operator()(const Input& i1, const Input& i2) {

		if (i1.time != i2.time) return i1.time > i2.time;
		return i1.idx > i2.idx;

	}

};

bool cmp(const Output& o1, const Output& o2) {

	if (o1.total != o2.total) return o1.total < o2.total;
	return o1.idx > o2.idx;

}

int main() {

	int n, k; cin >> n >> k;

	//time, idx
	priority_queue<Input, vector<Input>, Inputcmp> pq1;
	vector<Output> out;

	for (int i = 1; i <= k; i++)
		pq1.push(Input(i, 0));

	for (int i = 0; i < n; i++) {

		int a, b; cin >> a >> b;
		person.push_back({a, b});

		Input top = pq1.top(); pq1.pop();

		pq1.push({top.idx, top.time + b});
		out.push_back(Output(top.idx, top.time + b, i));

	}

	ll ans = 0;

	ll w = 1;

	sort(out.begin(), out.end(), cmp);

	for (Output &o : out) {

		ans += (ll)person[o.pId].id * w;

		w++;

	}

	cout << ans;

	return 0;

}
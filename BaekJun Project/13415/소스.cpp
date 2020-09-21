#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

vector<pi> GetOrder() {

	int k; cin >> k;
	k *= 2;
	vector<pi> order(k);
	for (int i = 0; i < k; i++) {

		cin >> order[i].first;
		order[i].second = i;

	}

	sort(order.begin(), order.end(), [](const pi& p1, const pi& p2) -> bool {
		if (p1.first != p2.first) return p1.first > p2.first;
		return p1.second > p2.second;
	});

	vector<pi> vec;

	pi top = order[0];
	vec.push_back(top);

	for (int i = 1; i < order.size(); i++) {

		if (top.second > order[i].second) continue;
		if (top.first == order[i].first)
			if (top.second > order[i].second) continue;

		top = order[i];
		vec.push_back(order[i]);

	}

	return vec;

}

vector<int> arr;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	vector<pi> order = GetOrder();
	order.push_back({0, 0});

	vector<int> vec(arr.begin(), arr.begin() + order[0].first);

	sort(vec.begin(), vec.end());

	deque<int> dq;
	for (int i = 0; i < vec.size(); i++) dq.push_back(i);

	for (int i = 0; i < order.size() - 1; i++) {

		if (order[i].second % 2 == 0) {
			for (int j = order[i].first; j > order[i + 1].first; j--)
				arr[j - 1] = vec[dq.back()], dq.pop_back();
		}
		else {
			for (int j = order[i].first; j > order[i + 1].first; j--)
				arr[j - 1] = vec[dq.front()], dq.pop_front();
		}

	}

	for (int w : arr)
		cout << w << " ";

	return 0;

}
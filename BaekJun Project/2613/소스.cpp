#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr;

bool f(int mid) {

	int group = 1, sum = 0;

	for (int w : arr) {

		if (sum + w <= mid) sum += w;
		else {

			sum = w;
			group++;

		}

	}

	return group <= m;

}

vector<int> GetOrder(int mid) {

	vector<int> ans;

	int group = 1, sum = 0;

	ans.push_back(0);

	int i = 0;
	for (i = 0; i < n; i++) {

		if (n - i == m - group) break;

		int w = arr[i];

		if (sum + w <= mid) sum += w, ans[group - 1]++;
		else {

			sum = w;
			group++;
			ans.push_back(1);

		}

	}

	for (; i < n; i++)
		ans.push_back(1);

	return ans;

}

int main() {

	cin >> n >> m;
	arr.resize(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	int lo = *max_element(arr.begin(), arr.end()), hi = 300 * 100;
	while (lo <= hi) {

		int mid = (lo + hi) / 2;

		if (!f(mid)) lo = mid + 1;
		else hi = mid - 1;

	}

	cout << lo << "\n";
	vector<int> order = GetOrder(lo);
	for (int w : order)
		cout << w << " ";

	return 0;

}
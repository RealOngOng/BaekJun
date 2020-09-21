#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cin.tie(0);

	int n, l; cin >> n >> l;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	deque<int> chain;

	for (int i = 0; i < n; i++)
	{
		while (!chain.empty() && arr[chain.back()] > arr[i])
			chain.pop_back();
		chain.push_back(i);

		while (!chain.empty() && chain.front() <= i - l)
			chain.pop_front();

		cout << arr[chain.front()] << " ";
	}
	return 0;
}
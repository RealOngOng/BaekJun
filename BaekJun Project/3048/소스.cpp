#include <bits/stdc++.h>

using namespace std;

typedef struct Ant {
	char c;
	bool group;
};

int main()
{

	int n, m; cin >> n >> m;
	string a, b; cin >> a >> b;
	reverse(a.begin(), a.end());

	vector<Ant> arr;
	for (int i = 0; i < n; i++)
		arr.push_back({a[i], false});
	for (int i = 0; i < m; i++)
		arr.push_back({ b[i], true });

	vector<Ant> cp(arr.begin(), arr.end());

	int t; cin >> t;

	while (t--) {

		for (int i = 0; i < n + m; i++) {

			int next = i + ((arr[i].group) ? -1 : 1);

			if (next < 0 || next >= n + m) continue;
			if (arr[i].group == arr[next].group) continue;
			swap(cp[i], cp[next]);
			i++;

		}

		for (int i = 0; i < n + m; i++)
			arr[i] = cp[i];

	}

	for (Ant a : arr)
		cout << a.c;

	return 0;

}
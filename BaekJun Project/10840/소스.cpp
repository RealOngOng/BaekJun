#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull pw1500[26];
vector<ull> arr;
 
int main() {

	pw1500[0] = 1;

	for (int i = 1; i < 26; i++)
		pw1500[i] = pw1500[i - 1] * 1500;

	string a, b; cin >> a >> b;

	for (int i = 0; i < a.length(); i++) {

		ull h = 0;

		for (int j = i; j < a.length(); j++) {

			h += pw1500[a[j] - 'a'];
			arr.push_back(h);

		}

	}

	sort(arr.begin(), arr.end());

	int ans = 0;

	for (int i = 0; i < b.length(); i++) {

		ull h = 0;

		for (int j = i; j < b.length(); j++) {

			h += pw1500[b[j] - 'a'];

			int idx = lower_bound(arr.begin(), arr.end(), h) - arr.begin();

			if (idx == arr.size()) continue;

			if (arr[idx] == h)
				ans = max(ans, j - i + 1);

		}

	}

	cout << ans;

	return 0;

}
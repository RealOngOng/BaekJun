#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string str[10];

ll Count[26];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {

		cin >> str[i];

		int len = str[i].length();

		for (int j = 0; j < len; j++)
			Count[str[i][j] - 'A'] += powl(10, len - j - 1);

	}

	vector<int> vec;

	for (int i = 0; i < 26; i++)
		if (Count[i])
			vec.push_back(Count[i]);

	ll result = 0;

	int num = 9;

	sort(vec.begin(), vec.end(), greater<int>()); 

	for (int i = 0; i < vec.size(); i++)
		result += vec[i] * (num--);

	cout << result << endl;

	return 0;

}
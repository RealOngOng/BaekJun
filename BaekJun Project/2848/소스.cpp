#include <bits/stdc++.h>

using namespace std;

int diffrentchar(const string& str1, const string& str2)
{
	int len = min(str1.length(), str2.length());
	for (int i = 0; i < len; i++)
		if (str1[i] != str2[i])
			return i;

	return -1;
}

int main()
{
	int n; cin >> n;
	bitset<26> visit;
	vector<int> V[26];
	vector<int> indegree(26);

	vector<string> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		for (char c : arr[i])
			visit[c - 'a'] = true;
	}

	for (int i = 0; i < n - 1; i++)
	{
		int pos = diffrentchar(arr[i], arr[i+1]);

		if (pos == -1 && arr[i].length() > arr[i+1].length())
		{
			cout << "!";
			return 0;
		}

		if (pos == -1) continue;

		int a = arr[i][pos] - 'a', b = arr[i + 1][pos] - 'a';

		V[a].push_back(b);
		indegree[b]++;
	}

	int len = 0;
	queue<int> q;
	for (int i = 0; i < 26; i++)
	{
		if (!visit[i]) continue;
		len++;
		if (indegree[i] == 0)
			q.push(i);
	}

	bool flag = false;
	vector<int> order;
	int cnt = 0;

	while (!q.empty())
	{
		if (q.size() > 1)
			flag = true;

		int top = q.front(); q.pop();
		order.push_back(top);
		cnt++;

		for (int w : V[top])
			if (--indegree[w] == 0)
				q.push(w);
	}

	if (cnt != len)
	{
		cout << "!";
		return 0;
	}
	if (flag)
	{
		cout << "?";
		return 0;
	}

	for (int w : order)
		cout << (char)(w + 'a');

	return 0;
}
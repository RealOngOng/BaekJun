#include <bits/stdc++.h>

using namespace std;

int main()
{

	vector<int> vec;

	for (int i = 0; i < 3; i++) {

		int a; scanf("%d", &a);
		vec.push_back(a);

	}

	sort(vec.begin(), vec.end());

	for (int i : vec)
		printf("%d ", i);

	return 0;

}
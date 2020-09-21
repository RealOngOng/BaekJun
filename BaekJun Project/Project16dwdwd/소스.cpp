#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> arr = { 1, 2, 3, 4, 5 };
	
	rotate(arr.begin(), arr.begin() + 3, arr.end());

	for (int w : arr)
		cout << w << " ";
	return 0;
}


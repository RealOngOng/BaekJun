#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tc; cin >> tc;

	for (int i = 1; i <= tc; i++)
	{
		long long a, b, c; cin >> a >> b >> c;
		vector<long long> arr = { a, b, c };
		sort(arr.begin(), arr.end());
		a = arr[0], b = arr[1], c = arr[2];

		function<void(string)> print = [&](string str) -> void
		{
			cout << "Case #" << i << ": " << str << "\n";
		};

		if (a + b <= c) print("invalid!"); 
		else if (a == b && b == c) print("equilateral");
		else if (a == b || b == c || a == c) print("isosceles");
		else print("scalene");
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

struct Vector2
{
	double x, y;
};
double distance(const Vector2& v1, const Vector2& v2)
{
	double dx = v1.x - v2.x;
	double dy = v1.y - v2.y;
	return dx * dx + dy * dy;
}
int main()
{
	int n; cin >> n;
	Vector2 mid = { 0, 0 };
	vector<Vector2> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].x >> arr[i].y;
		mid.x += arr[i].x;
		mid.y += arr[i].y;
	}

	mid.x /= (double)n;
	mid.y /= (double)n;

	double diff = 0.1;
	double ans = 0;
	for (int i = 0; i < 30000; i++)
	{
		int idx = 0;
		double dst = 0;	
		for (int j = 0; j < n; j++)
		{
			double d = distance(arr[j], mid);
			if (d > dst)
			{
				dst = d;
				idx = j;
			}
		}

		ans = dst;
		mid.x += (arr[idx].x - mid.x) * diff;
		mid.y += (arr[idx].y - mid.y) * diff;
		diff *= 0.999;
	}

	cout << fixed;
	cout.precision(3);
	cout << mid.x << " " << mid.y << "\n" << sqrt(ans) << "\n";
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

struct Vector3
{
	double x, y, z;
};

double distance(const Vector3 v1, const Vector3 v2)
{
	double dx = v1.x - v2.x;
	double dy = v1.y - v2.y;
	double dz = v1.z - v2.z;
	return dx * dx + dy * dy + dz * dz;
}

int main()
{
	int n; cin >> n;
	vector<Vector3> arr(n);

	double midx = 0, midy = 0, midz = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].x >> arr[i].y >> arr[i].z;
		midx += arr[i].x;
		midy += arr[i].y;
		midz += arr[i].z;
	}

	midx /= (double)n;
	midy /= (double)n;
	midz /= (double)n;
	Vector3 mid = { midx, midy, midz };

	double diff = 0.1;
	double ans = 0;
	for (int i = 0; i < 30000; i++)
	{
		int idx = 0;
		double dst = 0;
		for (int j = 0; j < n; j++)
		{
			double d = distance(mid, arr[j]);
			if (dst < d)
			{
				dst = d;
				idx = j;
			}
		}

		ans = dst;
		mid.x += (arr[idx].x - mid.x) * diff;
		mid.y += (arr[idx].y - mid.y) * diff;
		mid.z += (arr[idx].z - mid.z) * diff;
		diff *= 0.999;
	}

	cout << fixed;
	cout.precision(2);
	cout << sqrt(ans);

	return 0;
}
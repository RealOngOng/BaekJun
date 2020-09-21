#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 100000000

using namespace std;

bool compare(int a, int b) {
	return a < b;
}

int main() {

	int n, temp, arr[8001], mx = -1, mode, count = 0;
	double sum = 0;
	vector<int> vt, mode_vt;
	for (int i = 0; i < 8001; i++)
		arr[i] = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		vt.push_back(temp);
		sum += temp;
		temp = (temp <= 0) ? abs(temp) : temp + 4000;
		arr[temp]++;
		if (arr[temp] > mx) {
			mx = arr[temp];
			mode = temp;
		}
	}
	sort(vt.begin(), vt.end(), compare);
	for (int i = 0; i < 8001; i++) {
		if (arr[i] == mx) {
			mode = i;
			mode = (mode <= 4000) ? -mode : mode - 4000;
			mode_vt.push_back(mode);
		}
	}
	sort(mode_vt.begin(), mode_vt.end(), compare);
	mode = (mode_vt.size() >= 2) ? mode_vt[1] : mode_vt[0];
	double eve = sum / double(n);
	printf("%.0f\n", eve);
	printf("%d\n", vt[n / 2]);
	printf("%d\n", mode);
	printf("%d\n", vt[vt.size() - 1] - vt[0]);

	return 0;
}
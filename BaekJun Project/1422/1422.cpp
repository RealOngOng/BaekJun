#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long int list[1001], Sort[1001];

void merge(int left, int right) {

	int mid = (left + right) / 2, i = left, j = mid + 1, k = left;

	while (i <= mid && j <= right) Sort[k++] = (list[i] <= list[j]) ? list[i++] : list[j++];

	if (i <= mid) for (int w = i; w <= mid; w++) Sort[k++] = list[w];
	else for (int w = j; w <= right; w++) Sort[k++] = list[w];

	for (int w = left; w <= right; w++) list[w] = Sort[w];

}

void merge_sort(int left, int right) {

	if (left < right) {

		int mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, right);

	}

}

long long int min(long long int a, long long int b) { return (a > b) ? a : b; }

int main() {

	int n, k;
	cin >> k >> n;

	int w;
	for (int i = 0; i < k; i++) {

		cin >> w;
		list[i] = w;

	}

	for (int i = k - 1; i < n; i++) list[i] = list[k - 1];

	for (int i = 0; i < n; i++) cout << list[i] << endl;

	cout << endl;

	while (k--) {

		for (int i = 0; i < n; i += 2) {

			string s1 = to_string(list[i]), s2 = to_string(list[i+1]);

			string temp1 = s1 + s2, temp2 = s2 + s1;

			list[i] = min(stoi(temp1.c_str()), stoi(temp2.c_str()));

		}

		for (int i = 0; i < n - 1; i++) {

			cout << list[i] << " ";

		}

		cout << endl;

	}

	cout << list[0] << endl;

	return 0;

}
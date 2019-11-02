#include <iostream>

using namespace std;

#define MAX 1000000

int Array[MAX];
int Sorted[MAX];

void merge(int left, int right) {

	int mid = (left + right) / 2, i = left, j = mid + 1, k = left;

	while (i <= mid && j <= right) {

		if (Array[i] <= Array[j]) Sorted[k++] = Array[i++];
		else Sorted[k++] = Array[j++];

	}

	if (i <= mid) for (int w = i; w <= mid; w++) Sorted[k++] = Array[w];
	else for (int w = j; w <= right; w++) Sorted[k++] = Array[w];

	for (int w = left; w <= right; w++) Array[w] = Sorted[w];

}

void partition(int left, int right) {

	int mid;

	if (left < right) {

		mid = (left + right) / 2;

		partition(left, mid);
		partition(mid + 1, right);
		merge(left, right);

	}
	
}

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> Array[i];

	partition(0, n-1);

	for (int i = 0; i < n; i++) cout << Array[i] << "\n";

	return 0;

}
#include <bits/stdc++.h>

using namespace std;

int A[100], B[100];

int n;

int S() {

	int sum = 0;

	for (int i = 0; i < n; i++) sum += A[i] * B[i];

	return sum;

}

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) scanf("%d", &A[i]);
	for (int i = 0; i < n; i++) scanf("%d", &B[i]);

	sort(A, A + n);
	sort(B, B + n, greater<int>());

	printf("%d\n", S());

	return 0;

}
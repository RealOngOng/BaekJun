#include <bits/stdc++.h>

using namespace std;

int main() {

	int arr[3];

	for (int i = 0; i < 3; i++) scanf("%d", arr + i);
	
	sort(arr, arr + 3);

	int s1 = arr[1] - arr[0],
		s2 = arr[2] - arr[1];

	if (s1 == s2) printf("%d", arr[2] + s1);
	else if (s1 < s2) printf("%d", arr[1] + s1);
	else printf("%d", arr[0] + s2);

	return 0;

}
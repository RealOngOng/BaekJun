#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {

	int x, y;

	bool operator<(Vector2 vec) {

		if (x != vec.x) return x < vec.x;
		return y < vec.y;

	}
	bool operator>(Vector2 vec) {

		if (x != vec.x) return x > vec.x;
		return y > vec.y;

	}

};

Vector2 arr[100001];

int main() {

	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &arr[i].x, &arr[i].y);

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
		printf("%d %d\n", arr[i].x, arr[i].y);

	return 0;

}
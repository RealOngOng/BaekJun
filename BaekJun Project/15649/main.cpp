#include <iostream>
#include <vector>

using namespace std;

#define MAX 9

int n, m;

bool visited[MAX];
int arr[MAX];

void func(int);
void view() {

	for (int i = 0; i < n; i++) cout << "list: " << visited[i] << " ";

	cout << endl;

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	func(0);

	return 0;

}

void func(int num) {

	if (num == m) {

		for (int i = 0; i < m; i++) cout << arr[i] << " ";

		cout << "\n";
		return;

	}

	for (int i = 1; i <= n; i++) {

		if (!visited[i - 1]) {

			visited[i - 1] = true;
			arr[num] = i;
			func(num + 1);
			visited[i - 1] = false;

		}

	}

}
#include <bits/stdc++.h>

using namespace std;

typedef struct Node {

	int x = 0, y = 0;
	int left = -1, right = -1;
	int cntleft = 0, cntright = 0;

};

Node node[10001];
int parent[10001];

vector<int> depth_x[50];

int CountTree(int n) {

	if (node[n].left != -1) 
		node[n].cntleft = CountTree(node[n].left);
	if (node[n].right != -1) 
		node[n].cntright = CountTree(node[n].right);

	return node[n].cntleft + node[n].cntright + 1;

}

void SetTree(int n, int depth) {

	Node &now = node[n];

	now.y = depth;

	int pa = parent[n];

	if (now.left != -1) {

		node[now.left].x = now.x - node[now.left].cntright - 1;
		depth_x[depth + 1].push_back(node[now.left].x);
		SetTree(now.left, depth + 1);

	}
	if (now.right != -1) {

		node[now.right].x = now.x + node[now.right].cntleft + 1;
		depth_x[depth + 1].push_back(node[now.right].x);
		SetTree(now.right, depth + 1);

	}

}

int main() {

	int root = 1;

	int n; cin >> n;

	for (int i = 0; i < n; i++) {

		int a, b, c; cin >> a >> b >> c;

		node[a].left = b;
		node[a].right = c;
		
		parent[b] = a;
		parent[c] = a;

	}

	for (int i = 1; i <= n; i++) {

		if (parent[i] > 0) continue;

		root = i;
		break;

	}

	CountTree(root);

	node[root].x = node[root].cntleft + 1;

	SetTree(root, 1);

	int ans = 1;
	int dans = 1;

	for (int i = 1; i < 50; i++) {

		if (depth_x[i].size() == 0) continue;

		auto mm = minmax_element(depth_x[i].begin(), depth_x[i].end());

		int sub = *mm.second - *mm.first + 1;

		if (sub > ans) {

			ans = sub;
			dans = i;

		}

	}

	cout << dans << " " << ans;

	return 0;

}
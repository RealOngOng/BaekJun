#include <bits/stdc++.h>

using namespace std;

typedef struct Node {

	int left = - 1, right = -1;

};

Node node[30];

//전위 순회
void preorder(int idx) {

	cout << (char)(idx + 'A');
	if (node[idx].left != -1) preorder(node[idx].left);
	if (node[idx].right != -1) preorder(node[idx].right);

}

//중위 순회
void inorder(int idx) {

	if (node[idx].left != -1) inorder(node[idx].left);
	cout << (char)(idx + 'A');
	if (node[idx].right != -1) inorder(node[idx].right);

}

//후위 순회
void postorder(int idx) {

	if (node[idx].left != -1) postorder(node[idx].left);
	if (node[idx].right != -1) postorder(node[idx].right);
	cout << (char)(idx + 'A');

}

int main() {

	int n; scanf("%d", &n);

	while (n--) {

		char a, b, c; scanf(" %c %c %c", &a, &b, &c);

		int idx = a - 'A';

		if (b != '.')
			node[idx].left = b - 'A';

		if (c != '.')
			node[idx].right = c - 'A';

	}

	preorder(0); cout << "\n";
	inorder(0); cout << "\n";
	postorder(0); cout << "\n";

	return 0;

}
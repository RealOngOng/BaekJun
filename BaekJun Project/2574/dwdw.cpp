//#include <iostream>
//#include <limits.h>
//
//#define B 0
//#define W 1
//
//using namespace std;
//
//int I, J, N;
//
//int maxi = -INT_MAX, mini = INT_MAX;
//
//struct paper {
//
//	int sx, sy, fx, fy, color, id;
//	paper *left = 0;
//	paper *right = 0;
//
//}P[80010];
//
//int qs, qe;
//
//void set(int n, int a, int b, int c, int d, int e, int f) {
//
//	P[n].sx = a;    P[n].sy = b;    P[n].fx = c;
//	P[n].fy = d;    P[n].id = e;    P[n].color = f;
//
//}
//
//int main() {
//
//	cin >> I >> J >> N;
//	set(0, 0, 0, I, J, 0, W);
//
//	int a, b, i = 1;
//
//	paper *now = &P[0];
//
//	//����
//	while (N--) {
//
//		now = &P[0];
//		cin >> a >> b;
//
//		//���� ��尡 ���� ���
//		while (now->left) {
//
//			//���� ����� ���� �ȿ� ������ ���
//			if (now->left->sx <= a && now->left->fx >= a &&
//				now->left->sy <= b && now->left->fy >= b)
//				now = now->left;
//			//���� ����� ���� �ȿ� �������� ���� ���
//			else now = now->right;
//
//		}
//
//		if (now->color == W) {
//
//			set(i, now->sx, now->sy, now->fx, b, i, B);
//			now->left = &P[i++];
//
//			set(i, now->sx, b, now->fx, now->fy, i, B);
//			now->right = &P[i++];
//
//		}
//
//		if (now->color == B) {
//
//			set(i, now->sx, now->sy, a, now->fy, i, W);
//			now->left = &P[i++];
//
//			set(i, a, now->sy, now->fx, now->fy, i, W);
//			now->right = &P[i++];
//
//		}
//
//	}
//
//	now = &P[0];
//
//	qe = 1;
//
//	int nb; //����
//
//	while (qs != qe) {
//
//		if (P[qs].left) {
//
//			qe += 2;
//
//		}
//		else {
//
//			//���� ���ϱ�
//			nb = (P[qs].fx - P[qs].sx)*(P[qs].fy - P[qs].sy);
//
//			//�ִ� �ּ� ���ϱ�
//			if (nb < mini)mini = nb;
//			if (nb > maxi)maxi = nb;
//
//		}
//
//		qs++;
//
//	}
//
//	cout << maxi << " " << mini;
//
//	return 0;
//
//}
//

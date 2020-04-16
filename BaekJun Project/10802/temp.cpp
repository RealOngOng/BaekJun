#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int M, N, RM;
int grow[1110][1110][10], bee[1110][1110], seed[2220];
int normalize(int x, int m)
{
	if (x < 0) return 0;
	if (x >= 2 * m - 1) return 1000000;
	return x;
}
vector<int> dnc(int si, int sj, int ei, int ej, vector<int> input)
{
	int size = ei - si + 1;
	vector<int> output(4 * size*size);
	if (size == 2) {
		int see = 0;
		for (int x = 0; x < 4; x++) for (int y = x; y < 4; y++) {
			int g = grow[ei][ej][see++];
			bee[ei][ej] += g * input[x * 4 + y];
			int nx = 3, ny = 3;
			if (x == 0) nx = 0;
			else if (g >= 1) nx = 1;
			else if (x <= 2) nx = 2;
			if (y == 0) ny = 0;
			else if (g == 2) ny = 1;
			else if (y <= 2) ny = 2;
			output[x * 4 + y] = nx * 4 + ny;
		}
	}
	else if (si >= RM || sj >= RM) {
		for (int ax = 0; ax < 2 * size; ax++) for (int ay = ax; ay < 2 * size; ay++) {
			output[ax * 2 * size + ay] = ax * 2 * size + ay;
		}
	}
	else {
		int half = (ei - si) / 2 + 1;
		vector<int> input1(4 * half*half);
		for (int ax = 0; ax < 2 * size; ax++) for (int ay = ax; ay < 2 * size; ay++) if (input[ax * 2 * size + ay]) {
			int px = min(normalize(ax - half + 1, half), 2 * half - 1);
			int py = min(normalize(ay - half + 1, half), 2 * half - 1);
			input1[px * 2 * half + py] += input[ax * 2 * size + ay];
		}
		vector<int> output1 = dnc(si, sj, si + half - 1, sj + half - 1, input1);

		vector<int> input2(4 * half*half);
		vector<int> input3(4 * half*half);
		for (int ax = 0; ax < 2 * size; ax++) for (int ay = ax; ay < 2 * size; ay++) if (input[ax * 2 * size + ay]) {
			int px = min(normalize(ax - half + 1, half), 2 * half - 1);
			int py = min(normalize(ay - half + 1, half), 2 * half - 1);
			int po = output1[px * 2 * half + py];
			int pox = normalize(po / (2 * half), half);
			int poy = normalize(po % (2 * half), half);
			int bx = 2 * size - 1, by = 2 * size - 1;
			if (ax < half || ax >= size * 2 - half - 1) bx = min(bx, ax);
			else bx = min(bx, size * 2 - half - 1);
			if (ay < half || ay >= size * 2 - half - 1) by = min(by, ay);
			else by = min(by, size * 2 - half - 1);
			bx = min(bx, pox + half - 1);
			by = min(by, poy + half - 1);
			int qx = min(normalize(bx - 2 * (half - 1), half), 2 * half - 1);
			int qy = min(normalize(by - 2 * (half - 1), half), 2 * half - 1);
			input2[qx * 2 * half + qy] += input[ax * 2 * size + ay];
			int rx = min(normalize(bx, half), 2 * half - 1);
			int ry = min(normalize(by, half), 2 * half - 1);
			input3[rx * 2 * half + ry] += input[ax * 2 * size + ay];
		}
		vector<int> output2 = dnc(si, sj + half - 1, si + half - 1, ej, input2);
		vector<int> output3 = dnc(si + half - 1, sj, ei, sj + half - 1, input3);
		vector<int> input4(4 * half*half);
		for (int ax = 0; ax < 2 * size; ax++) for (int ay = ax; ay < 2 * size; ay++) if (input[ax * 2 * size + ay]) {
			int px = min(normalize(ax - half + 1, half), 2 * half - 1);
			int py = min(normalize(ay - half + 1, half), 2 * half - 1);
			int po = output1[px * 2 * half + py];
			int pox = normalize(po / (2 * half), half);
			int poy = normalize(po % (2 * half), half);
			int bx = 2 * size - 1, by = 2 * size - 1;
			if (ax < half || ax >= size * 2 - half - 1) bx = min(bx, ax);
			else bx = min(bx, size * 2 - half - 1);
			if (ay < half || ay >= size * 2 - half - 1) by = min(by, ay);
			else by = min(by, size * 2 - half - 1);
			bx = min(bx, pox + half - 1);
			by = min(by, poy + half - 1);
			int qx = min(normalize(bx - 2 * (half - 1), half), 2 * half - 1);
			int qy = min(normalize(by - 2 * (half - 1), half), 2 * half - 1);
			int qo = output2[qx * 2 * half + qy];
			int qox = normalize(qo / (2 * half), half);
			int qoy = normalize(qo % (2 * half), half);

			int rx = min(normalize(bx, half), 2 * half - 1);
			int ry = min(normalize(by, half), 2 * half - 1);
			int ro = output3[rx * 2 * half + ry];
			int rox = normalize(ro / (2 * half), half);
			int roy = normalize(ro % (2 * half), half);
			int cx = min(min(qox + 2 * (half - 1), rox), 2 * size - 1);
			int cy = min(min(qoy + 2 * (half - 1), roy), 2 * size - 1);
			int sx = min(normalize(cx - half + 1, half), 2 * half - 1);
			int sy = min(normalize(cy - half + 1, half), 2 * half - 1);
			input4[sx * 2 * half + sy] += input[ax * 2 * size + ay];
		}
		vector<int> output4 = dnc(si + half - 1, sj + half - 1, ei, ej, input4);
		for (int ax = 0; ax < 2 * size; ax++) for (int ay = ax; ay < 2 * size; ay++) {
			int px = min(normalize(ax - half + 1, half), 2 * half - 1);
			int py = min(normalize(ay - half + 1, half), 2 * half - 1);
			int po = output1[px * 2 * half + py];
			int pox = normalize(po / (2 * half), half);
			int poy = normalize(po % (2 * half), half);
			int bx = 2 * size - 1, by = 2 * size - 1;
			if (ax < half || ax >= size * 2 - half - 1) bx = min(bx, ax);
			else bx = min(bx, size * 2 - half - 1);
			if (ay < half || ay >= size * 2 - half - 1) by = min(by, ay);
			else by = min(by, size * 2 - half - 1);
			bx = min(bx, pox + half - 1);
			by = min(by, poy + half - 1);
			int qx = min(normalize(bx - 2 * (half - 1), half), 2 * half - 1);
			int qy = min(normalize(by - 2 * (half - 1), half), 2 * half - 1);
			int qo = output2[qx * 2 * half + qy];
			int qox = normalize(qo / (2 * half), half);
			int qoy = normalize(qo % (2 * half), half);
			int rx = min(normalize(bx, half), 2 * half - 1);
			int ry = min(normalize(by, half), 2 * half - 1);
			int ro = output3[rx * 2 * half + ry];
			int rox = normalize(ro / (2 * half), half);
			int roy = normalize(ro % (2 * half), half);
			int cx = min(min(qox + 2 * (half - 1), rox), 2 * size - 1);
			int cy = min(min(qoy + 2 * (half - 1), roy), 2 * size - 1);
			int sx = min(normalize(cx - half + 1, half), 2 * half - 1);
			int sy = min(normalize(cy - half + 1, half), 2 * half - 1);
			int so = output4[sx * 2 * half + sy];
			int sox = normalize(so / (2 * half), half);
			int soy = normalize(so % (2 * half), half);

			int dx = 2 * size - 1, dy = 2 * size - 1;
			if (cx < half || cx >= size * 2 - half - 1) dx = min(dx, cx);
			else dx = min(dx, size * 2 - half - 1);
			if (cy < half || cy >= size * 2 - half - 1) dy = min(dy, cy);
			else dy = min(dy, size * 2 - half - 1);
			dx = min(dx, sox + half - 1);
			dy = min(dy, soy + half - 1);
			output[ax * 2 * size + ay] = dx * 2 * size + dy;
		}
}
return output;
}
int main()
{
	scanf("%d %d", &M, &N);
	RM = M;
	M = 2;
	while (M < RM) M = M * 2 - 1;
	for (int i = 1; i < M; i++) for (int j = 1; j < M; j++) {
		if (i < RM && j < RM) {
			char str[30];
			scanf("%s", str);
			grow[i][j][0] = 2;
			grow[i][j][1] = str[17] == 'L' ? 1 : 2;
			grow[i][j][2] = str[14] == 'U' ? 2 : 1;
			grow[i][j][3] = 1;
			grow[i][j][4] = str[8] == 'L' ? 0 : 2;
			grow[i][j][5] = str[5] == 'L' ? 0 : (str[5] == 'D' ? 1 : 2);
			grow[i][j][6] = str[4] == 'L' ? 0 : 1;
			grow[i][j][7] = str[2] == 'U' ? 2 : 0;
			grow[i][j][8] = str[1] == 'U' ? 1 : 0;
			grow[i][j][9] = 0;
			int l = 0;
			while (str[l]) {
				l++;
			}
		}
		else {
			grow[i][j][0] = 2;
			for (int k = 1; k < 4; k++) grow[i][j][k] = 1;
			for (int k = 4; k < 10; k++) grow[i][j][k] = 0;
		}
	}
	vector<int> input(4 * M*M);

	for (int i = 0; i < N; i++) {
		int x, y, z; scanf("%d %d %d", &x, &y, &z); x += M - RM;
		y += x;
		input[x * 2 * M + y]++;
		seed[x]++; seed[y]++;
	}
	int cnt = 0, pos = 0;
	for (int i = M - 1; i >= 0; i--) {
		cnt += seed[pos++];
		bee[i][0] = cnt;
	}
	for (int j = 1; j < M; j++) {
		cnt += seed[pos++];
		bee[0][j] = cnt;
	}
	dnc(0, 0, M - 1, M - 1, input);
	for (int i = 0; i < RM; i++) {
		for (int j = 0; j < RM; j++) {
			if (j) printf(" ");
			printf("%d", bee[i][j] + 1);
		}
		puts("");
	}
	return 0;
}
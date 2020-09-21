#include <bits/stdc++.h>

#define MAX_POINTS 100

typedef struct {

	float x, y, weight;
	int left_flag, right_flag;

}POINT;

typedef struct {

	float rows, cols;

}MATRIX;

POINT points[MAX_POINTS];
MATRIX matrix[MAX_POINTS - 1];

char s_temp[2 * MAX_POINTS];
int final_order[4 * MAX_POINTS];
int s_paren[MAX_POINTS][MAX_POINTS];
float cost[MAX_POINTS][MAX_POINTS];
int point_counter = 0;
int retrieve_counter;
int last_draw_point = 0;
int final_order_counter = 0;static int input_points(void);
static float max_re(float, float);
static void parenth(int, int);

int main() {

	int k_ta, n;
	float q, q_ta;

	n = input_points() - 1;
	for (int i = 0; i < n; i++) cost[i][i] = 0;

	return 0;

}
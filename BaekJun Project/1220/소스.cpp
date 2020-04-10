#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long Cost;

const int kDefaultSpeed = 10;
const Cost kMaxAnswer = 2000000000LL;
const int kMaxN = 1000;
const int kMaxCoord = 100000000;
const int kMaxSpeed = 100000000;

int n;
vector<int> arr_x1, arr_y1, arr_x2, arr_y2, t; //t 가중치

inline int SolveOneDirection(vector<int>& arr_x1, vector<int>& arr_y1, vector<int>& arr_x2, vector<int>& arr_y2, int xa, int ya, int xb, int yb, int nx, int ny, vector<int>& xv, vector<int>& yv) {
  
	vector<Cost> d(ny, kMaxAnswer);

	//만약 시작지점의 x좌표가 크다면, 시작지점과 도착좌표 바꾸기
	if (xa > xb) {

		int t = xa;

		xa = xb;
		xb = t;

		t = ya;

		ya = yb;
		yb = t;

	}

	d[ya] = 0;

	//시작 지점 x부터 도착지점 x까지
	for (int x = xa; x <= xb; ++x) {

		//첫번째 이후
		if (x > xa) {

			vector<int> delta(ny, kDefaultSpeed);

			for (int i = 0; i < n; ++i) {

      			if (arr_x1[i] <= x - 1 && arr_x2[i] >= x) {

					for (int j = arr_y1[i] + 1; j < arr_y2[i]; ++j)
						delta[j] = t[i];

				}

			}

			for (int i = 0; i < ny; ++i)
				d[i] = min(kMaxAnswer, d[i] + (Cost) delta[i] * (xv[x] - xv[x - 1]));

		}

		vector<int> delta(ny - 1, kDefaultSpeed);

		for (int i = 0; i < n; ++i) {

			if (arr_x1[i] < x && arr_x2[i] > x) {

			  for (int j = arr_y1[i]; j < arr_y2[i]; ++j)
				delta[j] = t[i];

			}

		}

		for (int i = 0; i < ny - 1; ++i)
			d[i + 1] = min(d[i + 1], d[i] + (Cost) delta[i] * (yv[i + 1] - yv[i]));

		for (int i = ny - 1; i > 0; --i)
			d[i - 1] = min(d[i - 1], d[i] + (Cost) delta[i - 1] * (yv[i] - yv[i - 1]));

    }

	return (int) d[yb];

}

int main() {

	int xa, ya, xb, yb;

	cin >> xa >> ya >> xb >> yb >> n;
	arr_x1.resize(n), arr_y1.resize(n), arr_x2.resize(n), arr_y2.resize(n), t.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> arr_x1[i] >> arr_y1[i] >> arr_x2[i] >> arr_y2[i] >> t[i];
  
	 set<int> xs, ys;
	 xs.insert(xa), ys.insert(ya);
	 xs.insert(xb), ys.insert(yb);
  
	 for (int i = 0; i < n; ++i) {

		xs.insert(arr_x1[i]), ys.insert(arr_y1[i]);
		ys.insert(arr_y2[i]), xs.insert(arr_x2[i]);

	 }

	 int nx = 0, ny = 0;
	 vector<int> xv, yv;
	 map<int, int> x_to_id, y_to_id;

	for (set<int>::const_iterator it = xs.begin(); it != xs.end(); ++it) {

		x_to_id[*it] = nx++;
		xv.push_back(*it);

	}
	for (set<int>::const_iterator it = ys.begin(); it != ys.end(); ++it) {

		y_to_id[*it] = ny++;
		yv.push_back(*it);

	}

	xa = x_to_id[xa], ya = y_to_id[ya];
	xb = x_to_id[xb], yb = y_to_id[yb];
  
	for (int i = 0; i < n; ++i) {

		arr_x1[i] = x_to_id[arr_x1[i]], arr_y1[i] = y_to_id[arr_y1[i]];
		arr_x2[i] = x_to_id[arr_x2[i]], arr_y2[i] = y_to_id[arr_y2[i]];
    
	}

	int res_by_x = SolveOneDirection(arr_x1, arr_y1, arr_x2, arr_y2, xa, ya, xb, yb, nx, ny, xv, yv);
	int res_by_y = SolveOneDirection(arr_y1, arr_x1, arr_y2, arr_x2, ya, xa, yb, xb, ny, nx, yv, xv);

	int res = min(res_by_x, res_by_y);
	printf("%d\n", res);

	return 0;

}

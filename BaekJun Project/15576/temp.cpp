//#define _USE_MATH_DEFINES
//
//#include <string>
//#include <iostream>
//#include <complex>
//#include <math.h>
//#include <vector>
//
//using namespace std;
//
//typedef complex<double> base;
//
//int max(int a, int b) { return(a > b) ? a : b; }
//
//void fft(vector<base> &a, bool inv) {
//	int n = (int)a.size();
//	for (int i = 1, j = 0; i < n; i++) {
//		int bit = n >> 1;
//		while (!((j ^= bit) & bit)) bit >>= 1;
//		if (i < j) swap(a[i], a[j]);
//	}
//	for (int i = 1; i < n; i <<= 1) {
//		double x = (inv ? 1 : -1) * M_PI / i;
//		base w = { cos(x), sin(x) };
//		for (int j = 0; j < n; j += i << 1) {
//			base th(1);
//			for (int k = 0; k < i; k++) {
//				base tmp = a[i + j + k] * th;
//				a[i + j + k] = a[j + k] - tmp;
//				a[j + k] += tmp;
//				th *= w;
//			}
//		}
//	}
//	if (inv) {
//		for (int i = 0; i < n; i++) a[i] /= n;
//	}
//}
//
//int powerOf2(int a) {
//
//	int result = 1;
//
//	while (a > (result <<= 1)) {}
//
//	return result;
//
//}
//
//vector<int> multiply(vector<int> &A, vector<int> &B) {
//	vector<base> a(A.begin(), A.end());
//	vector<base> b(B.begin(), B.end());
//	int n = powerOf2(max(a.size(), b.size())) * 2;
//
//	a.resize(n);	b.resize(n);
//	fft(a, false);	fft(b, false);
//
//	for (int i = 0; i < n; i++)
//		a[i] *= b[i];
//	fft(a, true);
//
//	vector<int> ret(n);
//	for (int i = 0; i < n; i++)
//		ret[i] = (int)round(a[i].real());
//	return ret;
//}
//
//int main() {
//	ios::sync_with_stdio(false);    cin.tie(NULL);
//
//	std::string input1, input2;
//	std::cin >> input1 >> input2;
//	
//	int Size = powerOf2(max(input1.size(), input2.size())) * 2;
//	
//	std::vector<int> vInput1, vInput2;
//	
//	vInput1.resize(Size); vInput2.resize(Size);
//		
//	int i;
//	
//	i = 0;
//	for (char c : input1)
//		vInput1[i] = (double)(input1[i] - '0'), i++;
//			
//	i = 0;
//	for (char c : input2)
//		vInput2[i] = (double)(input2[i] - '0'), i++;
//
//	vector<int> ret = multiply(vInput1, vInput2);
//
//	i = 0;
//	while (i < ret.size()) {
//		if (ret[i] >= 10) {
//			if (i == ret.size() - 1)
//				ret.push_back(ret[i] / 10);
//			else
//				ret[i + 1] += ret[i] / 10;
//			ret[i] %= 10;
//		}
//		++i;
//	}
//
//	reverse(ret.begin(), ret.end());
//
//	bool start = false;
//	for (auto elem : ret) {
//		if (elem)start = true;
//		if (start)cout << elem;
//	}
//	if (!start)cout << '0';
//
//	return 0;
//}
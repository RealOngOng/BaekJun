#define _USE_MATH_DEFINES

#define MAX 1200001

#include <iostream>
#include <math.h>
#include <complex>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

#include <time.h>

typedef std::complex<double> Complex;

inline int powerOf2(int a) {

	int result = 1;

	while (a > (result <<= 1)) {}

	return result;

}
inline int max(int a, int b) { return (a > b) ? a : b; }

const double Pi2 = 2 * M_PI;

inline Complex E(double x) {

	return { cos(2 * M_PI * x), -sin(2 * M_PI * x) };

}

int num[MAX];

void FFT(Complex* a, int n, bool inv) {

	int half = n * 0.5;

	int d = 1;
	for (int bit = (n >> 1); bit; bit >>= 1) {

		for (int i = 0; i < n; i++)
			if ((i / d) & 1) num[i] |= bit;

		d <<= 1;

	}

	Complex *v = new Complex[n],
			*w = new Complex[n];
	
	for (int i = 0; i < n; i++)
		v[i] = a[num[i]];

	int inverse = (inv) ? -1 : 1;

	int count = 0;

	for (int lv = 2; lv <= n; lv <<= 1) {

		for (int i = 0; i < n; i += lv) {

			for (int j = 0; j < lv / 2; j++) {

				Complex ce = v[i + j],
					co = v[i + j + lv / 2] * E((double)j / lv * inverse);

				w[i + j] = ce + co;
				w[i + j + lv / 2] = ce - co;

				count++;

			}

		}

		for (int i= 0; i < n; i++) v[i] = w[i];

	}

	if (inv)
		for (int i = 0; i < n; i++) a[i] = w[i] / (double)n;
	else
		for (int i = 0; i < n; i++) a[i] = w[i];

}

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::string input1, input2;

	std::cin >> input1 >> input2;

	if (input1 == "0" || input2 == "0") {

		std::cout << "0\n";
		return 0;

	}

	int Size = powerOf2(max(input1.size(), input2.size())) * 2;

	Complex *vInput1 = new Complex[MAX],
		    *vInput2 = new Complex[MAX];

	int len;
				
	len = input1.size();

	for (int i = 0; i < len; i++)
		vInput1[i] = { (double)(input1[i] - '0') , 0 };

	len = input2.size();

	for (int i = 0; i < len; i++)
		vInput2[i] = { (double)(input2[i] - '0') , 0 };

	std::reverse(vInput1, vInput1 + Size);
	std::reverse(vInput2, vInput2 + Size);

	FFT(vInput1, Size, false);
	FFT(vInput2, Size, false);

	for (int i = 0; i < Size; i++)
		vInput1[i] *= vInput2[i];

	FFT(vInput1, Size, true);

	int *ret = new int[Size];

	for (int i = 0; i < Size; i++)
		ret[i] = (int)std::round(vInput1[i].real());

	int length = 0;

	int i = 0;
	while (i < Size) {
		if (ret[i] >= 10) {
			if (i == Size - 1)
				ret[i] = ret[i] / 10;
			else
				ret[i + 1] += ret[i] / 10;
			ret[i] %= 10;
		}
		++i;
	}

	std::reverse(ret, ret + Size);

	std::string result = "";

	int start = 0;

	for (start = 0; start < Size; start++)
		if (ret[start] != 0) break;

	for (int i = start; i < Size; i++)
		result += std::to_string(ret[i]);

	std::cout << result << "\n";

	return 0;

}
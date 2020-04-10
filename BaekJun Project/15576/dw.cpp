//#define _USE_MATH_DEFINES
//
//#define MAX 1200001
//
//#include <iostream>
//#include <math.h>
//#include <complex>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <map>
//
//#include <time.h>
//
//typedef std::complex<double> Complex;
//
//inline int powerOf2(int a) {
//
//	int result = 1;
//
//	while (a > (result <<= 1)) {}
//
//	return result;
//
//}
//inline int max(int a, int b) { return (a > b) ? a : b; }
//
//inline void swap(Complex *a, Complex *b) {
//
//	Complex temp = *a;
//	*a = *b;
//	*b = temp;
//
//}
//
//const double Pi2 = 2 * M_PI;
//
//inline Complex E(double x) {
//
//	return { cos(2 * M_PI * x), -sin(2 * M_PI * x) };
//
//}
//
//int num[MAX];
//
//clock_t fft_start, fft_end;
//
//void _FFT1d(double* g, unsigned long N, int isign)
//{
//	int mmax, m, istep;
//	double wtemp, wr, wpr, wpi, wi, theta;
//	double tempr, tempi;
//	double temp;
//
//	// 스크램블 수행
//	int n = N;
//	int j = 1;
//	for (int i = 1; i < n; i += 2)
//	{
//		if (j > i)
//		{
//			temp = g[j];
//			g[j] = g[i];
//			g[i] = temp;
//
//			temp = g[j + 1];
//			g[j + 1] = g[i + 1];
//			g[i + 1] = temp;
//		}
//		m = n >> 1;
//		while (j > m && m >= 2)
//		{
//			j -= m;
//			m >>= 1;
//		}
//		j += m;
//	}
//
//	// 버터플라이 알고리즘 수행
//	mmax = 2; // 2원소 DFT로 시작
//	while (n > mmax)
//	{
//		istep = mmax << 1;
//		theta = isign * (6.28318530717959 / mmax);
//		wtemp = sin(0.5*theta);
//		wpr = -2.0*wtemp*wtemp;
//		wpi = sin(theta);
//		wr = 1.0;
//		wi = 0.0;
//		for (m = 1; m < mmax; m += 2)
//		{
//			for (int i = m; i <= n; i += istep)
//			{
//				j = i + mmax;
//				tempr = double(wr*g[j] - wi * g[j + 1]);
//				tempi = double(wr*g[j + 1] + wi * g[j]);
//				g[j] = g[i] - tempr;
//				g[j + 1] = g[i + 1] - tempi;
//				g[i] += tempr;
//				g[i + 1] += tempi;
//			}
//			wr = (wtemp = wr)*wpr - wi * wpi + wr;
//			wi = wi * wpr + wtemp * wpi + wi;
//		}
//		mmax = istep;
//	}
//
//	if (isign == -1)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			g[i] /= N;
//		}
//	}
//}
//
//int main() {
//
//	clock_t start1, end1;
//
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(NULL); std::cout.tie(NULL);
//
//	std::string input1, input2;
//
//	//for (int i = 0; i < 300000; i++)
//	//	input1 += '1', input2 += '1';
//
//	std::cin >> input1 >> input2;
//
//	if (input1 == "0" || input2 == "0") {
//
//		std::cout << "0\n";
//		return 0;
//
//	}
//
//	int Size = powerOf2(max(input1.size(), input2.size())) * 2;
//
//	double *vInput1 = new double[MAX],
//		*vInput2 = new double[MAX];
//
//	int len;
//
//	len = input1.size();
//
//	for (int i = 0; i < len; i++)
//		vInput1[i] = (double)(input1[i] - '0');
//
//	len = input2.size();
//
//	for (int i = 0; i < len; i++)
//		vInput2[i] = (double)(input2[i] - '0');
//
//	std::reverse(vInput1, vInput1 + Size);
//	std::reverse(vInput2, vInput2 + Size);
//
//	start1 = clock();
//
//	_FFT1d(vInput1, Size, false);
//
//	for (int i = 0; i < Size; i++)
//		std::cout << vInput1[i] << "\n";
//
//	_FFT1d(vInput2, Size, false);
//
//	end1 = clock();
//
//	std::cout << "time4 : " << ((double)(end1 - start1) / CLOCKS_PER_SEC) << "\n";
//
//	for (int i = 0; i < Size; i++)
//		vInput1[i] *= vInput2[i];
//
//	_FFT1d(vInput1, Size, true);
//
//	start1 = clock();
//
//	int *ret = new int[Size];
//
//	for (int i = 0; i < Size; i++)
//		ret[i] = (int)std::round(vInput1[i]);
//
//	int length = 0;
//
//	int i = 0;
//	while (i < Size) {
//		if (ret[i] >= 10) {
//			if (i == Size - 1)
//				ret[i] = ret[i] / 10;
//			else
//				ret[i + 1] += ret[i] / 10;
//			ret[i] %= 10;
//		}
//		++i;
//	}
//
//	std::reverse(ret, ret + Size);
//
//	std::string result = "";
//
//	int start = 0;
//
//	for (start = 0; start < Size; start++)
//		if (ret[start] != 0) break;
//
//	for (int i = start; i < Size; i++)
//		result += std::to_string(ret[i]);
//
//	std::cout << result << "\n";
//
//	end1 = clock();
//
//	std::cout << "time5 : " << ((double)(end1 - start1) / CLOCKS_PER_SEC) << "\n";
//
//	return 0;
//
//}
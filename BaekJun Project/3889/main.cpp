#include <iostream>
#include <math.h>

#define MAX 101

typedef struct Vector3 {

	double x, y, z;

	Vector3 operator+(const Vector3& vec) { return { x + vec.x, y + vec.y, z + vec.z }; }
	Vector3 operator-(const Vector3& vec) { return { x - vec.x, y - vec.y, z - vec.z }; }
	Vector3 operator*(double d) { return { x * d, y * d, z * d }; }
	Vector3 operator/(double d) { return { x / d, y / d, z / d }; }

	Vector3 normalize() {

		double sum = std::sqrt(x * x + y * y + z * z);

		return { x / sum, y / sum, z / sum };

	}

	void debug() {

		std::cout << "(" << x << ", " << y << ", " << z << ")" << "\n";

	}

};

typedef struct Sphere {

	Vector3 pos;
	double radius;

};

double distance(Vector3 vec1, Vector3 vec2) {

	double dst = std::sqrt(
		std::pow(vec1.x - vec2.x, 2) + std::pow(vec1.y - vec2.y, 2) + std::pow(vec1.z - vec2.z, 2));

	return std::round(dst * 1000) / 1000;

}

Vector3 raser;
Sphere sphere[MAX];

int main() {

	int n; std::cin >> n;

	std::cin >> raser.x >> raser.y >> raser.z;
	raser = raser.normalize();

	for (int i = 0; i < n; i++) {

		double x, y, z, r; std::cin >> x >> y >> z >> r;
		sphere[i] = { {x, y, z}, r };

	}

	raser.debug();

	double result = 0;
	double low = 0, high = 100;

	while (true) {

		double mid = (low + high) * 0.5;

		double dst = distance(sphere[2].pos, raser * mid);

		if (dst == 5) break;

		std::cout << dst << "\n";
		(raser * mid).debug();

		if (dst >= sphere[2].radius) {

			result = mid;
			high = mid;

		}
		else
			low = mid;

	}

	std::cout << result << "\n";

	return 0;

}
#include <iostream>
#include <math.h>

typedef struct Vector3 {

	double x, y, z;

	Vector3 operator+(const Vector3& vec) { return { x + vec.x, y + vec.y, z + vec.z }; }
	Vector3 operator-(const Vector3& vec) { return { x + vec.x, y + vec.y, z + vec.z }; }
	Vector3 operator*(double ratio) { return { x * ratio, y * ratio, z * ratio }; }

};

typedef struct Sphere {

	Vector3 pos;
	double r;

};

typedef struct Equation {

	double a, b, c;

};

typedef struct Solution {

	double s1, s2;

};

bool isDiscriminant(double a, double b, double c) {

	return ((b * b) - 4 * a * c >= 0);

}

Equation getEquation(Vector3 pos, Vector3 dir, Sphere sph) {

	Equation e;

	e.a = dir.x + dir.y + dir.z;
	e.b = 2 * (dir.x * (pos.x - sph.pos.x) + dir.y * (pos.y - sph.pos.y) + dir.z * (pos.z - sph.pos.z));
	e.c = pos.x * pos.x + pos.y * pos.y + pos.z * pos.z
		+ sph.pos.x * sph.pos.x + sph.pos.y * sph.pos.y + sph.pos.z * sph.pos.z
		- 2 * pos.x * sph.pos.x - 2 * pos.y * sph.pos.y - 2 * pos.z * sph.pos.z
		- sph.r * sph.r;

	return e;

}

double dot(Vector3 vec1, Vector3 vec2) {

	return (vec1.x * vec2.x) + (vec1.y * vec2.y);

}

Vector3 Reflact(Vector3 dir, Vector3 normal) {

	return dir +  normal * 2 * dot(dir * -1, normal);

}

Vector3 Normalize(Vector3 vec) {

	double temp = std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);

	return { vec.x / temp, vec.y / temp, vec.z / temp };

}

Solution rootFomula(Equation e) {

	double root = std::sqrt(e.b * e.b - 4 * e.a * e.c);

	return { (-e.b + root) / (2 * e.a), (-e.b - root) / (2 * e.a) };

}

int main() {

	//int t; std::cin >> t;

	//while (t--) {

	//	int n; std::cin >> n;

	//	Vector3 dir, pos = {0, 0, 0}; std::cin >> dir.x >> dir.y >> dir.z;

	//	Sphere *sph = new Sphere[n];

	//	for (int i = 0; i < n; i++) 
	//		std::cin >> sph[i].pos.x >> sph[i].pos.y >> sph[i].pos.z >> sph[i].r;

	//	while (true) {

	//	}

	//}

	Vector3 pos = { 3, 0, 0 }, dir = { 2, 1, 0 };
	Sphere sph = { {1, 1, 0}, 3 };

	//dir = Normalize(dir);

	Equation e = getEquation(pos, dir, sph);

	Solution s = rootFomula(e);

	std::cout << s.s1 << ", " << s.s2 << "\n";

	Vector3 hit[2] = 
	{ {pos.x + dir.x * s.s1, pos.y + dir.y * s.s1, pos.z + dir.z * s.s1}, 
	{pos.x + dir.x * s.s2, pos.y + dir.y * s.s2, pos.z + dir.z * s.s2} };
	
	std::cout << hit[0].x << ", " << hit[0].y << ", " << hit[0].z << "\n";
	std::cout << hit[1].x << ", " << hit[1].y << ", " << hit[1].z << "\n";

	Vector3 normal[2] = 
	{ Normalize(hit[0] - sph.pos) , Normalize(hit[1] - sph.pos) };

	std::cout << normal[0].x << ", " << normal[0].y << ", " << normal[0].z << "\n";
	std::cout << normal[1].x << ", " << normal[1].y << ", " << normal[1].z << "\n";
	std::cout << dir.x << ", " << dir.y << ", " << dir.z << "\n";

	return 0;

}


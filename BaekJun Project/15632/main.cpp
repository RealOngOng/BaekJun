#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
#include <vector>

#define MAX 3

typedef struct Vector2 {

	double x, y;

	void debug() {

		std::cout << "(" << x << ", " << y << ")";

	}

};

double distance(Vector2 vec1, Vector2 vec2) {

	return std::sqrt(std::pow(vec1.x - vec2.x, 2) + std::pow(vec1.y - vec2.y, 2));

}

typedef struct Sphere {

	Vector2 pos;
	double r;

	bool isCollision(Sphere s) {

		double len = r + s.r;

		double dst = distance(pos, s.pos);

		return ((len > dst) && (dst > std::abs(r - s.r)));

	}

};

Sphere sph[MAX];

double getRoundD(Sphere s1, Sphere s2) {

	double dst = distance(s1.pos, s2.pos);

	return 0.25 * std::sqrt(
	(dst + s1.r + s2.r) * (dst + s1.r - s2.r) * 
	(dst - s1.r + s2.r) * (-dst + s1.r + s2.r));

}

Vector2* getCross(Sphere s1, Sphere s2) {

	Vector2 *result = new Vector2[2];

	double D = distance(s1.pos, s2.pos);

	double rd = getRoundD(s1, s2);

	double rsub = std::pow(s1.r, 2) - std::pow(s2.r, 2);
	double d = D * D;

	double x1 = (s1.pos.x + s2.pos.x) * 0.5 + ((s2.pos.x - s1.pos.x) * rsub) / (2 * d);
	double x2 = 2 * ((s1.pos.y - s2.pos.y) / d) * rd;

	double y1 = (s1.pos.y + s2.pos.y) * 0.5 + ((s2.pos.y - s1.pos.y) * rsub) / (2 * d);
	double y2 = 2 * ((s1.pos.x - s2.pos.x) / d) * rd;

	result[0].x = x1 + x2, result[0].y = y1 - y2;
	result[1].x = x1 - x2, result[1].y = y1 + y2;

	return result;

}

double triangle(Vector2 vec1, Vector2 vec2, Vector2 vec3) {

	return 0.5 * std::abs(
		vec1.x * (vec2.y - vec3.y) + 
		vec2.x * (vec3.y - vec1.y) + 
		vec3.x * (vec1.y - vec2.y));

}

int main() {

	int n = 3;

	double sum = 0;

	for (int i = 0; i < n; i++) {

		double x, y, r; std::cin >> x >> y >> r;
		sph[i] = { x, y, r };

		sum += r * r * M_PI;

	}

	std::vector<Vector2> inc;

	for (int i = 0; i < n; i++) {

		int n1 = (i + 1) % 3, n2 = (i + 2) % 3;

		Vector2 *cross = getCross(sph[n1], sph[n2]);

		for (int j = 0; j < 2; j++) {

			double dst = distance(sph[i].pos, cross[j]);

			if (dst <= sph[i].r) inc.push_back(cross[j]);

		}	

	}

	double rapping = 0;

	if (false) {

		for (int i = 0; i < n; i++) {

			int n1 = (i + 1) % 3, n2 = (i + 2) % 3;

			double dst = distance(inc[n1], inc[n2]);

			double var = std::pow(sph[i].r, 2) * std::asin(dst / (sph[i].r * 2)) -
				(dst * 0.25) * std::sqrt(4 * sph[i].r * sph[i].r - dst * dst);

			if (sph[i].pos.x > 0) var = sph[i].r * sph[i].r * M_PI - var;

			rapping += var;

		}

		rapping += triangle(inc[0], inc[1], inc[2]);

	}
	else {

		Vector2 crs[3][2];

		for (int i = 0; i < n; i++) {

			int n1 = (i + 1) % 3;

			Vector2 *cross = getCross(sph[i], sph[n1]);

			for (int j = 0; j < 2; j++) crs[i][j] = cross[j];

		}

		for (int i = 0; i < n; i++) {

			int n1 = (i + 1) % 3;

			if (std::isnan(crs[i][0].x)) continue;

			double d = distance(crs[i][0], crs[i][1]);

			double t, buch, sum, s;

			t = std::acos((d * d) / (sph[i].r * sph[i].r * -2) + 1) * (180 / M_PI);

			buch = (sph[i].r * sph[i].r * M_PI) * (t / 360);

			sum = (sph[i].r + sph[i].r + d) * 0.5;

			rapping += buch - std::sqrt(sum * (sum - sph[i].r) * (sum - sph[i].r) * (sum - d));

			t = std::acos((d * d) / (sph[n1].r * sph[n1].r * -2) + 1) * (180 / M_PI);

			buch = (sph[n1].r * sph[n1].r * M_PI) * (t / 360);

			sum = (sph[n1].r + sph[n1].r + d) * 0.5;

			rapping += buch - std::sqrt(sum * (sum - sph[i].r) * (sum - sph[i].r) * (sum - d));

		}

	}

	std::cout << (sum - rapping) << "\n";

	return 0;
	
}
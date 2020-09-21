import sys
import math

c2 = 299792458.0 * 299792458.0

result = ""

while (1) :

	t1, t2 = map(float, input().split())

	if (t1 == 0 and t2 == 0) : break

		r2 = t2 / t1
		r2 *= r2

		v = c2 * (1 - r2)

		result += '%.3lf\n' % (math.sqrt(v) / 299792458.0)

		print(result)


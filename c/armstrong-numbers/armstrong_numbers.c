#include "armstrong_numbers.h"

#include <stdio.h>

static int powi(int a, int b) {
	int res = a;
	while( b > 1 ) {
		res *= a;
		b--;
	}

	return res;
}

bool is_armstrong_number(const int candidate) {
	int res = 0, nb = 1;

	int tmp = candidate;
	while( tmp > 10 ) {
		tmp /= 10;
		nb++;
	}

	tmp = candidate;
	while( tmp > 0 ) {
		res += powi(tmp % 10, nb);
		tmp /= 10;
	}

	return res == candidate ? true : false;
}
